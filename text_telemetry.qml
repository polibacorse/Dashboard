import QtQuick 2.6

import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

import QtPositioning 5.6
import QtLocation 5.6

Window {
    id: root
    visible: true
    width: 1200
    height: 800

    color: "#606060"

    readonly property int my_border: root.width * 0.05
    readonly property int small_border: root.width * 0.005
    readonly property int text_width: 100
    readonly property int font_size: 24
    readonly property int small_font_size: 14
    readonly property int row_height: 40
    readonly property int padd: 3


    // Dashboards are typically in a landscape orientation, so we need to ensure
    // our height is never greater than our width.
    Item {
        id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent

        Row{
            id: row1
            width: parent.width
            height: 7*(row_height+padd) + small_border

            Rectangle {
                id: main_rect
                width: parent.width
                height: parent.height
                color: "lightgray" //"#606060"


                Column{
                    width: (container.width - 2*padd) / 5*3
                    height: container.height - 2*padd
                    x: padd
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:gear
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "Gear:"
                        }
                        Text {
                            anchors.left: gear.right
                            height: parent.height
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.gear
                        }

                    }//row1

                    Rectangle {
                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:kph
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "Kph:"
                        }
                        Text {
                            anchors.right: parent.right
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.kph
                        }
                        Rectangle{
                            height: parent.height * 0.6
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: kph.right
                            width: ((parent.width /1.4) * dashboardValues.percent_kph) + 10
                            color: "white"
                        }

                    }//row2

                    Rectangle {
                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:rpm
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "Rpm:"
                        }
                        Text {
                            id:rpmValue
                            anchors.right: parent.right
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.rpm
                        }
                        Rectangle{
                            height: parent.height * 0.6
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: rpm.right
                            width: ((parent.width /1.4) * dashboardValues.percent_rpm) + 10
                            color: "white"
                        }

                    }//row3

                    Rectangle {
                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:fuel
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "Fuel:"
                        }
                        Text {
                            id:fuelValue
                            anchors.right: parent.right
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.fuel
                        }
                        Rectangle{
                            height: parent.height * 0.6
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: fuel.right
                            width: ((parent.width /1.4) * dashboardValues.percent_fuel) + 10
                            color: "white"
                        }

                    }//row4

                    Rectangle {
                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:h2o
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "H2O:"
                        }
                        Text {
                            id:h2oValue
                            anchors.right: parent.right
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.h2o
                        }
                        Rectangle{
                            height: parent.height * 0.6
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: h2o.right
                            width: ((parent.width /1.4) * dashboardValues.percent_h2o) + 10
                            color: "white"
                        }

                    }//row5

                    Rectangle {
                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:oil_p
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "Oil P.:"
                        }
                        Text {
                            id:oil_pValue
                            anchors.right: parent.right
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.oil_press
                        }
                        Rectangle{
                            height: parent.height * 0.6
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: oil_p.right
                            width: ((parent.width /1.4) * dashboardValues.percent_oil_press) + 10
                            color: "white"
                        }

                    }//row6

                    Rectangle {
                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:oil_t
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: "Oil T.:"
                        }
                        Text {
                            id:oil_tValue
                            anchors.right: parent.right
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: font_size
                            text: dashboardValues.oil_temp
                        }
                        Rectangle{
                            height: parent.height * 0.6
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: oil_t.right
                            width: ((parent.width /1.4) * dashboardValues.percent_oil_temp) + 10
                            color: "white"
                        }

                    }//row7

                }//Column1

                Column{
                    width: (container.width - 2*padd) / 5*2 -padd
                    height: 7*(row_height+padd) + small_border
                    x: (container.width - 2*padd) / 5*3 + 2*padd
                    y: padd
                    spacing: 2

                    Plugin {
                            id: mapPlugin
                            name: "osm"
                    }

                    Map {
                        id:map_positioning
                        width: parent.width
                        height: parent.height
                        plugin: mapPlugin
                        center {// Bari
                            latitude: dashboardValues.center_latitude
                            longitude: dashboardValues.center_longitude
                        }
                        zoomLevel: 14

                        MapQuickItem {
                            coordinate{ // Bari
                                latitude: dashboardValues.latitude
                                longitude: dashboardValues.longitude
                            }

                            anchorPoint.x: image.width * 0.5
                            anchorPoint.y: image.height * 0.5

                            sourceItem: Column {
                                id: image
                                Rectangle{
                                    color: "red"
                                    width: 12
                                    height: 12
                                    radius: 6
                                }
                            }
                        }
                    }

                }//column2

            }

        }//Row1

        Row{
            id:row2
            width: parent.width
            height: parent.height - row1.height
            y:row1.height

            Rectangle {
                id: row2_rect
                width: parent.width
                height: parent.height
                color: "lightgray"


                Column{
                    id:table_column
                    width: (container.width - 7*padd) / 6
                    height: container.height - 2*padd
                    x: padd
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:a1x
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "A1x:"
                        }
                        Text {
                            anchors.left: a1x.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.a1x
                        }

                    }//row1

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:a1y
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "A1y:"
                        }
                        Text {
                            anchors.left: a1y.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.a1y
                        }

                    }//row2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:steerPos
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Steer Pos.:"
                        }
                        Text {
                            anchors.left: steerPos.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.steerPos
                        }

                    }//row3

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:fl_damp
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "FLdamp:"
                        }
                        Text {
                            anchors.left: fl_damp.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.FLdamp
                        }

                    }//row4

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:fr_damp
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "FRdamp:"
                        }
                        Text {
                            anchors.left: fr_damp.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.FRdamp
                        }

                    }//row5

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:rl_damp
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "RLdamp:"
                        }
                        Text {
                            anchors.left: rl_damp.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.RLdamp
                        }

                    }//row6

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:rr_damp
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "RRdamp:"
                        }
                        Text {
                            anchors.left: rr_damp.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.RRdamp
                        }

                    }//row7

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:current1
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Current1:"
                        }
                        Text {
                            anchors.left: current1.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.current1
                        }

                    }//row8

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:current2
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Current2:"
                        }
                        Text {
                            anchors.left: current2.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.current2
                        }

                    }//row9


                }//Column1

                Column{
                    width: (container.width - 7*padd) / 6
                    height: container.height - 2*padd
                    x: 2*padd + table_column.width
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:dr_ax_speed
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "DrAxSpeed:
"
                        }
                        Text {
                            anchors.left: dr_ax_speed.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.drAxSpeed
                        }

                    }//row1

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:osa_slip
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "OSA slip:"
                        }
                        Text {
                            anchors.left: osa_slip.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.OSASlip
                        }

                    }//row2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:slip_ok
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Slip OK:"
                        }
                        Text {
                            anchors.left: slip_ok.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.slip_ok
                        }

                    }//row3

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:slip_calc
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Slip calc:"
                        }
                        Text {
                            anchors.left: slip_calc.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.slip_Calc
                        }

                    }//row4


                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lap_close
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Lap close:"
                        }
                        Text {
                            anchors.left: lap_close.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.lapClose
                        }

                    }//row5

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:target_rpm_up
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "T. Rpm up:"
                        }
                        Text {
                            anchors.left: target_rpm_up.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.target_rpm_up
                        }

                    }//row6

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:shift_duration
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Shift dur.:"
                        }
                        Text {
                            anchors.left: shift_duration.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.shift_duration
                        }

                    }//row7

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:time_0_75
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "T. 0-75:"
                        }
                        Text {
                            anchors.left: time_0_75.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.time_0_75
                        }

                    }//row8

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:time_0_100
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "T. 0-100:"
                        }
                        Text {
                            anchors.left: time_0_100.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.time_0_100
                        }

                    }//row9


                }//Column2

                Column{
                    width: (container.width - 7*padd) / 6
                    height: container.height - 2*padd
                    x: 3*padd + 2*table_column.width
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:n_satellite
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "N sat:"
                        }
                        Text {
                            anchors.left: n_satellite.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.satellite
                        }

                    }//row1

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:fix
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Fix:"
                        }
                        Text {
                            anchors.left: fix.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.fix
                        }

                    }//row2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:gps_time
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "GPS time:"
                        }
                        Text {
                            anchors.left: gps_time.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.gps_time
                        }

                    }//row3

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:gps_speed
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "GPS speed:"
                        }
                        Text {
                            anchors.left: gps_speed.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.GPS_speed
                        }

                    }//row4

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:altitude
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Altitude:"
                        }
                        Text {
                            anchors.left: altitude.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.altitude
                        }

                    }//row5

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:latitude
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Latitude:"
                        }
                        Text {
                            anchors.left: latitude.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.latitude
                        }

                    }//row6

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:longitude
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Longitude:"
                        }
                        Text {
                            anchors.left: longitude.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.longitude
                        }

                    }//row7

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:tps
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Tps:"
                        }
                        Text {
                            anchors.left: tps.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.tps
                        }

                    }//row8

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:derivata_farfalla
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Der. Farf.:
"
                        }
                        Text {
                            anchors.left: derivata_farfalla.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.derivata_farfalla
                        }

                    }//row9


                }//Column3

                Column{
                    width: (container.width - 7*padd) / 6
                    height: container.height - 2*padd
                    x: 4*padd + 3*table_column.width
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lambda
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Lambda:"
                        }
                        Text {
                            anchors.left: lambda.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.lambda
                        }

                    }//row1

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:map
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Map:"
                        }
                        Text {
                            anchors.left: map.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.map
                        }

                    }//row2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:dmap
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Dmap:"
                        }
                        Text {
                            anchors.left: dmap.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.dmap
                        }

                    }//row3

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:baro
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Baro:"
                        }
                        Text {
                            anchors.left: baro.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.baro
                        }

                    }//row4

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:t_air
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "T. air:"
                        }
                        Text {
                            anchors.left: t_air.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.tair
                        }

                    }//row5

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:terog_pq
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "T. erog pq:"
                        }
                        Text {
                            anchors.left: terog_pq.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.terog_piano_quotato
                        }

                    }//row6

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:terog
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "T. erog:"
                        }
                        Text {
                            anchors.left: terog.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.terog
                        }

                    }//row7

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:sa_base
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "SA base:"
                        }
                        Text {
                            anchors.left: sa_base.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.SABase
                        }

                    }//row8

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:sa
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "SA:"
                        }
                        Text {
                            x: sa.width
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.SA
                        }

                    }//row9




                }//Column4

                Column{
                    width: (container.width - 7*padd) / 6
                    height: container.height - 2*padd
                    x: 5*padd + 4*table_column.width
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:gear_shift_tr
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Gear Shift T.R.:"
                        }
                        Text {
                            x: parent.width - gear_shift_tr.width + 5
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.gearShiftTimeRemaine
                        }

                    }//row1

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr1i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR1I (TC1):"
                        }
                        Text {
                            x: parent.width - lnr1i.width + 5
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR1I
                        }

                    }//row2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr2i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR2I (TC2):"
                        }
                        Text {
                            x: parent.width - lnr2i.width + 5
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR2I
                        }

                    }//row3

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr3i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR3I (TC3):"
                        }
                        Text {
                            x: parent.width - lnr3i.width + 5
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR3I
                        }

                    }//row4

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr4i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR4I (TC4):"
                        }
                        Text {
                            x: parent.width - lnr4i.width + 5
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR4I
                        }

                    }//row5

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr5i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR5I (Pbrake F.):"
                        }
                        Text {
                            x: parent.width - lnr5i.width + 27
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR5I
                        }

                    }//row6

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr6i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR6I (Pbrake R.):"
                        }
                        Text {
                            x: parent.width - lnr6i.width + 27
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR6I
                        }

                    }//row7

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr7i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR7I (TC pot):"
                        }
                        Text {
                            x: parent.width - lnr7i.width + 10
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR7I
                        }

                    }//row8

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:lnr8i
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "LNR8I (Gear pot):"
                        }
                        Text {
                            x: parent.width - lnr8i.width + 25
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.LNR8I
                        }

                    }//row9

                }//Column5

                Column{
                    width: (container.width - 7*padd) / 6
                    height: container.height - 2*padd
                    x: 6*padd + 5*table_column.width
                    y: padd
                    spacing: 2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:v_batt_dir
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "VBattDir:"
                        }
                        Text {
                            anchors.left: v_batt_dir.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.vBattDir
                        }

                    }//row1

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:v_batt_key
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "VBattKey:"
                        }
                        Text {
                            anchors.left: v_batt_key.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.vBattKey
                        }

                    }//row2

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:auto_acc_flag
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Auto acc:"
                        }
                        Text {
                            anchors.left: auto_acc_flag.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.auto_acc_flag
                        }

                    }//row3

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:datalog_on_off
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Datalog:"
                        }
                        Text {
                            anchors.left: datalog_on_off.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.datalog_on_off
                        }

                    }//row4

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:telemetry
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Telemetry:"
                        }
                        Text {
                            anchors.left: telemetry.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.telemetria_on_off
                        }

                    }//row5

                    Rectangle {

                        color: "#606060"
                        width: parent.width
                        height: row_height

                        Text {
                            id:debug
                            height: parent.height
                            width: text_width
                            color:"white"
                            font.pointSize: small_font_size
                            text: "Debug:"
                        }
                        Text {
                            anchors.left: debug.right
                            height: parent.height
                            color:"white"
                            font.pointSize: small_font_size
                            text: dashboardValues.debugMode
                        }

                    }//row6

                }//Column6


            }

        }//row2
    }
}
