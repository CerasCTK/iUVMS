import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Window

ApplicationWindow {
    id: root

    width: 500
    height: 500

    visible: true

    Rectangle {
        id: rect

        width: 20
        height: 20

        x: 20
        y: 20

        color: "red"
    }
}
