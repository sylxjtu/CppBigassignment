#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T18:15:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        bank.cpp\
        sqlite3.c \
    newaccount.cpp \
    deleteaccount.cpp

HEADERS  += mainwindow.h\
            sqlite3.h \
    newaccount.h \
    bank.h \
    deleteaccount.h

FORMS    += mainwindow.ui \
    newaccount.ui \
    deleteaccount.ui
