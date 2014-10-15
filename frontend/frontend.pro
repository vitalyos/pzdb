#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T07:55:13
#
#-------------------------------------------------

QT += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = frontend
TEMPLATE = app

SOURCES += main.cpp\
        PZDBMainWindow.cpp \
    DataBaseXmlModel.cpp \
    DomItem.cpp \
    XmlEditor.cpp

HEADERS  += PZDBMainWindow.h \
    DataBaseXmlModel.h \
    DomItem.h \
    XmlEditor.h

FORMS    += PZDBMainWindow.ui
