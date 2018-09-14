#ifndef BR_Ethereum_AccountState_H
#define BR_Ethereum_AccountState_H

#include "BREthereumEther.h"
#include "BREthereumBase.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREthereumAccountStateRecord *BREthereumAccountState;

extern uint64_t
accountStateGetNonce (BREthereumAccountState state);

extern BREthereumEther
accountStateGetBalance (BREthereumAccountState state);

extern BREthereumHash
accountStateGetStorageRoot (BREthereumAccountState state);

extern BREthereumHash
accountStateGetCodeHash (BREthereumAccountState state);

extern BRRlpItem
accountStateRlpEncodeItem (BREthereumAccountState state, BRRlpCoder coder);

extern BREthereumAccountState
accountStateRlpDecodeItem (BRRlpItem item, BRRlpCoder coder);

#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_AccountState_H */
