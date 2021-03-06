#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T19:17:09
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialCom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    availableports.cpp \
    kernelmodule.cpp \
    configuration.cpp

HEADERS  += mainwindow.h \
    availableports.h \
    kernelmodule.h \
    configuration.h

FORMS    += mainwindow.ui \
    availableports.ui \
    configuration.ui
