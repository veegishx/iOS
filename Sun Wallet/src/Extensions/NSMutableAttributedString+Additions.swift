import Foundation

extension NSMutableAttributedString {
    func set(attributes attrs: [NSAttributedStringKey: Any], forText text: String) {
        if let range = self.string.range(of: text) {
            setAttributes(attrs, range: NSRange(range, in: self.string))
        }
    }
}
