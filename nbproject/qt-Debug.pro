# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = FileArchiver
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += BlkTable.cpp FileArchiver.cpp FileRec.cpp GetCommentForm.cpp MainWindow.cpp MyTableModel.cpp RetrieveForm.cpp VersionInfoRecord.cpp VersionRec.cpp fns.cpp main.cpp
HEADERS += BlkTable.h FileArchiver.h FileRec.h GetCommentForm.h MainWindow.h MyTableModel.h RetrieveForm.h VersionInfoRecord.h VersionRec.h fns.h
FORMS += GetCommentForm.ui MainWindow.ui RetrieveForm.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += /usr/include/boost /usr/include/qt4 /usr/include/mongo 
LIBS += -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_serialization.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtGui.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtCore.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_system.so /usr/lib/libmongoclient.a -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_filesystem.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_thread.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_program_options.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_regex.so  
