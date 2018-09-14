/**
 *
 * Etheruem LES specific data structures & algorithms needed for the p2p network.
 *
 */
#ifndef BR_Ethereum_LES_Base_h
#define BR_Ethereum_LES_Base_h

#include <inttypes.h>
#include "BRKey.h"
#include "BRInt.h"
#include "BREthereumBase.h"

#ifdef __cplusplus
extern "C" {
#endif

extern BREthereumBoolean ethereumGenRandomPriKey(BRKey ** key);

extern UInt256 ethereumGetNonce(void); 

extern BREthereumBoolean etheruemECDHAgree(BRKey* key, UInt512* pubKey, UInt256* outSecret);

extern BREthereumBoolean ethereumEncryptECIES(UInt512* pubKey, uint8_t * plain, uint8_t * cipher, size_t len);

extern BREthereumBoolean ethereumDecryptECIES(UInt256* priKey, uint8_t * plain, uint8_t * cipher, size_t len);

extern void ethereumXORBytes(uint8_t * op1, uint8_t* op2, uint8_t* result, size_t len);



#ifdef __cplusplus
}
#endif


#endif /* BR_Ethereum_LES_Base_h */
