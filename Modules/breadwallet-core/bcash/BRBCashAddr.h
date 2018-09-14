#ifndef BRBCashAddr_h
#define BRBCashAddr_h

#include <stddef.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

// b-cash address format: https://github.com/bitcoincashorg/spec/blob/master/cashaddr.md

// returns the number of bytes written to bitcoinAddr36 (maximum of 36)
size_t BRBCashAddrDecode(char *bitcoinAddr36, const char *bCashAddr);

// returns the number of bytes written to bCashAddr55 (maximum of 55)
size_t BRBCashAddrEncode(char *bCashAddr55, const char *bitcoinAddr);

#ifdef __cplusplus
}
#endif

#endif // BRBCashAddr_h
