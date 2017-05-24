#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T13:18:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LegendofWesteros
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    AbstractArmyFactory.cpp \
    Army.cpp \
    Baratheon.cpp \
    ConcreteArmyFactory.cpp \
    Greyjoy.cpp \
    Lannister.cpp \
    Map.cpp \
    Stark.cpp \
    Targaryen.cpp \
    Territory.cpp \
    WhiteWalkers.cpp \
    ChooseWindow.cpp \
    PlayWindow.cpp \
    Troop.cpp

HEADERS  += mainwindow.h \
    AbstractArmyFactory.h \
    Army.h \
    Baratheon.h \
    ConcreteArmyFactory.h \
    Greyjoy.h \
    Lannister.h \
    Map.h \
    Stark.h \
    Targaryen.h \
    Territory.h \
    WhiteWalkers.h \
    ChooseWindow.h \
    PlayWindow.h \
    Troop.h

FORMS    += mainwindow.ui \
    choosewindow.ui \
    playwindow.ui
