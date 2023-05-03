import QtQuick 2.15
import QtQuick.Window 2.15
import Model 1.0
import Controller 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: root
        width: window.width; height: window.height

        property var points: {
            [Qt.point(75.0, 0.0),
            Qt.point(150.0, 100.0),
            Qt.point(100.0, 200.0),
            Qt.point(50.0, 200.0),
            Qt.point(0.0, 100.0),
            Qt.point(75.0, 0.0)
            ]
        }
        property var handledPoints: {
            let newPoints = points.map((point) => Qt.point(point.x, point.y))

            const sequence = list
            for (let i = 0; i < sequence.length; ++i) {
                if (sequence[i] !== null) {
                    console.log(i, 'not null')
                    const vector = list[i].unit
                    for (let a = 0; a < newPoints.length; ++a) {
                        if (vector.index === (a % (newPoints.length - 1))) {
                            const point = vector.point
                            newPoints[a].x += point.x
                            newPoints[a].y += point.y
                        }
                    }
                } else {
                    console.log(i, 'null')
                }
            }
            return newPoints
        }

        property list<Unit> list
        VectorController {
            id: cntr
        }
        LinkSequence {
            id: link
        }


        Repeater {
            anchors.fill: parent
            model: root.handledPoints.length - 1
            Rectangle {
                id: circle
                x: root.handledPoints[index].x - height / 2; y: root.handledPoints[index].y - width/ 2
                width: 20; height: 20;
                radius: 20
                color: 'violet'
                MouseArea {
                    anchors.fill: circle
                    cursorShape: Qt.PointingHandCursor
                    property point pressedPoint; property point positionPoint
                    property var vector;  property var unit
                    onPressed: {
                        pressedPoint = circle.mapToItem(root, mouseX, mouseY)
                        vector = cntr.createVector()
                        vector.index = index
                        const unit = link.createUnit()
                        unit.type = 'vector'
                        unit.unit = vector
                        root.list.push(unit)
                    }
                    onPositionChanged: {
                        positionPoint = circle.mapToItem(root, mouseX, mouseY)
                        vector.point = Qt.point(positionPoint.x - pressedPoint.x,positionPoint.y - pressedPoint.y)
                    }
                }
            }
        }
    }
}
