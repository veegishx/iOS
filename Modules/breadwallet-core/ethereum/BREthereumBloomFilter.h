#ifndef BR_Ethereum_Bloom_Filter_h
#define BR_Ethereum_Bloom_Filter_h

#include "BREthereumBase.h"
#include "BREthereumAccount.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ETHEREUM_BLOOM_FILTER_BITS 2048
#define ETHEREUM_BLOOM_FILTER_BYTES   (ETHEREUM_BLOOM_FILTER_BITS / 8)

typedef struct {
    uint8_t bytes[ETHEREUM_BLOOM_FILTER_BYTES];
} BREthereumBloomFilter;

#define EMPTY_BLOOM_FILTER_INIT   { \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
}

/**
 * Create an empty BloomFilter
 */
extern BREthereumBloomFilter
bloomFilterCreateEmpty (void);

/**
 * Create a BloomFilter from `hash`
 */
extern BREthereumBloomFilter
bloomFilterCreateHash (const BREthereumHash hash);

/**
 * Create a BloomFilter from `data` - computes the hash of `data`
 */
extern BREthereumBloomFilter
bloomFilterCreateData (const BRRlpData data);

/**
 * Create a BloomFilter from `address` - computes the hash of `address`
 */
extern BREthereumBloomFilter
bloomFilterCreateAddress (const BREthereumAddressRaw address);

extern BREthereumBloomFilter
bloomFilterOr (const BREthereumBloomFilter filter1, const BREthereumBloomFilter filter2);

extern void
bloomFilterOrInPlace (BREthereumBloomFilter filter1, const BREthereumBloomFilter filter2);

extern BREthereumBoolean
bloomFilterEqual (const BREthereumBloomFilter filter1, const BREthereumBloomFilter filter2);

extern BREthereumBoolean
bloomFilterMatch (const BREthereumBloomFilter filter, const BREthereumBloomFilter other);

extern BRRlpItem
bloomFilterRlpEncode(BREthereumBloomFilter filter, BRRlpCoder coder);

extern BREthereumBloomFilter
bloomFilterRlpDecode (BRRlpItem item, BRRlpCoder coder);

/**
 * Return a hex-encode string representation of `filter`.
 */
extern char *
bloomFilterAsString (BREthereumBloomFilter filter);

#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Bloom_Filter_h */
