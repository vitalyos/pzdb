import QtQuick 2.0

Item {
    id: fieldRoot;
    property alias content: fieldListView.model;
    ListView {
        id: fieldListView;
        anchors.top: parent.top;
        anchors.left: parent.left;
        height: fieldRoot.height;
        delegate: Component {
            id: fdel;
            Item {
                id: fieldWrapperItem;
                height: fieldNameText.height;
                Text {
                    id: fieldNameText;
                    text: model.modelData.fieldName;
                    height: 25;
                }
            }
        }
    }
}

