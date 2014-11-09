#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T07:55:13
#
#-------------------------------------------------

QT += core gui
QT += xml uitools
QMAKE_CXXFLAGS += -std=gnu++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = frontend
TEMPLATE = app

SOURCES += main.cpp\
        PZDBMainWindow.cpp \
    DropDatabase.cpp \
    BaseCatalogEntity.cpp \
    StreamOverloads.cpp \
    DataBaseEntity.cpp \
    TableEntity.cpp \
    FieldEntity.cpp \
    DataBaseCatalogSerializer.cpp

HEADERS  += PZDBMainWindow.h \
    DropDatabase.h \
    Role.h \
    BaseCatalogEntity.h \
    StreamOverloads.h \
    DataBaseEntity.h \
    TableEntity.h \
    FieldEntity.h \
    Enumerator.h \
    DataBaseCatalogSerializer.h

FORMS    += PZDBMainWindow.ui \
    DropDatabase.ui

RESOURCES += \
    resource.qrc
