import QtQuick 2.4
import QtQuick.Window 2.0

Window {
    width: 1280
    height: 720

    Item {
        id: dbStructure
        x: 8
        y: 8
        width: 358
        height: 704
    }

    Item {
        id: item2
        x: 406
        y: 8
        width: 858
        height: 704
    }

    Flickable {
        id: flickable1
        x: 400
        y: 210
        width: 300
        height: 300
    }
}

