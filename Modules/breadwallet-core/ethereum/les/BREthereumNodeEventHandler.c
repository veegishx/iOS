#include <stdlib.h>
#include <pthread.h>
#include "BRArray.h"
#include "BREthereumNodeEventHandler.h"

#define DEFAULT_EVENT_QUEUE_CAPACITY 10

typedef struct {

    //The array that contains all
    BREthereumNodeEvent* queue;

    //The index of the head of the event queue
    uint32_t head;
    
    uint32_t size;
    
    uint32_t capacity;
    
   // A lock for the event handler context
   pthread_mutex_t lock;

}BREthereumNodeEventHandlerContext;

//
// Public functions
//
BREthereumNodeEventHandler ethereumNodeEventHandlerCreate(void) {

    BREthereumNodeEventHandlerContext* ctx = (BREthereumNodeEventHandlerContext *)calloc(1, sizeof(BREthereumNodeEventHandlerContext));
    ctx->queue = (BREthereumNodeEvent*)malloc(DEFAULT_EVENT_QUEUE_CAPACITY * sizeof(BREthereumNodeEvent));
    ctx->head = 0;
    ctx->size = 0;
    ctx->capacity = DEFAULT_EVENT_QUEUE_CAPACITY;
    pthread_mutex_init(&ctx->lock, NULL);
    
    return (BREthereumNodeEventHandler) ctx;
}
void ethereumNodeEventHandlerRelease(BREthereumNodeEventHandler handler) {

    BREthereumNodeEventHandlerContext* ctx = (BREthereumNodeEventHandlerContext *)handler;
    free(ctx->queue);
    free(ctx);
}
void ethereumNodeEventHandlerEnqueue(BREthereumNodeEventHandler handler, BREthereumNodeEvent event) {

    BREthereumNodeEventHandlerContext* ctx = (BREthereumNodeEventHandlerContext *)handler;
    pthread_mutex_lock(&ctx->lock);
    uint32_t tail = ctx->head + ctx->size;
    if(tail + 1 > ctx->capacity) {
        ctx->capacity = (ctx->capacity + 1)*3/2;
        ctx->queue = realloc(ctx->queue, ctx->capacity);
        for(int i= 0, idx = ctx->head; i < ctx->size; ++i, ++idx){
            ctx->queue[i] = ctx->queue[idx];
        }
        ctx->head = 0;
        tail = ctx->size;
    }
    ctx->queue[tail] = event;
    ctx->size++;
    pthread_mutex_unlock(&ctx->lock);
}
void ethereumNodeEventHandlerDequeue(BREthereumNodeEventHandler handler, BREthereumNodeEvent* output) {

    BREthereumNodeEventHandlerContext* ctx = (BREthereumNodeEventHandlerContext *)handler;
    pthread_mutex_lock(&ctx->lock);
    if(ctx->size != 0){
        memcpy(output, &ctx->queue[ctx->head], sizeof(BREthereumNodeEvent));
        ctx->head++;
        ctx->size--;
        if(ctx->size == 0){
            ctx->head = 0;
        }
    }
    pthread_mutex_unlock(&ctx->lock);
}

BREthereumBoolean ethereumNodeEventHandlerHasEvent(BREthereumNodeEventHandler handler, BREthereumNodeEventType type) {

    BREthereumNodeEventHandlerContext* ctx = (BREthereumNodeEventHandlerContext *)handler;
    BREthereumBoolean result = ETHEREUM_BOOLEAN_FALSE;
    pthread_mutex_lock(&ctx->lock);
    uint32_t tail = ctx->head + ctx->size;
    for(uint32_t idx = ctx->head; idx < tail; ++idx){
        if(type == ctx->queue[idx].type){
            result = ETHEREUM_BOOLEAN_TRUE;
            break;
        }
    }
    pthread_mutex_unlock(&ctx->lock);
    return result;
}

/**
 * Determines the number of events inside the event queue
 * @param handler - the event handler
 * @return the number of events in the queue
 */
extern size_t ethereumNodeEventHandlerSize(BREthereumNodeEventHandler handler) {

    BREthereumNodeEventHandlerContext* ctx = (BREthereumNodeEventHandlerContext *)handler;
    return (size_t)ctx->size;
}
