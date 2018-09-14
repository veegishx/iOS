import XCTest
@testable import sunwallet

class WalletCreationTests: XCTestCase {

    private let walletManager: BTCWalletManager = try! BTCWalletManager(currency: Currencies.btc, dbPath: nil)

    override func setUp() {
        super.setUp()
        clearKeychain()
    }

    override func tearDown() {
        super.tearDown()
        clearKeychain()
    }

    func testWalletCreation() {
        XCTAssertNotNil(walletManager.setRandomSeedPhrase(), "Seed phrase should not be nil.")
    }
}
