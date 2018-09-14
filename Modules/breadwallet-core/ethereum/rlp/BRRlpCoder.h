#ifndef BR_RLP_Coder_H
#define BR_RLP_Coder_H

#include <stddef.h>
#include <stdint.h>
#include "BRInt.h"

#ifdef __cplusplus
extern "C" {
#endif

//
// RLP Coder
//
typedef struct BRRlpCoderRecord *BRRlpCoder;

extern BRRlpCoder
rlpCoderCreate (void);

extern void
rlpCoderRelease (BRRlpCoder coder);

//
// RLP Data
//
typedef struct {
    size_t bytesCount;
    uint8_t *bytes;
} BRRlpData;

extern BRRlpData
createRlpDataEmpty (void);

extern void
rlpDataRelease (BRRlpData data);

//
// RLP Item
//
typedef struct {
  void *identifier;
  unsigned long indexer;
} BRRlpItem;

extern BRRlpItem
rlpGetItem (BRRlpCoder coder, BRRlpData data);

//
// UInt64
//
extern BRRlpItem
rlpEncodeItemUInt64(BRRlpCoder coder, uint64_t value, int zeroAsEmptyString);

extern uint64_t
rlpDecodeItemUInt64(BRRlpCoder coder, BRRlpItem item, int zeroAsEmptyString);

//
// UInt256
//
extern BRRlpItem
rlpEncodeItemUInt256(BRRlpCoder coder, UInt256 value, int zeroAsEmptyString);

extern UInt256
rlpDecodeItemUInt256(BRRlpCoder coder, BRRlpItem item, int zeroAsEmptyString);

//
// Bytes
//
extern BRRlpItem
rlpEncodeItemBytes (BRRlpCoder coder, uint8_t *bytes, size_t bytesCount);

extern BRRlpData
rlpDecodeItemBytes (BRRlpCoder coder, BRRlpItem item);

//
// String
//
extern BRRlpItem
rlpEncodeItemString (BRRlpCoder coder, char *string);

extern char *
rlpDecodeItemString (BRRlpCoder coder, BRRlpItem item);

extern int
rlpDecodeItemIsString (BRRlpCoder coder, BRRlpItem item);

//
// Hex String
//
extern BRRlpItem
rlpEncodeItemHexString (BRRlpCoder coder, char *string);

extern char *
rlpDecodeItemHexString (BRRlpCoder coder, BRRlpItem item, const char *prefix);

//
// List
//
extern BRRlpItem
rlpEncodeList1 (BRRlpCoder coder, BRRlpItem item1);

extern BRRlpItem
rlpEncodeList2 (BRRlpCoder coder, BRRlpItem item1, BRRlpItem item2);

extern BRRlpItem
rlpEncodeList (BRRlpCoder coder, size_t count, ...);

extern BRRlpItem
rlpEncodeListItems (BRRlpCoder coder, BRRlpItem *items, size_t itemsCount);

extern const BRRlpItem *
rlpDecodeList (BRRlpCoder coder, BRRlpItem item, size_t *itemsCount);
    
// Hold onto BRRlpItem 'forever'... then try to use... will fail because 'coder'
// will not have 'context'
extern void
rlpDataExtract (BRRlpCoder coder, BRRlpItem item, uint8_t **bytes, size_t *bytesCount);

#ifdef __cplusplus
}
#endif

#endif //BR_RLP_Coder_H
