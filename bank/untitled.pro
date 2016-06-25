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
    deleteaccount.cpp \
    bank_save.cpp \
    bank_withdraw.cpp \
    bank_query.cpp \
    fileexists.cpp \
    bank_databaseinit.cpp \
    bank_findaccount.cpp \
    cardlist.cpp \
    trades.cpp

HEADERS  += mainwindow.h\
            sqlite3.h \
    newaccount.h \
    bank.h \
    deleteaccount.h \
    fileexists.h \
    cardlist.h \
    trades.h

FORMS    += mainwindow.ui \
    newaccount.ui \
    deleteaccount.ui \
    cardlist.ui \
    trades.ui
