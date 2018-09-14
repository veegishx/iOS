#ifndef BRKeyECIES_h
#define BRKeyECIES_h

#include "BRKey.h"

#ifdef __cplusplus
extern "C" {
#endif
    
// ecies-aes128-sha256 as specified in SEC 1, 5.1: http://www.secg.org/SEC1-Ver-1.0.pdf
// NOTE: these are not implemented using constant time algorithms
    
size_t BRKeyECIESAES128SHA256Encrypt(BRKey *pubKey, void *out, size_t outLen, BRKey *ephemKey,
                                     const void *data, size_t dataLen);

size_t BRKeyECIESAES128SHA256Decrypt(BRKey *privKey, void *out, size_t outLen, const void *data, size_t dataLen);

#ifdef __cplusplus
}
#endif

#endif // BRKeyECIES_h
