#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T00:11:38
#
#-------------------------------------------------

QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graaveyard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    students.cpp \
    course.cpp \
    file.cpp \
    msgdialog.cpp \
    sortwindow.cpp \
    chartwindow.cpp

HEADERS  += mainwindow.h \
    students.h \
    course.h \
    file.h \
    msgdialog.h \
    sortwindow.h \
    chartwindow.h

FORMS    += mainwindow.ui \
    msgdialog.ui \
    sortwindow.ui \
    chartwindow.ui

DISTFILES +=
