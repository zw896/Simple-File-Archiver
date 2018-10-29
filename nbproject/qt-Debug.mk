#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/FileArchiver
# Generated by qmake (2.01a) (Qt 4.8.6) on: Wed Oct 7 08:43:11 2015
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/include/boost -I/usr/include/qt4 -I/usr/include/mongo -I. -I. -Inbproject -I.
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_serialization.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtGui.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libQtCore.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_system.so /usr/lib/libmongoclient.a -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_filesystem.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_thread.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_program_options.so -Wl,-rpath,/usr/lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu/libboost_regex.so -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = BlkTable.cpp \
		FileArchiver.cpp \
		FileRec.cpp \
		GetCommentForm.cpp \
		MainWindow.cpp \
		MyTableModel.cpp \
		RetrieveForm.cpp \
		VersionInfoRecord.cpp \
		VersionRec.cpp \
		fns.cpp \
		main.cpp moc_GetCommentForm.cpp \
		moc_MainWindow.cpp \
		moc_MyTableModel.cpp \
		moc_RetrieveForm.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/BlkTable.o \
		build/Debug/GNU-Linux-x86/FileArchiver.o \
		build/Debug/GNU-Linux-x86/FileRec.o \
		build/Debug/GNU-Linux-x86/GetCommentForm.o \
		build/Debug/GNU-Linux-x86/MainWindow.o \
		build/Debug/GNU-Linux-x86/MyTableModel.o \
		build/Debug/GNU-Linux-x86/RetrieveForm.o \
		build/Debug/GNU-Linux-x86/VersionInfoRecord.o \
		build/Debug/GNU-Linux-x86/VersionRec.o \
		build/Debug/GNU-Linux-x86/fns.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/moc_GetCommentForm.o \
		build/Debug/GNU-Linux-x86/moc_MainWindow.o \
		build/Debug/GNU-Linux-x86/moc_MyTableModel.o \
		build/Debug/GNU-Linux-x86/moc_RetrieveForm.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = FileArchiver
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/FileArchiver

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_GetCommentForm.h ui_MainWindow.h ui_RetrieveForm.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Debug/GNU-Linux-x86/FileArchiver1.0.0 || $(MKDIR) build/Debug/GNU-Linux-x86/FileArchiver1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Debug/GNU-Linux-x86/FileArchiver1.0.0/ && $(COPY_FILE) --parents BlkTable.h FileArchiver.h FileRec.h GetCommentForm.h MainWindow.h MyTableModel.h RetrieveForm.h VersionInfoRecord.h VersionRec.h fns.h build/Debug/GNU-Linux-x86/FileArchiver1.0.0/ && $(COPY_FILE) --parents BlkTable.cpp FileArchiver.cpp FileRec.cpp GetCommentForm.cpp MainWindow.cpp MyTableModel.cpp RetrieveForm.cpp VersionInfoRecord.cpp VersionRec.cpp fns.cpp main.cpp build/Debug/GNU-Linux-x86/FileArchiver1.0.0/ && $(COPY_FILE) --parents GetCommentForm.ui MainWindow.ui RetrieveForm.ui build/Debug/GNU-Linux-x86/FileArchiver1.0.0/ && (cd `dirname build/Debug/GNU-Linux-x86/FileArchiver1.0.0` && $(TAR) FileArchiver1.0.0.tar FileArchiver1.0.0 && $(COMPRESS) FileArchiver1.0.0.tar) && $(MOVE) `dirname build/Debug/GNU-Linux-x86/FileArchiver1.0.0`/FileArchiver1.0.0.tar.gz . && $(DEL_FILE) -r build/Debug/GNU-Linux-x86/FileArchiver1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_GetCommentForm.cpp moc_MainWindow.cpp moc_MyTableModel.cpp moc_RetrieveForm.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_GetCommentForm.cpp moc_MainWindow.cpp moc_MyTableModel.cpp moc_RetrieveForm.cpp
moc_GetCommentForm.cpp: FileRec.h \
		fns.h \
		ui_GetCommentForm.h \
		GetCommentForm.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) GetCommentForm.h -o moc_GetCommentForm.cpp

moc_MainWindow.cpp: ui_MainWindow.h \
		FileArchiver.h \
		FileRec.h \
		fns.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h \
		MyTableModel.h \
		GetCommentForm.h \
		ui_GetCommentForm.h \
		RetrieveForm.h \
		ui_RetrieveForm.h \
		MainWindow.h \
		MainWindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) MainWindow.h -o moc_MainWindow.cpp

moc_MyTableModel.cpp: FileRec.h \
		fns.h \
		VersionInfoRecord.h \
		MyTableModel.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) MyTableModel.h -o moc_MyTableModel.cpp

moc_RetrieveForm.cpp: ui_RetrieveForm.h \
		MainWindow.h \
		ui_MainWindow.h \
		FileArchiver.h \
		FileRec.h \
		fns.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h \
		MyTableModel.h \
		GetCommentForm.h \
		ui_GetCommentForm.h \
		RetrieveForm.h \
		RetrieveForm.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) RetrieveForm.h -o moc_RetrieveForm.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_GetCommentForm.h ui_MainWindow.h ui_RetrieveForm.h
compiler_uic_clean:
	-$(DEL_FILE) ui_GetCommentForm.h ui_MainWindow.h ui_RetrieveForm.h
ui_GetCommentForm.h: GetCommentForm.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic GetCommentForm.ui -o ui_GetCommentForm.h

ui_MainWindow.h: MainWindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic MainWindow.ui -o ui_MainWindow.h

ui_RetrieveForm.h: RetrieveForm.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic RetrieveForm.ui -o ui_RetrieveForm.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/BlkTable.o: BlkTable.cpp BlkTable.h \
		fns.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/BlkTable.o BlkTable.cpp

build/Debug/GNU-Linux-x86/FileArchiver.o: FileArchiver.cpp FileArchiver.h \
		FileRec.h \
		fns.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/FileArchiver.o FileArchiver.cpp

build/Debug/GNU-Linux-x86/FileRec.o: FileRec.cpp FileRec.h \
		fns.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/FileRec.o FileRec.cpp

build/Debug/GNU-Linux-x86/GetCommentForm.o: GetCommentForm.cpp MainWindow.h \
		ui_MainWindow.h \
		FileArchiver.h \
		FileRec.h \
		fns.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h \
		MyTableModel.h \
		GetCommentForm.h \
		ui_GetCommentForm.h \
		RetrieveForm.h \
		ui_RetrieveForm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/GetCommentForm.o GetCommentForm.cpp

build/Debug/GNU-Linux-x86/MainWindow.o: MainWindow.cpp MainWindow.h \
		ui_MainWindow.h \
		FileArchiver.h \
		FileRec.h \
		fns.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h \
		MyTableModel.h \
		GetCommentForm.h \
		ui_GetCommentForm.h \
		RetrieveForm.h \
		ui_RetrieveForm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/MainWindow.o MainWindow.cpp

build/Debug/GNU-Linux-x86/MyTableModel.o: MyTableModel.cpp MyTableModel.h \
		FileRec.h \
		fns.h \
		VersionInfoRecord.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/MyTableModel.o MyTableModel.cpp

build/Debug/GNU-Linux-x86/RetrieveForm.o: RetrieveForm.cpp RetrieveForm.h \
		ui_RetrieveForm.h \
		MainWindow.h \
		ui_MainWindow.h \
		FileArchiver.h \
		FileRec.h \
		fns.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h \
		MyTableModel.h \
		GetCommentForm.h \
		ui_GetCommentForm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/RetrieveForm.o RetrieveForm.cpp

build/Debug/GNU-Linux-x86/VersionInfoRecord.o: VersionInfoRecord.cpp VersionInfoRecord.h \
		fns.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/VersionInfoRecord.o VersionInfoRecord.cpp

build/Debug/GNU-Linux-x86/VersionRec.o: VersionRec.cpp VersionRec.h \
		fns.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/VersionRec.o VersionRec.cpp

build/Debug/GNU-Linux-x86/fns.o: fns.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/fns.o fns.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp GetCommentForm.h \
		FileRec.h \
		fns.h \
		ui_GetCommentForm.h \
		FileArchiver.h \
		VersionRec.h \
		BlkTable.h \
		VersionInfoRecord.h \
		MainWindow.h \
		ui_MainWindow.h \
		MyTableModel.h \
		RetrieveForm.h \
		ui_RetrieveForm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/moc_GetCommentForm.o: moc_GetCommentForm.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_GetCommentForm.o moc_GetCommentForm.cpp

build/Debug/GNU-Linux-x86/moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_MainWindow.o moc_MainWindow.cpp

build/Debug/GNU-Linux-x86/moc_MyTableModel.o: moc_MyTableModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_MyTableModel.o moc_MyTableModel.cpp

build/Debug/GNU-Linux-x86/moc_RetrieveForm.o: moc_RetrieveForm.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_RetrieveForm.o moc_RetrieveForm.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

