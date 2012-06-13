#-------------------------------------------------
#
# Project created by QtCreator 2012-06-12T09:05:57
#
#-------------------------------------------------

QT       += network opengl sql script scripttools svg xml xmlpatterns testlib core gui

TARGET = tst_testtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testtest.cpp \
    ../dialog.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../dialog.h
