import UIKit

class MenuCell : SeparatorCell {
    
    static let cellIdentifier = "MenuCell"
    
    func set(item: MenuItem) {
        textLabel?.text = item.title
        textLabel?.font = .customBody(size: 16.0)
        textLabel?.textColor = .white
        
        imageView?.image = item.icon
        imageView?.tintColor = .navigationTint
        
        if let accessoryText = item.accessoryText?() {
            let label = UILabel(font: .customMedium(size: 16.0), color: .transparentWhiteText)
            label.text = accessoryText
            label.sizeToFit()
            accessoryView = label
        } else {
            accessoryView = nil
            accessoryType = .none
        }
    }
}
