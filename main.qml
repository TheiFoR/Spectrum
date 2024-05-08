import QtQuick
import UniversalChart 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    UniversalChart{
        id: customPlot
        anchors.fill: parent

        plotAreaLeftMargin: 140
        plotAreaTopMargin: 140
        plotAreaRightMargin: 140
        plotAreaBottomMargin: 140
    }
}
