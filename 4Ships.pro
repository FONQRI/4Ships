#-------------------------------------------------
#
# Project created by QtCreator 2018-03-27T22:31:55
#
#-------------------------------------------------

QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4Ships
TEMPLATE = app
CONFIG += c++17

include(src/FEngine/Graphics/graphics.pri)
include(src/FEngine/Core/core.pri)
#include(QtWebApp/templateengine/templateengine.pri)
#include(QtWebApp/logging/logging.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    src/Core/game.cpp \
    src/Core/gameview.cpp \
    src/GameObjects/chracter.cpp \
    src/GameObjects/bullet.cpp \
    src/UI/healthbar.cpp \
    src/UI/timerbar.cpp
HEADERS += \
    src/Core/game.h \
    src/Core/gameview.h \
    src/GameObjects/chracter.h \
    src/GameObjects/bullet.h \
    src/UI/healthbar.h \
    src/UI/timerbar.h
FORMS +=

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resource.qrc

