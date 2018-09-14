#ifndef BR_Ethereum_LES_h
#define BR_Ethereum_LES_h

#include <inttypes.h>
#include "BREthereumBase.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Status Header information for the LES handshake
 */
typedef struct {
    
    uint64_t protocolVersion;
    uint64_t chainId;
    uint64_t headerTd;
    uint8_t headHash[32];
    uint64_t headNum;
    uint8_t genesisHash[32];
    // Note: The below fields are optional LPV1
    BREthereumBoolean* serveHeaders;
    uint64_t* serveChainSince;
    uint64_t* serveStateSince;
    BREthereumBoolean* txRelay;
    uint64_t*flowControlBL;
    uint64_t*flowControlMRC;
    uint64_t*flowControlMRR;
}BREthereumLESHeader;


#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_LES_h */
