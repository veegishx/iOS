#ifndef BR_Ethereum_Frame_Coder_h
#define BR_Ethereum_Frame_Coder_h

#include <inttypes.h>
#include "BRKey.h"
#include "BRInt.h"
#include "BREthereumBase.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Opaque pointer for a Frame coder
 */
typedef struct BREthereumFrameCoderContext* BREthereumFrameCoder;
    

/**
 * Creates a frame coder
 */
extern BREthereumFrameCoder ethereumFrameCoderCreate(void);
    
/**
 * Initilaize a frame coder
 */
extern BREthereumBoolean ethereumFrameCoderInit(BREthereumFrameCoder fCoder,
                                               UInt512* remoteEphemeral,
                                               UInt256* remoteNonce,
                                               BRKey* ecdheLocal,
                                               UInt256* localNonce,
                                               uint8_t* aukCipher,
                                               size_t aukCipherLen,
                                               uint8_t* authCiper,
                                               size_t authCipherLen,
                                               BREthereumBoolean didOriginate);
    
/**
 * Frees the memory of the frame coder 
 */
extern void ethereumFrameCoderFree(BREthereumFrameCoder coder);

/**
 * Writes a single frame to the coder
 */
 extern void ethereumFrameCoderWrite(BREthereumFrameCoder fCoder, uint8_t msgId,  uint8_t* payload, size_t payloadSize, uint8_t** oBytes, size_t * oBytesSize);

/**
 * Authenticates and descrptys the header 
 */
extern BREthereumBoolean ethereumFrameCoderDecryptHeader(BREthereumFrameCoder fCoder, uint8_t * oBytes, size_t outSize);
 
/**
 * Authenticates and descrptys the frame
 */
extern BREthereumBoolean ethereumFrameCoderDecryptFrame(BREthereumFrameCoder fCoder, uint8_t * oBytes, size_t outSize);
  
 
#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Frame_Coder_h */
