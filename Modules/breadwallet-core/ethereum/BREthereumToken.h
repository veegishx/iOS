#ifndef BR_Ethereum_Token_H
#define BR_Ethereum_Token_H

#include "BREthereumEther.h"
#include "BREthereumGas.h"
#include "BREthereumContract.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * An Ethereum ERC20 Token
 */
typedef struct BREthereumTokenRecord *BREthereumToken;

/**
 * Return the token address as a '0x'-prefixed string.  DO NOT FREE THIS.
 */
extern const char *
tokenGetAddress (BREthereumToken token);

extern const char *
tokenGetSymbol (BREthereumToken token);

extern const char *
tokenGetName (BREthereumToken token);

extern const char *
tokenGetDescription(BREthereumToken token);

extern int
tokenGetDecimals (BREthereumToken token);

extern BREthereumGas
tokenGetGasLimit (BREthereumToken token);

extern BREthereumGasPrice
tokenGetGasPrice (BREthereumToken token);

extern const char *
tokenGetColorLeft (BREthereumToken token);

extern const char *
tokenGetColorRight (BREthereumToken token);

extern BREthereumContract
tokenGetContract (BREthereumToken token);

extern const BREthereumToken tokenBRD;

#if defined (BITCOIN_DEBUG)
extern const BREthereumToken tokenTST;
#endif

extern BREthereumToken
tokenLookup (const char *address);

extern int
tokenCount (void);

extern BREthereumToken
tokenGet (int index);

//
// Token Quantity
//

/**
 * A BREthereumTokenQuantityUnit defines the (external) representation of a token quantity
 */
typedef enum {
  TOKEN_QUANTITY_TYPE_DECIMAL,
  TOKEN_QUANTITY_TYPE_INTEGER
} BREthereumTokenQuantityUnit;

/**
 * A BREthereumTokenQuantity defines a token amount.
 *
 */
typedef struct {
  BREthereumToken token;
  UInt256 valueAsInteger;
} BREthereumTokenQuantity;

extern BREthereumTokenQuantity
createTokenQuantity (BREthereumToken token,
                     UInt256 valueAsInteger);

extern BREthereumTokenQuantity
createTokenQuantityString (BREthereumToken token,
                           const char *number,
                           BREthereumTokenQuantityUnit unit,
                           BRCoreParseStatus *status);

extern const BREthereumToken
tokenQuantityGetToken (BREthereumTokenQuantity quantity);

/**
 * A newly allocated string; you own it.
 *
 * @param quantity
 * @param unit
 * @return
 */
extern char *
tokenQuantityGetValueString(const BREthereumTokenQuantity quantity,
                            BREthereumTokenQuantityUnit unit);

extern BREthereumComparison
tokenQuantityCompare (BREthereumTokenQuantity q1, BREthereumTokenQuantity q2, int *typeMismatch);

#ifdef __cplusplus
}
#endif

#endif //BR_Ethereum_Token_H

