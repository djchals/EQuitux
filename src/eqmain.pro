#-------------------------------------------------
#
# Project created by QtCreator 2020-10-25T20:47:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eqmain
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
        main.cpp \
        mainwindow.cpp \
    winselectrange.cpp \
    RangeSlider.cpp \
    threadcalculate.cpp

HEADERS += \
        mainwindow.h \
    header.h \
    get_value_combo.h \
    conv_pkr.h \
    calculate_all.h \
    boards.h \
    header.h \
    get_value_combo.h \
    get_value_combo.h \
    winselectrange.h \
    RangeSlider.h \
    init_cardmatrix.h \
    threadcalculate.h

FORMS += \
        mainwindow.ui \
    winselectrange.ui

LIBS += -L/usr/include -lpcre \
        -L/usr/include -lm \

RESOURCES += \
    resources.qrc
