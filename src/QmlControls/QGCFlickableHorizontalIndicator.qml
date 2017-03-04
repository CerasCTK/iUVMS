import QtQuick 2.7

Rectangle {
    id:                    horizontalIndicator
    anchors.bottomMargin:  2
    anchors.bottom:        parent.bottom
    x:                     parent.width * (parent.contentX / parent.contentWidth)
    z:                     10
    height:                2
    width:                 parent.width * (parent.width / parent.contentWidth)
    color:                 parent.indicatorColor
    visible:               showIndicator

    property bool showIndicator: (parent.flickableDirection == Flickable.AutoFlickDirection ||
                                  parent.flickableDirection == Flickable.HorizontalFlick ||
                                  parent.flickableDirection == Flickable.HorizontalAndVerticalFlick) &&
                                 (parent.contentWidth > parent.width)

    Component.onCompleted:  animateOpacity.restart()
    onVisibleChanged:       animateOpacity.restart()
    onWidthChanged:         animateOpacity.restart()

    Connections {
        target:                    horizontalIndicator.parent
        onMovementStarted:         horizontalIndicator.opacity = 1.0
        onMovementEnded:           animateOpacity.restart()
        onContentHeightChanged:    animateOpacity.restart()
    }

    NumberAnimation {
        id:            animateOpacity
        target:        horizontalIndicator
        properties:    "opacity"
        from:          1.0
        to:            0.0
        duration:      1000
        easing.type:   Easing.InQuint
    }
}
