#ifndef BR_Ethereum_Node_Event_Handler_h
#define BR_Ethereum_Node_Event_Handler_h

#include <inttypes.h>
#include "BREthereumNode.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREthereumNodeEventHandlerContext* BREthereumNodeEventHandler;

//
// The type of events that can be enqueued
//
typedef enum {
    BRE_NODE_EVENT_DISCONNECT = 0,
    BRE_NODE_EVENT_FREE,
    BRE_NODE_EVENT_SUBMIT_TRANSACTION
}BREthereumNodeEventType;

typedef struct {
    BREthereumNodeEventType type;
    union {
        //Submit transaction data
        struct {
            uint8_t* transaction;
            size_t size;
        }submit_transaction;
    } u;
} BREthereumNodeEvent;

//
// Ethereum Node Event Handler management functions
//
/**
 * Creates a new event handler
 * @post: Must be released by a calling ethereumNodeManagerRelease(manager)
*/
extern BREthereumNodeEventHandler ethereumNodeEventHandlerCreate(void);

/**
 * Frees the memory assoicated with the given event handler.
 * @param handler - the even handler to release
 */
extern void ethereumNodeEventHandlerRelease(BREthereumNodeEventHandler handler);

/**
 * Enqueues an event into the event handler queue
 * @param handler - the event handler to release
 * @param event - the event to enqueue
 */
extern void ethereumNodeEventHandlerEnqueue(BREthereumNodeEventHandler handler, BREthereumNodeEvent event);
 
 /**
  * Dequeues an event from the even handler queue
  * @param handler - the event handler to release
  * @return the event removed from the queue
  */
extern void ethereumNodeEventHandlerDequeue(BREthereumNodeEventHandler handler, BREthereumNodeEvent* event);

/**
 * Determines whether an event is in the even queue
 * @param handler - the event handler to release
 * @param type - the event to check for inside the queue
 * @return ETHEREUM_BOOLEAN_TRUE, if the event is inside the queue. Otherwise, ETHEREUM_BOOLEAN_FALSE.
 */
extern BREthereumBoolean ethereumNodeEventHandlerHasEvent(BREthereumNodeEventHandler handler, BREthereumNodeEventType type);
 
/**
 * Determines the number of events inside the event queue 
 * @param handler - the event handler
 * @return the number of events in the queue
 */
extern size_t ethereumNodeEventHandlerSize(BREthereumNodeEventHandler handler);

#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Node_Event_Handler_h */
