#-------------------------------------------------
#
# Project created by QtCreator 2018-06-02T22:03:53
#
#-------------------------------------------------

QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Keyboard
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


SOURCES += \
    keyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    combobox.cpp \
    sorting.cpp \
    table.cpp \
    diagram.cpp \

HEADERS += \
    keyboard.h \
    mainwindow.h \
    combobox.h \
    sorting.h \
    table.h \
    diagram.h \

FORMS += \
        mainwindow.ui \
    diagram.ui \
    sorting.ui

RESOURCES += \
    images.qrc

TRANSLATIONS += translation/Keyboard_en_US.ts \
                translation/Keyboard_ru_RU.ts \
                translation/Keyboard_es_ES.ts


DISTFILES += \
    keyboard.bat \
    tr/Keyboard_ru_RU.ts
