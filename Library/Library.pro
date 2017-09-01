#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T19:34:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    secdialog.cpp \
    userexit.cpp \
    booksearch.cpp \
    booksearchbyauthor.cpp \
    userinfosearch.cpp \
    bookborrow.cpp \
    bookreturn.cpp \
    userregister.cpp \
    userdelete.cpp \
    bookadd.cpp \
    bookdelete.cpp \
    passwordchange.cpp \
    changebookinfo.cpp

HEADERS  += mainwindow.h \
    secdialog.h \
    userexit.h \
    booksearch.h \
    booksearchbyauthor.h \
    userinfosearch.h \
    bookborrow.h \
    bookreturn.h \
    userregister.h \
    userdelete.h \
    bookadd.h \
    bookdelete.h \
    passwordchange.h \
    changebookinfo.h

FORMS    += mainwindow.ui \
    secdialog.ui \
    userexit.ui \
    booksearch.ui \
    booksearchbyauthor.ui \
    userinfosearch.ui \
    bookborrow.ui \
    bookreturn.ui \
    userregister.ui \
    userdelete.ui \
    bookadd.ui \
    bookdelete.ui \
    passwordchange.ui \
    changebookinfo.ui

QMAKE_CXXFLAGS += -std=gnu++11

RESOURCES +=
