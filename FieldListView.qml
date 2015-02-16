import QtQuick 2.0

Item {
    id: root;
    property alias content: fieldListView.model;
    height: fieldListView.height;
    ListView {
        id: fieldListView;
        anchors.fill: parent;
        height: content.length * 25;
        delegate: Component {
            id: fdel;
            Item {
                Text {
                    id: fieldNameText;
                    text: model.modelData.fieldName;
                    height: 25;
                }
                height: fieldNameText.height;
            }
        }
    }
}

