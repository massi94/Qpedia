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


SOURCES += model/course.cpp \
    model/dbio.cpp \
    model/dbonxml.cpp \
    model/definition.cpp \
    model/list.cpp \
    model/note.cpp \
    model/schema.cpp \
    model/setcourses.cpp \
    model/source.cpp \
    model/student.cpp \
    model/teacher.cpp \
    model/user.cpp \
    view/definitionview.cpp \
    view/mainview.cpp \
    view/mainwindow.cpp \
    view/noteview.cpp \
    view/schemaview.cpp \
    view/sourceview.cpp \
    main.cpp

HEADERS  += model/course.h \
    model/dbio.h \
    model/dbonxml.h \
    model/definition.h \
    model/list.h \
    model/note.h \
    model/schema.h \
    model/setcourses.h \
    model/source.h \
    model/student.h \
    model/teacher.h \
    model/user.h \
    view/definitionview.h \
    view/mainview.h \
    view/mainwindow.h \
    view/noteview.h \
    view/schemaview.h \
    view/sourceview.h

