import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    visible: true
    width: 640
    height: 480
    color: "black"

    property int rectangleHeigh: 1
    property string rectangleColor: "white"
    property int threshold: 200

    Rectangle {
        id: testRectangle
        width: 100
        height: rectangleHeigh
        color: rectangleColor
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
