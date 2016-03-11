QT += core
QT -= gui

CONFIG += c++11

TARGET = Inter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    interp.cpp

HEADERS += \
    interp.h
