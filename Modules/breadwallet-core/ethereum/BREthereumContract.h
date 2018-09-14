#ifndef BR_Ethereum_Contract_h
#define BR_Ethereum_Contract_h

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BREthereumFunctionRecord *BREthereumContractFunction;
typedef struct BREthereumEventRecord *BREthereumContractEvent;
typedef struct BREthereumContractRecord *BREthereumContract;


extern BREthereumContract contractERC20;
extern BREthereumContractFunction functionERC20Transfer; // "transfer(address,uint256)"
extern BREthereumContractEvent eventERC20Transfer;       // "Transfer(address indexed _from, address indexed _to, uint256 _value)"

/**
 *
 */
extern const char *
eventGetSelector (BREthereumContractEvent event);

/**
 * Encode an Ehtereum function with arguments.  The specific arguments and their types are
 * defined on a function-by-function basis.  For each function argument, contractEncode() is
 * called with a pair as (uint8_t *bytes, size_t bytesCount).  Thus for example, an ERC20
 * token transfer would be called as:
 *
 * char *address;
 * UInt256 amount;
 *
 * char *encoding contractEncode (contractERC20, functionERC20Transfer,
 *          (uint8_t *) address, strlen(address),
 *          (uint8_t *) &amount, sizeof (UInt256),
 *          NULL);  // end marker -> 'bytes' is never NULL.
 * ...
 * free (encoding);
 */
extern const char *
contractEncode (BREthereumContract contract, BREthereumContractFunction function, ...);

/**
 * Return the function for `encodeing` or NULL.
 *
 * @param contract
 * @param encoding
 * @return
 */
extern BREthereumContractFunction
contractLookupFunctionForEncoding (BREthereumContract contract, const char *encoding);

extern BREthereumContractEvent
contractLookupEventForTopic (BREthereumContract contract, const char *topic);

#ifdef __cplusplus
}
#endif

#endif // BR_Ethereum_Contract_h
