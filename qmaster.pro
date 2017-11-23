QT  += core gui
QT  += serialbus
QT  += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qmaster
TEMPLATE = app

DESTDIR = ../bin

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ./include

HEADERS += $$files(./include/*.h) \
    include/request.h
SOURCES += $$files(./src/*.cpp)
FORMS += $$files(./forms/*.ui)
