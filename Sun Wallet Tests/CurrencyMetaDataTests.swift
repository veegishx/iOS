import XCTest
@testable import sunwallet

class CurrencyMetaDataTests : XCTestCase {

    func testAddingCurrencies() {
        let metaData = CurrencyListMetaData()
        let tokens = ["1", "2"]
        let tokenArray = ["erc20:1", "erc20:2"]
        metaData.addTokenAddresses(addresses: tokens)
        XCTAssert(metaData.previouslyAddedTokenAddresses == tokens, "Previously Added Token addresses should match")
        XCTAssert(metaData.enabledTokenAddresses == tokens, "Enabled token addresses should match")
        XCTAssert(metaData.hiddenTokenAddresses == [], "Hidden Token Addresses should be empty")
        XCTAssert(metaData.enabledCurrencies == tokenArray, "Enabled currencies should match")
        XCTAssert(metaData.hiddenCurrencies == [], "Hidden currencies should match")
    }

    func testAddingThenRemovingCurrencies() {
        let metaData = CurrencyListMetaData()
        let tokens = ["1", "2"]
        let tokenArray = ["erc20:1", "erc20:2"]
        metaData.addTokenAddresses(addresses: tokens)
        metaData.removeTokenAddresses(addresses: tokens)
        XCTAssert(metaData.previouslyAddedTokenAddresses == tokens, "Previously Added Token addresses should match")
        XCTAssert(metaData.enabledTokenAddresses == [], "Enabled token addresses should be empty")
        XCTAssert(metaData.hiddenTokenAddresses == tokens, "Hidden Token Addresses should match")
        XCTAssert(metaData.enabledCurrencies == [], "Enabled currencies should match")
        XCTAssert(metaData.hiddenCurrencies == tokenArray, "Hidden currencies should match")
    }

    func testRemovingSomeCurrencies() {
        let metaData = CurrencyListMetaData()
        let tokens = ["1", "2"]
        metaData.addTokenAddresses(addresses: tokens)
        metaData.removeTokenAddresses(addresses: ["2"])
        XCTAssert(metaData.previouslyAddedTokenAddresses == tokens, "Previously Added Token addresses should match")
        XCTAssert(metaData.enabledTokenAddresses == ["1"], "Enabled token addresses should match")
        XCTAssert(metaData.hiddenTokenAddresses == ["2"], "Hidden Token Addresses should match")
    }

    func testAddRemoveAddCurrencies() {
        let metaData = CurrencyListMetaData()
        let tokens = ["1", "2"]
        metaData.addTokenAddresses(addresses: tokens)
        metaData.removeTokenAddresses(addresses: ["2"])
        metaData.addTokenAddresses(addresses: ["2"])
        XCTAssert(metaData.previouslyAddedTokenAddresses == tokens, "Previously Added Token addresses should match")
        XCTAssert(metaData.enabledTokenAddresses == tokens, "Enabled token addresses should match")
        XCTAssert(metaData.hiddenTokenAddresses == [], "Hidden Token Addresses should match")
    }
}
