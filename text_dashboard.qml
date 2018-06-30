import QtQuick 2.6

import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: root
    visible: true
    width: dashboardValues.resolutionWidth
    height: dashboardValues.resolutionHeight
    color: "black"

    readonly property int caution_light_size: root.width * 0.05
    readonly property int content_margin: root.width * 0.005

    property int animatedValue: 0
    SequentialAnimation on animatedValue {
        loops: Animation.Infinite
        PropertyAnimation { to: 100; duration: 5000 }
        PropertyAnimation { to: 0; duration: 5000 }
    }

    Item {
        id: main_container
        width: root.width
        height: root.height
        anchors.centerIn: parent

        Rectangle {
            id: main_content
            width: parent.width
            height: parent.height
            color: "black"
            // make caution light as border of main container
            border.width: caution_light_size
            border.color: "black"

            // Animation
            SequentialAnimation on border.color {
                loops: Animation.Infinite
                //ColorAnimation  { to: "red"; duration: 50 }
                ColorAnimation  { to: "red"; duration: 300 }
                //ColorAnimation  { to: main_content.color; duration: 50 }
                ColorAnimation  { to: main_content.color; duration: 1000 }
            }

            Row {
                id: row1
                spacing: 10
                padding: caution_light_size
                anchors.top: parent.top
                anchors.left: parent.left

                Item {
                    width: main_container.width - (2 * caution_light_size)
                    height: main_container.height * 0.5 - caution_light_size

                    Rectangle {
                        color: main_content.color
                        width: parent.width / 2
                        height: parent.height

                        Text {
                            id: rpm
                            height: parent.height
                            width: parent.width / 2
                            color:"white"
                            x: parent.width * 0.2
                            y: parent.height / 3
                            font.pointSize: 56
                            text: dashboardValues.rpm
                        }

                        Text {
                            id: rpm_label
                            height: parent.height
                            width: parent.width / 2
                            x: rpm.width * 1.3
                            y: parent.height / 3
                            color:"white"
                            font.pointSize: 56
                            text: "RPM"
                        }

                    }

                    Rectangle {
                        color: main_content.color
                        width: parent.width / 2
                        height: parent.height
                        x: parent.width / 2

                        Text {
                            id: kph
                            height: parent.height
                            width: parent.width / 2
                            color:"white"
                            x: parent.width / 5
                            y: parent.height / 3
                            font.pointSize: 56
                            text: dashboardValues.kph
                        }
                        Text {
                            height: parent.height
                            width: parent.width / 2
                            x: kph.x * 2.5
                            y: parent.height / 3
                            color:"white"
                            font.pointSize: 56
                            text: "km/h"
                        }
                    }
                }
            }

            Row {
                id: row2
                spacing: 10
                padding: caution_light_size
                anchors.bottom: parent.bottom
                anchors.right: parent.right

                Item {
                    id: row2_item
                    width: main_container.width - 2 * caution_light_size // / 3 * 2 // 2/3 della larghezza
                    height: main_container.height * 0.5 - caution_light_size

                    Rectangle {
                        color: main_content.color
                        width: parent.width / 3
                        height: parent.height
                        x: 0

                        Text {
                            id: gear
                            height: parent.height
                            width: parent.width / 2
                            color:"white"
                            x: parent.width / 5
                            y: parent.height / 3
                            font.pointSize: 56
                            text: dashboardValues.gear
                        }
                        Text {
                            height: parent.height
                            width: parent.width / 2
                            x: gear.x * 2
                            y: parent.height / 3
                            color:"white"
                            font.pointSize: 56
                            text: "Gear"
                        }
                    }

                    Rectangle {
                        id: pressure
                        border.width: 5
                        border.color: "#161616"
                        width: parent.width / 3
                        height: parent.height
                        x: parent.width / 3

                        Rectangle {
                            id: fuel
                            color: "lightgray"
                            width: parent.width - 2*content_margin
                            height: parent.height / 2 - content_margin
                            x:content_margin
                            y:content_margin

                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: 10
                                y: parent.height/3
                                font.pointSize: 32
                                text: "Fuel"
                            }
                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: parent.width/3 + 30
                                y: parent.height/3
                                font.pointSize: 32
                                text: dashboardValues.fuel
                            }
                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: parent.width/3*2
                                y: parent.height/3
                                font.pointSize: 32
                                text: "Bar"
                            }
                        }

                        Rectangle {
                            id: oil
                            color: "lightgray"
                            width: parent.width - 2*content_margin
                            height: parent.height / 2 - content_margin
                            anchors.top: fuel.bottom
                            x:content_margin

                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: 10
                                y: parent.height/3
                                font.pointSize: 32
                                text: "Oil"
                            }

                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: parent.width/3 + 30
                                y: parent.height/3
                                font.pointSize: 32
                                text: dashboardValues.oil_press
                            }

                            Text {
                                height: parent.height
                                width: parent.width/2
                                x: parent.width/3*2
                                y: parent.height/3
                                font.pointSize: 32
                                text: "Bar"
                            }
                        }
                    }

                    Rectangle {
                        id: temperature
                        border.width: 5
                        border.color: "#161616"
                        width: parent.width / 3
                        height: parent.height
                        anchors.right: parent.right

                        Rectangle {
                            id: h2o
                            color: "lightgray"
                            width: parent.width - 2*content_margin
                            height: parent.height / 2 - content_margin
                            x:content_margin
                            y:content_margin

                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: 10
                                y: parent.height/3
                                font.pointSize: 32
                                text: "H2O"
                            }
                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: parent.width/3 + 30
                                y: parent.height/3
                                font.pointSize: 32
                                text: dashboardValues.h2o
                            }
                            Text {
                                height: parent.height
                                width: parent.width/2
                                x: parent.width/3*2
                                y: parent.height/3
                                font.pointSize: 32
                                text: "°C"
                            }
                        }

                        Rectangle {
                            id: oil_temp
                            color: "lightgray"
                            width: parent.width - 2*content_margin
                            height: parent.height / 2 - content_margin
                            anchors.top: h2o.bottom
                            x:content_margin

                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: 10
                                y: parent.height/3
                                font.pointSize: 32
                                text: "Oil"
                            }
                            Text {
                                height: parent.height
                                width: parent.width/3
                                x: parent.width/3 + 30
                                y: parent.height/3
                                font.pointSize: 32
                                text: dashboardValues.oil_temp
                            }
                            Text {
                                height: parent.height
                                width: parent.width/2
                                x: parent.width/3*2
                                y: parent.height/3
                                font.pointSize: 32
                                text: "°C"
                            }
                        }
                    }
                }

            }

        }
    }
}
