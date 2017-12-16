#-------------------------------------------------
#
# Project created by QtCreator 2017-11-05T15:39:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEARCHAD
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_LFLAGS_RELEASE += -static -static-libgcc

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    studentnumberselector.cpp \
    attempt.cpp \
    gameoverdialog.cpp \
    helpdialog.cpp \
    congratulationsdialog.cpp \
    customdoublevalidator.cpp

HEADERS += \
        mainwindow.h \
    studentnumberselector.h \
    attempt.h \
    gameoverdialog.h \
    helpdialog.h \
    congratulationsdialog.h \
    customdoublevalidator.h

FORMS += \
        mainwindow.ui \
    studentnumberselector.ui \
    attempt.ui \
    gameoverdialog.ui \
    helpdialog.ui \
    congratulationsdialog.ui

CONFIG += c++11
