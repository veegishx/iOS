#ifndef BR_Ethereum_Handshake_h
#define BR_Ethereum_Handshake_h

#include <inttypes.h>
#include "BRInt.h"
#include "BREthereumNode.h"
#include "BRKey.h"
#include "BREthereumBase.h"
#include "BREthereumLES.h"
#include "BREthereumFrameCoder.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The current state of the handshake
 */
typedef enum {
    BRE_HANDSHAKE_ERROR = -1,
    BRE_HANDSHAKE_NEW,
    BRE_HANDSHAKE_ACKAUTH,
    BRE_HANDSHAKE_WRITESTATUS,
    BRE_HANDSHAKE_READSTATUS,
    BRE_HANDSHAKE_FINISHED
}BREthereumHandshakeStatus;

/**
 * The context for the ethereum handhsake
 *
 */
typedef struct BREthereumHandshakeContext* BREthereumHandShake;

/**
 * Creates an etheruem handshake context
 *
 * @param peer - network information about the remote node
 */
extern BREthereumHandShake ethereumHandshakeCreate(BREthereumPeer * peer,
                                                   BRKey* nodeKey,
                                                   BREthereumBoolean didOriginate,
                                                   uint8_t* statusMessage,
                                                   size_t statusMessageLen,
                                                   BREthereumFrameCoder code);

/**
 * Checks whether the state of the handhsake needs to be updated based on recieving/sending messages
 * to/from the remote peer
 *
 * @returns - the current state of the handshake after performing an update
 */
extern BREthereumHandshakeStatus ethereumHandshakeTransition(BREthereumHandShake handshake);


/**
 * Deletes the memory of a handshake context
 *
 * @param handshakeCxt - the hande shake context information to delete
 */
extern void ethereumHandshakeFree(BREthereumHandShake handshake);

#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Handshake_h */

