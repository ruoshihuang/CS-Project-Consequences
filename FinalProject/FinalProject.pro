#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T20:16:43
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalProject
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    authorwindow.cpp \
    basewindow.cpp \
    binarychoicewindow.cpp \
    characterassignment.cpp \
    consequences.cpp \
    endwindow.cpp \
    fireendwindow.cpp \
    firegame.cpp \
    genderassignment.cpp \
    helpwindow.cpp \
    icecreamcup.cpp \
    icecreamgame.cpp \
    oneparticle.cpp \
    playstory.cpp \
    soundwindow.cpp \
    trinarychoicewindow.cpp \
    welcomewindow.cpp

HEADERS += \
        mainwindow.h \
    AssignmentChoice.h \
    authorwindow.h \
    basewindow.h \
    binarychoicewindow.h \
    characterassignment.h \
    Choice.h \
    consequences.h \
    endwindow.h \
    fireendwindow.h \
    firegame.h \
    genderassignment.h \
    helpwindow.h \
    icecreamcup.h \
    icecreamgame.h \
    oneparticle.h \
    playstory.h \
    soundwindow.h \
    StoryChoice.h \
    trinarychoicewindow.h \
    welcomewindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    A1.txt \
    B1.txt \
    C1.txt \
    HorrorF.txt \
    HorrorM.txt \
    moviechoice.txt \
    RomanceF.txt \
    RomanceM.txt \
    trinaryChoice.txt

RESOURCES += \
    images.qrc \
    sounds.qrc
