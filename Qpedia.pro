#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T18:31:23
#
#-------------------------------------------------

QT       += core gui
QT += gui

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
    dbonxml.cpp \
    setcourses.cpp \
    mainview.cpp \
    user.cpp \
    teacher.cpp \
    student.cpp \
    noteview.cpp \
    definitionview.cpp \
    schemaview.cpp \
    sourceview.cpp

HEADERS  += mainwindow.h \
    note.h \
    dbio.h \
    definition.h \
    source.h \
    schema.h \
    course.h \
    list.h \
    dbonxml.h \
    setcourses.h \
    mainview.h \
    user.h \
    teacher.h \
    student.h \
    noteview.h \
    definitionview.h \
    schemaview.h \
    sourceview.h

FORMS    += mainwindow.ui
