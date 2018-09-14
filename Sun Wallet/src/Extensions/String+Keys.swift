import Foundation
import BRCore

extension String {
    var isValidPrivateKey: Bool {
        return BRPrivKeyIsValid(self) != 0
    }

    var isValidBip38Key: Bool {
        return BRBIP38KeyIsValid(self) != 0
    }
}
