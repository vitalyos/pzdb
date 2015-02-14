#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T07:55:13
#
#-------------------------------------------------

TEMPLATE = app

QT += qml quick core

RESOURCES += qml.qrc

#QMAKE_CXXFLAGS += -std=gnu++0x


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)


TARGET = PZDB

SOURCES += main.cpp\
    DataBaseEntity.cpp \
    TableEntity.cpp \
    FieldEntity.cpp \
    DataBaseCatalogSerializer.cpp \
    PZDBController.cpp \
    MongoService.cpp \
    Tools.cpp \
    IndexingService.cpp \
    databasemodel.cpp \
    DataBaseQueryResultModel.cpp

HEADERS  += \
    Role.h \
    DataBaseEntity.h \
    TableEntity.h \
    FieldEntity.h \
    Enumerator.h \
    DataBaseCatalogSerializer.h \
    PZDBController.h \
    MongoService.h \
    Tools.h \
    IndexingService.h \
    databasemodel.h \
    DataBaseQueryResultModel.hpp

unix:!macx: LIBS += -L$$PWD/../../tools/mongodriver/lib/ -lmongoclient -lboost_thread -lboost_system -lboost_regex -lssl -lcrypto -pthread -lboost_filesystem -lboost_program_options

INCLUDEPATH += $$PWD/../../tools/mongodriver/include
DEPENDPATH += $$PWD/../../tools/mongodriver/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../tools/mongodriver/lib/libmongoclient.a
