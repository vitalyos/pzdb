#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T07:55:13
#
#-------------------------------------------------

QT += core gui xml uitools
unix:!macx: LIBS += -lmongoclient -lboost_thread-mt -lboost_filesystem -lboost_program_options -lboost_system
QMAKE_CXXFLAGS += -std=gnu++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = frontend
TEMPLATE = app

SOURCES += main.cpp\
        PZDBMainWindow.cpp \
    DropDatabase.cpp \
    BaseCatalogEntity.cpp \
    DataBaseEntity.cpp \
    TableEntity.cpp \
    FieldEntity.cpp \
    DataBaseCatalogSerializer.cpp \
    PZDBController.cpp \
    MongoService.cpp \
    Tools.cpp \
    DataBaseStructureModel.cpp \
    IndexingService.cpp

HEADERS  += PZDBMainWindow.h \
    DropDatabase.h \
    Role.h \
    BaseCatalogEntity.h \
    DataBaseEntity.h \
    TableEntity.h \
    FieldEntity.h \
    Enumerator.h \
    DataBaseCatalogSerializer.h \
    PZDBController.h \
    MongoService.h \
    Tools.h \
    DataBaseStructureModel.h \
    IndexingService.h

FORMS    += PZDBMainWindow.ui \
    DropDatabase.ui

RESOURCES += \
    resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L/opt/mongodriver/lib/release/ -lmongoclient
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/mongodriver/lib/debug/ -lmongoclient
else:unix: LIBS += -L/opt/mongodriver/lib/ -lmongoclient

INCLUDEPATH += /opt/mongodriver/include
DEPENDPATH += /opt/mongodriver/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += /opt/mongodriver/lib/release/libmongoclient.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += /opt/mongodriver/lib/debug/libmongoclient.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += /opt/mongodriver/lib/release/mongoclient.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += /opt/mongodriver/lib/debug/mongoclient.lib
else:unix: PRE_TARGETDEPS += /opt/mongodriver/lib/libmongoclient.a
