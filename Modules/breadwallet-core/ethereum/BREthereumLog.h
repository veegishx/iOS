#ifndef BR_Ethereum_Log_h
#define BR_Ethereum_Log_h

#include "BREthereumBase.h"
#include "BREthereumAccount.h"
#include "BREthereumBloomFilter.h"

#ifdef __cplusplus
extern "C" {
#endif

    //
    // Log Topic
    //
typedef struct {
    uint8_t bytes[32];
} BREthereumLogTopic;

extern BREthereumBloomFilter
logTopicGetBloomFilter (BREthereumLogTopic topic);

extern BREthereumBloomFilter
logTopicGetBloomFilterAddress (BREthereumAddressRaw address);

    //
    // Log
    //
typedef struct BREthereumLogRecord *BREthereumLog;

extern BREthereumAddressRaw
logGetAddress (BREthereumLog log);

extern size_t
logGetTopicsCount (BREthereumLog log);

extern  BREthereumLogTopic
logGetTopic (BREthereumLog log, size_t index);

extern BRRlpData
logGetData (BREthereumLog log);
    
extern BREthereumLog
logRlpDecodeItem (BRRlpItem item,
                  BRRlpCoder coder);
/**
 * [QUASI-INTERNAL - used by BREthereumBlock]
 */
extern BRRlpItem
logRlpEncodeItem(BREthereumLog log,
                 BRRlpCoder coder);

extern BRRlpData
logEncodeRLP (BREthereumLog log);

extern BREthereumLog
logDecodeRLP (BRRlpData data);

#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Log_h */
