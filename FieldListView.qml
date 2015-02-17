import QtQuick 2.0

Item {
    id: fieldRoot;
    property alias content: fieldListView.model;
    height: fieldListView.count * 25;
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
                    text: model.modelData.fieldName
                          + (model.modelData.primary ? "(PK)" : "")
                          + ":" + model.modelData.length;
                    height: 25;
                }
            }
        }
    }
}

