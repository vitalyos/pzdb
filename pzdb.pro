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
