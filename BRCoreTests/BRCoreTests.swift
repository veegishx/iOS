import XCTest
import BRCore.Ethereum

class BRCoreTests: XCTestCase {
    
    override func setUp() {
        super.setUp()
    }
    
    override func tearDown() {
        super.tearDown()
    }
    
    func testCore() {
        XCTAssert(1 == BRRunTests());
    }
    
    func testCoreEthereum () {
        runTests()
        
    }
}
