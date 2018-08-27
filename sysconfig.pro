#-------------------------------------------------
#
# Project created by QtCreator 2017-02-20T15:34:08
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sysconfig
TEMPLATE = app
DESTDIR = ../bin_win
INCLUDEPATH += \
              ../include \

SOURCES += main.cpp\
    #hxml.cpp \
    hnetset.cpp \
    hfunset.cpp \
    hnormalset.cpp \
    hformatset.cpp \
    hsysconfigdlg.cpp \
    #hsysconfig.cpp \
    hticketnoset.cpp \
    hotherset.cpp \
    hsyspathset.cpp

HEADERS  += \
    #hxml.h \
    hnetset.h \
    hfunset.h \
    hnormalset.h \
    hformatset.h \
    #sysconfigapi.h \
    hsysconfigdlg.h \
    #hsysconfig.h \
    hticketnoset.h \
    hotherset.h \
    hsyspathset.h

FORMS    += sysconfig.ui \
    normalset.ui \
    netset.ui \
    funset.ui \
    formatset.ui \
    otherset.ui \
    ticketnoset.ui \
    syspathset.ui

#LIBS += -L../lib
unix{
    LIBS += -L ../lib -lH5ConfigHelp
    #UI_DIR=	.ui
    #MOC_DIR= .moc
    #OBJECTS_DIR= .obj
}


win32{
    LIBS += \
           ../lib/H5ConfigHelp.lib
    UI_DIR = temp/ui
    MOC_DIR = temp/moc
    OBJECTS_DIR	= temp/obj
}



QT += xml
