#ifndef BR_Event_Queue_H
#define BR_Event_Queue_H

#include "BREvent.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREventQueueRecord *BREventQueue;

/**
 * Create an Event Queue with `size` as the maximum event size and with the
 * optional `lock`.
 */
extern BREventQueue
eventQueueCreate (size_t size, pthread_mutex_t *lock);

extern void
eventQueueDestroy (BREventQueue queue);

extern void
eventQueueEnqueue (BREventQueue queue,
                   const BREvent *event);

extern BREventStatus
eventQueueDequeue (BREventQueue queue,
                   BREvent *event);

extern int
eventQueueHasPending (BREventQueue queue);

#ifdef __cplusplus
}
#endif

#endif /* BR_Event_Queue_H */
