# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux-x86
TARGET = FileArchiver
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += BlkTable.cpp FileArchiver.cpp FileRec.cpp GetCommentForm.cpp MainWindow.cpp MyTableModel.cpp RetrieveForm.cpp VersionInfoRecord.cpp VersionRec.cpp fns.cpp main.cpp
HEADERS += BlkTable.h FileArchiver.h FileRec.h GetCommentForm.h MainWindow.h MyTableModel.h RetrieveForm.h VersionInfoRecord.h VersionRec.h fns.h
FORMS += GetCommentForm.ui MainWindow.ui RetrieveForm.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`  
