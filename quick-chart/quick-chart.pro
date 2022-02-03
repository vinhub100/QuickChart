#-------------------------------------------------
#
# Project created by QtCreator 2021-10-09T13:12:52
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quick-chart
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


DBUS_INTERFACES += servicedemon.xml


SOURCES += \
        chartable.cpp \
        chartablewidget.cpp \
        favourite.cpp \
        flowlayout.cpp \
        frontend.cpp \
        leftchartablebutton.cpp \
        main.cpp \
        qc_frame.cpp \
        recent.cpp

HEADERS += \
    chartable.h \
    chartablewidget.h \
    common.h \
    favourite.h \
    flowlayout.h \
    frontend.h \
    leftchartablebutton.h \
    qc_frame.h \
    recent.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    servicedemon.xml
    
