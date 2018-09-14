#ifndef BR_Ethereum_Network_h
#define BR_Ethereum_Network_h

#include "BRInt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREthereumNetworkRecord *BREthereumNetwork;
typedef int BREthereumChainId;  // 'Officially' UInt256

extern BREthereumChainId
networkGetChainId (BREthereumNetwork network);

extern const BREthereumNetwork ethereumMainnet;
extern const BREthereumNetwork ethereumTestnet;
extern const BREthereumNetwork ethereumRinkeby;

#ifdef __cplusplus
}
#endif

#endif // BR_Ethereum_Network_h
