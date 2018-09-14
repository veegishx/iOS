import UIKit

protocol ModalDisplayable {
    var modalTitle: String { get }
    var faqArticleId: String? { get }
    var faqCurrency: CurrencyDef? { get }
}

protocol ModalPresentable {
    var parentView: UIView? { get set }
}
