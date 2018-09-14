import UIKit

extension UIViewControllerContextTransitioning {
    var views: (UIView, UIView)? {
        guard let fromView = self.view(forKey: .from) else { assert(false, "Empty from view"); return nil}
        guard let toView = self.view(forKey: .to) else { assert(false, "Empty to view"); return nil}
        return (fromView, toView)
    }
}
