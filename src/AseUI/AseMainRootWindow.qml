import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Window

import QGroundControl
import UVMS.ScreenManager
import UVMS.FlyView

ApplicationWindow {
    id: mainRootWindow
    minimumWidth:   ScreenManager.isMobile ? ScreenManager.screenWidth  : Math.min(ScreenManager.defaultFontPixelWidth * 100, Screen.width)
    minimumHeight:  ScreenManager.isMobile ? ScreenManager.screenHeight : Math.min(ScreenManager.defaultFontPixelWidth * 50, Screen.height)
    visible:        true

    Component.onCompleted: {
        //-- Full screen on mobile or tiny screens
        if (!ScreenManager.isFakeMobile && (ScreenManager.isMobile || Screen.height / ScreenManager.realPixelDensity < 120)) {
            mainWindow.showFullScreen()
        } else {
            width   = ScreenManager.isMobile ? ScreenManager.screenWidth  : Math.min(250 * Screen.pixelDensity, Screen.width)
            height  = ScreenManager.isMobile ? ScreenManager.screenHeight : Math.min(150 * Screen.pixelDensity, Screen.height)
        }
    }

    readonly property real _topBottomMargins: ScreenManager.defaultFontPixelHeight * 0.5

    QtObject {
        id: globalVars

        readonly property var       activeVehicle:                  QGroundControl.multiVehicleManager.activeVehicle
        readonly property real      defaultTextHeight:              ScreenManager.defaultFontPixelHeight
        readonly property real      defaultTextWidth:               ScreenManager.defaultFontPixelWidth
    }

    FlyView {

    }
}
