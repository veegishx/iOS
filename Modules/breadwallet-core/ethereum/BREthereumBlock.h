#ifndef BR_Ethereum_Block_H
#define BR_Ethereum_Block_H

#include "BREthereumBase.h"
#include "BREthereumTransaction.h"
#include "BREthereumBloomFilter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREthereumBlockHeaderRecord *BREthereumBlockHeader;
typedef struct BREthereumBlockRecord *BREthereumBlock;

//
// Block Header
//
extern BREthereumBlockHeader
blockHeaderDecodeRLP (BRRlpData data);

extern BRRlpData
blockHeaderEncodeRLP (BREthereumBlockHeader header,
                      BREthereumBoolean withNonce);

extern BREthereumHash
blockHeaderGetParentHash (BREthereumBlockHeader header);

// ...

extern uint64_t
blockHeaderGetNonce (BREthereumBlockHeader header);

extern BREthereumBoolean
blockHeaderMatch (BREthereumBlockHeader header,
            BREthereumBloomFilter filter);

extern BREthereumBoolean
blockHeaderMatchAddress (BREthereumBlockHeader header,
                   BREthereumAddressRaw address);

//
// Block
//
extern BREthereumBlock
createBlockMinimal(BREthereumHash hash,
            uint64_t number,
            uint64_t timestamp);

extern BREthereumBlock
createBlock (BREthereumBlockHeader header,
             BREthereumBlockHeader ommers[], size_t ommersCount,
             BREthereumTransaction transactions[], size_t transactionCount);

extern BREthereumBlockHeader
blockGetHeader (BREthereumBlock block);

extern unsigned long
blockGetTransactionsCount (BREthereumBlock block);

extern BREthereumTransaction
blockGetTransaction (BREthereumBlock block, unsigned int index);

extern unsigned long
blockGetOmmersCount (BREthereumBlock block);

extern BREthereumBlockHeader
blockGetOmmer (BREthereumBlock block, unsigned int index);

extern BREthereumHash
blockGetHash (BREthereumBlock block);

extern uint64_t
blockGetNumber (BREthereumBlock block);

extern uint64_t
blockGetConfirmations (BREthereumBlock block);

extern uint64_t
blockGetTimestamp (BREthereumBlock block);

extern BRRlpData
blockEncodeRLP (BREthereumBlock block,
                BREthereumNetwork network);

extern BREthereumBlock
blockDecodeRLP (BRRlpData data,
                BREthereumNetwork network);

//
// Genesis Blocks
//
extern const BREthereumBlockHeader ethereumMainnetBlockHeader;
extern const BREthereumBlockHeader ethereumTestnetBlockHeader;
extern const BREthereumBlockHeader ethereumRinkebyBlockHeader;

extern const BREthereumBlockHeader
networkGetGenesisBlockHeader (BREthereumNetwork network);
    
#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Block_H */
