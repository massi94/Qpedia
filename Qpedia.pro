#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T18:31:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qpedia
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    note.cpp \
    dbio.cpp \
    definition.cpp \
    source.cpp \
    schema.cpp \
    course.cpp \
    dbnoteio.cpp

HEADERS  += mainwindow.h \
    note.h \
    dbio.h \
    definition.h \
    source.h \
    schema.h \
    course.h \
    list.h \
    dbnoteio.h

FORMS    += mainwindow.ui
