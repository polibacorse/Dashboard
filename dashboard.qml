import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

Window {
    id: root
    visible: true

    width: 1024
    height: 600

    color: "#161616"

    Canvas {
        anchors.fill: parent

        onPaint: {
            function createArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, startAngle, endAngle) {
                ctx.beginPath();
                ctx.strokeStyle = "white";
                ctx.lineWidth = 2;
                ctx.arc(centreX, centreY, innerRadious, -startAngle, -endAngle, true);
                ctx.arc(centreX, centreY, outerRadious, -endAngle, -startAngle, false);
                ctx.lineTo(centreX + innerRadious * Math.cos(startAngle), centreY - innerRadious * Math.sin(startAngle));
                ctx.stroke();
            }

            function fillArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, startAngle, endAngle, percentage) {
                endAngle = endAngle;

                ctx.beginPath();
                ctx.fillStyle = "green";
                ctx.arc(centreX, centreY, innerRadious+3, -startAngle, -endAngle, true);
                ctx.arc(centreX, centreY, outerRadious-3, -endAngle, -startAngle, false);
                ctx.lineTo(centreX + innerRadious * Math.cos(startAngle), centreY - innerRadious * Math.sin(startAngle));
                ctx.fill();
            }

            var ctx = getContext("2d");
            ctx.reset();

            var centreX = width / 2;
            var centreY = height / 2;

            var innerRadious = width / 4;
            var outerRadious = width / 3.5;

            createArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, 0.1745, 0.8726);
            createArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, 2.2689, 2.9670);
            createArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, 3.2288, 3.9269);
            createArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, 5.4977, 6.1959);

            fillArcIndicator(ctx, centreX, centreY, innerRadious, outerRadious, 0.1745, 0.8726, 50);
        }
    }

    Item {
        id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent

        Row {
            id: gaugeRow
            spacing: container.width * 0.2
            anchors.centerIn: parent

            Item {
                width: height
                height: container.height * 0.25 - gaugeRow.spacing
                anchors.verticalCenter: parent.verticalCenter

                CircularGauge {
                    id: tachometer
                    value: dashboardValues.rpm
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    maximumValue: 230

                    width: height
                    height: container.height * 0.8

                    style: DashboardGaugeStyle {}
                }
            }
        }
    }


}
