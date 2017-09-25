#-------------------------------------------------
#
# Project created by QtCreator 2017-06-11T22:41:49
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visulization
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
            ../qcustomplot.cpp

HEADERS  += mainwindow.h \
    ../qcustomplot.h

FORMS    += mainwindow.ui

DISTFILES += \
    Cal_error.txt \
    datau.txt \
    datau1.txt \
    datau2.txt \
    datau3.txt \
    datau4.txt
