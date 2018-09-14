#ifndef BR_Ethereum_Transaction_Receipt_h
#define BR_Ethereum_Transaction_Receipt_h

#include "BREthereumBase.h"
#include "BREthereumBloomFilter.h"
#include "BREthereumLog.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREthereumTransactionReceiptRecord *BREthereumTransactionReceipt;

extern BREthereumBoolean
transactionReceiptMatch (BREthereumTransactionReceipt receipt,
                     BREthereumBloomFilter filter);

extern BREthereumBoolean
transactionReceiptMatchAddress (BREthereumTransactionReceipt receipt,
                                BREthereumAddressRaw address);

extern BREthereumTransactionReceipt
transactionReceiptDecodeRLP (BRRlpData data);

extern BRRlpData
transactionReceiptEncodeRLP (BREthereumTransactionReceipt receipt);

#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Transaction_Receipt_h */
