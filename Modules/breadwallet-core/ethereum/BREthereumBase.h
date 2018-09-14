#ifndef BR_Ethereum_Base_H
#define BR_Ethereum_Base_H

#ifdef __cplusplus
extern "C" {
#endif

#define private_extern  extern

#include "rlp/BRRlp.h"
    
//
// Etherum Boolean
//
typedef enum {
  ETHEREUM_BOOLEAN_TRUE = 0,               // INTENTIONALLY 'backwards'
  ETHEREUM_BOOLEAN_FALSE = 1
} BREthereumBoolean;

#define ETHEREUM_BOOLEAN_IS_TRUE(x)  ((x) == ETHEREUM_BOOLEAN_TRUE)
#define ETHEREUM_BOOLEAN_IS_FALSE(x) ((x) == ETHEREUM_BOOLEAN_FALSE)

#define AS_ETHEREUM_BOOLEAN(x)    ((x) ? ETHEREUM_BOOLEAN_TRUE : ETHEREUM_BOOLEAN_FALSE)

//
// Ethereum Comparison
//
typedef enum {
  ETHEREUM_COMPARISON_LT = -1,
  ETHEREUM_COMPARISON_EQ =  0,
  ETHEREUM_COMPARISON_GT = +1
} BREthereumComparison;

//
// Hash - An Ethereum 256-bit Keccak hash
//

#define ETHEREUM_HASH_BYTES    (256/8)

typedef struct {
    uint8_t bytes[ETHEREUM_HASH_BYTES];
} BREthereumHash;

#define EMPTY_HASH_INIT   { \
    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0, \
    0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0  \
}

/**
 * Create a Hash by converting from a hex-encoded string of a hash.  The string must
 * begin with '0x'.
 */
extern BREthereumHash
hashCreate (const char *string);

/**
 * Create an empty (all zeros) Hash
 */
extern BREthereumHash
hashCreateEmpty (void);

/**
 * Creata a Hash by computing it from a arbitrary data set
 */
extern BREthereumHash
hashCreateFromData (BRRlpData data);

/**
 * Return the hex-encoded string
 */
extern char *
hashAsString (BREthereumHash hash);

extern BREthereumBoolean
hashExists (BREthereumHash hash);

extern BREthereumHash
hashCopy(BREthereumHash hash);

extern BREthereumComparison
hashCompare(BREthereumHash hash1, BREthereumHash hash2);

extern BREthereumBoolean
hashEqual (BREthereumHash hash1, BREthereumHash hash2);

extern BRRlpItem
hashRlpEncode(BREthereumHash hash, BRRlpCoder coder);

extern BREthereumHash
hashRlpDecode (BRRlpItem item, BRRlpCoder coder);
    
#ifdef __cplusplus
}
#endif

#endif /* BR_Ethereum_Base_H */
