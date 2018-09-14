import UIKit

extension UITableView {
    func reload(row: Int, section: Int) {
        beginUpdates()
        reloadRows(at: [IndexPath(row: row, section: section)], with: .automatic)
        endUpdates()
    }
}
