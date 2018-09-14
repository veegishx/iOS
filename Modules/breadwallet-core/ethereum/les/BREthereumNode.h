#ifndef BR_Ethereum_Node_h
#define BR_Ethereum_Node_h

#include <stddef.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include "BRInt.h"
#include "BREthereumBase.h"

// Note:: Duplicated this logging code from Aaron's BRPeer.h file
// TODO: May want to move this code into it's own library
#define bre_peer_log(peer, ...) _bre_peer_log("%s:%"PRIu16" " _va_first(__VA_ARGS__, NULL) "\n", ethereumPeerGetHost(peer),\
(peer)->port, _va_rest(__VA_ARGS__, NULL))
#define _va_first(first, ...) first
#define _va_rest(first, ...) __VA_ARGS__

#if defined(TARGET_OS_MAC)
#include <Foundation/Foundation.h>
#define _bre_peer_log(...) NSLog(__VA_ARGS__)
#elif defined(__ANDROID__)
#include <android/log.h>
#define _bre_peer_log(...) __android_log_print(ANDROID_LOG_INFO, "sunwallet", __VA_ARGS__)
#else
#include <stdio.h>
#define _bre_peer_log(...) printf(__VA_ARGS__)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * An Ethereum LES Node
 *
 */
typedef struct BREthereumNodeContext *BREthereumNode;

/**
 * Ehtereum Node Connection Status - Connection states for a node
 */
typedef enum {
    BRE_NODE_ERROR = -1, 
    BRE_NODE_DISCONNECTED,
    BRE_NODE_CONNECTING,
    BRE_NODE_PERFORMING_HANDSHAKE,
    BRE_NODE_CONNECTED
} BREthereumNodeStatus;

/**
 * BREthereumPeer - holds information about the remote peer
 */
typedef struct {

    //ipv6 address of the peer
    UInt128 address;
    
    //port number of peer connection
    uint16_t port;
    
    //The name for a host
    char host[INET6_ADDRSTRLEN];
    
    //socket used for communicating with a peer
    volatile int socket;
    
    //The public address for the remote node
    UInt512 remoteId;
    
}BREthereumPeer;

/**
 * Creates an ethereum node with the remote peer information and whether the node should send
 * an auth message first. 
 */ 
extern BREthereumNode  ethereumNodeCreate(BREthereumPeer peer, BREthereumBoolean originate);

/**
 * Retrieves the status of an ethereum node
 */
extern BREthereumNodeStatus ethereumNodeStatus(BREthereumNode node);

/**
 * Connects to the ethereum node to a remote node
 */
extern void ethereumNodeConnect(BREthereumNode node);

/**
 * Disconnects the ethereum node from a remote node
 */
extern void ethereumNodeDisconnect(BREthereumNode node);

/**
 * Deletes the memory of the ethereum node
 */
extern void ethereumNodeFree(BREthereumNode node);

/**
 * Retrieves the string representation of the remot peer address
 */ 
extern const char * ethereumPeerGetHost(BREthereumPeer* peer);


#ifdef __cplusplus
}
#endif

#endif // BR_Ethereum_Node_h
