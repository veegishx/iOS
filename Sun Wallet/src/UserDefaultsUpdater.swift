import Foundation

private enum AppGroup {
    static let id = "group.sunwallet"
    static let requestDataKey = "kBRSharedContainerDataWalletRequestDataKey"
    static let receiveAddressKey = "kBRSharedContainerDataWalletReceiveAddressKey"
}

class UserDefaultsUpdater {

    init(walletManager: BTCWalletManager) {
        self.walletManager = walletManager
    }

    func refresh() {
        guard let wallet = walletManager.wallet else { return }
        defaults?.set(wallet.receiveAddress as NSString, forKey: AppGroup.receiveAddressKey)
        defaults?.set(wallet.receiveAddress.data(using: .utf8), forKey: AppGroup.requestDataKey)
    }

    private lazy var defaults: UserDefaults? = {
        return UserDefaults(suiteName: AppGroup.id)
    }()

    private let walletManager: BTCWalletManager

}
