QT       += core gui
QT	 += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPedia
TEMPLATE = app
CONFIG += C++11

SOURCES += main.cpp\
    note.cpp \
    definition.cpp \
    source.cpp \
    user.cpp \
    usrcourse.cpp \
    dbonxml.cpp \
    viewlogin.cpp \
    mainwidget.cpp \
    viewreg.cpp \
    viewdefinition.cpp \
    viewsource.cpp \
    viewusercourse.cpp \
    viewuserdata.cpp \
    controllerusrcourse.cpp \
    controllerlogin.cpp \
    usrstudent.cpp \
    viewuserstudent.cpp \
    viewcourselist.cpp \
    controllerusrstudent.cpp

HEADERS  += \
    note.h \
    definition.h \
    source.h \
    user.h \
    usrcourse.h \
    dbonxml.h \
    mainwidget.h \
    viewlogin.h \
    viewreg.h \
    viewdefinition.h \
    viewsource.h \
    viewusercourse.h \
    viewuserdata.h \
    controllerusrcourse.h \
    controllerlogin.h \
    usrstudent.h \
    viewuserstudent.h \
    viewcourselist.h \
    controllerusrstudent.h


FORMS    +=

