#include <string.h>
#include <pthread.h>
#include "BREventQueue.h"

#define EVENT_QUEUE_DEFAULT_INITIAL_CAPACITY   (1)

struct BREventQueueRecord {
    // A linked-list (through event->next) of pending events.
    BREvent *pending;

    // A linked-list (through event->next) of available events
    BREvent *available;

    // A lock for exclusive access when queueing/dequeueing events.
    pthread_mutex_t lock;

    // Boolean to identify we this queue owns (created) the lock.
    int lockOwner;

    // The size of each event
    size_t size;
};

extern BREventQueue
eventQueueCreate (size_t size, pthread_mutex_t *lock) {
    BREventQueue queue = calloc (1, sizeof (struct BREventQueueRecord));

    queue->pending = NULL;
    queue->available = NULL;
    queue->size = size;

    for (int i = 0; i < EVENT_QUEUE_DEFAULT_INITIAL_CAPACITY; i++) {
        BREvent *event = calloc (1, queue->size);
        event->next = queue->available;
        queue->available = event;
    }

    queue->lock = *lock;
    queue->lockOwner = 0;

    // If a lock was not provided, create the PTHREAD LOCK, as a normal, non-recursive, lock.
    if (NULL == lock) {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
        pthread_mutex_init(&queue->lock, &attr);
        pthread_mutexattr_destroy(&attr);

        queue->lockOwner = 1;
    }

    return queue;
}

extern void
eventQueueDestroy (BREventQueue queue) {
    pthread_mutex_lock(&queue->lock);

    // Move pending to available
    if (NULL != queue->pending) {
        BREvent *next, *this = queue->pending;
        while (NULL != this->next) {
            next = this->next;
            this->next = queue->available;
            queue->available = this;
            this = next;
        }
        queue->pending = NULL;
    }

    // Free available
    if (NULL != queue->available) {
        BREvent *next, *this = queue->available;
        while (NULL != this->next) {
            next = this->next;
            free (this);
            this = next;
        }
        queue->available = NULL;
    }

    pthread_mutex_unlock(&queue->lock);

    if (queue->lockOwner)
        pthread_mutex_destroy(&queue->lock);

    memset (queue, 0, sizeof (struct BREventQueueRecord));
}

extern void
eventQueueEnqueue (BREventQueue queue,
                   const BREvent *event) {
    pthread_mutex_lock(&queue->lock);

    // Get the next available event
    BREvent *this = queue->available;
    if (NULL == this) {
        this = (BREvent*) calloc (1, queue->size);
        this->next = NULL;
    }
    // Make the next event no longer available.
    queue->available = this->next;

    // Fill in `this` with event
    memcpy (this, event, queue->size);
    this->next = NULL;

    // Add to the end of pending
    if (NULL == queue->pending)
        queue->pending = this;
    else {
        // Find the last event
        BREvent *last = queue->pending;
        while (NULL != last->next) last = last->next;
        last->next = this;
    }

    pthread_mutex_unlock(&queue->lock);
}

extern BREventStatus
eventQueueDequeue (BREventQueue queue,
                   BREvent *event) {
    BREventStatus status = EVENT_STATUS_SUCCESS;
    
    if (NULL == event)
        return EVENT_STATUS_NULL_EVENT;
    
    pthread_mutex_lock(&queue->lock);
    
    // Get the next pending event
    BREvent *this = queue->pending;
    
    // there is none, just return
    if (NULL == this)
        status = EVENT_STATUS_NONE_PENDING;
    
    // otherwise process it.
    else {
        // Remove `this` from the pending list.
        queue->pending = this->next;
        
        // Fill in the provided event;
        this->next = NULL;
        memcpy (event, this, queue->size);
        
        // Return `this` to the available list.
        this->next = queue->available;
        queue->available = this;
    }
    pthread_mutex_unlock(&queue->lock);
    
    return status;
}

extern int
eventQueueHasPending (BREventQueue queue) {
    int pending = 0;
    pthread_mutex_lock(&queue->lock);
    pending = NULL != queue->pending;
    pthread_mutex_unlock(&queue->lock);
    return pending;
}
