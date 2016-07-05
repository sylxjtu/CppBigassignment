#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T23:31:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = phone
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keyboard.cpp \
    screen.cpp \
    chip.cpp \
    mobile.cpp \
    basestation.cpp \
    drawable.cpp \
    phone.cpp \
    pda.cpp \
    laptop.cpp

HEADERS  += mainwindow.h \
    keyboard.h \
    screen.h \
    chip.h \
    mobile.h \
    basestation.h \
    drawable.h \
    phone.h \
    basepath.h \
    pda.h \
    laptop.h

FORMS    += mainwindow.ui
