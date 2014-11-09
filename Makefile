#############################################################################
# Makefile for building: Babel
# Generated by qmake (2.01a) (Qt 4.8.5) on: Sun Nov 9 22:31:07 2014
# Project:  sans_titre.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile sans_titre.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/default -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include/QtXml -I/usr/include -IIncludes -I/usr/local/include/opencv2 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib64 -lopus -ljack -lasound -lrt -lm -lportaudio -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann -lopencv_nonfree -lQtXml -L/usr/lib64 -lQtGui -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

OBJECTS_DIR   = ./

####### Files

SOURCES       = Gui/main.cpp \
		Gui/Connection.cpp \
		Gui/Subscribe.cpp \
		Gui/Home.cpp \
		Modules/Network/UClientInfo.cpp \
		Modules/Network/UNetwork.cpp \
		Modules/Opus/BabelEncoder.cpp \
		Modules/PortAudio/BabelSound.cpp \
		Modules/OpenCV/OpenCV.cpp \
		Modules/Network/WNetwork.cpp \
		Modules/Network/WClientInfo.cpp moc_Connection.cpp \
		moc_Subscribe.cpp \
		moc_Home.cpp \
		moc_OpenCV.cpp
OBJECTS       = main.o \
		Connection.o \
		Subscribe.o \
		Home.o \
		UClientInfo.o \
		UNetwork.o \
		BabelEncoder.o \
		BabelSound.o \
		OpenCV.o \
		WNetwork.o \
		WClientInfo.o \
		moc_Connection.o \
		moc_Subscribe.o \
		moc_Home.o \
		moc_OpenCV.o
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
		/usr/share/qt4/mkspecs/features/release.prf \
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
		sans_titre.pro
QMAKE_TARGET  = Babel
DESTDIR       = 
TARGET        = Babel

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

all: Makefile $(TARGET)

$(TARGET): ui_Connection.h ui_Subscribe.h ui_Home.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: sans_titre.pro  /usr/share/qt4/mkspecs/default/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
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
		/usr/share/qt4/mkspecs/features/release.prf \
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
		/usr/lib64/libQtXml.prl \
		/usr/lib64/libQtCore.prl \
		/usr/lib64/libQtGui.prl
	$(QMAKE) -o Makefile sans_titre.pro
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
/usr/share/qt4/mkspecs/features/release.prf:
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
/usr/lib64/libQtXml.prl:
/usr/lib64/libQtCore.prl:
/usr/lib64/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile sans_titre.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Babel1.0.0 || $(MKDIR) .tmp/Babel1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Babel1.0.0/ && $(COPY_FILE) --parents Includes/Connection.hh Includes/Subscribe.hh Includes/Home.hh Includes/IGui.hh Includes/BabelEncoder.hh Includes/IBabelEncoder.hh Includes/Network.hh Includes/BabelSound.hh Includes/IBabelSound.hh Includes/IModule.hh Includes/INetwork.hh Includes/UClientInfo.hh Includes/OpenCV.hh Includes/WClientInfo.hh .tmp/Babel1.0.0/ && $(COPY_FILE) --parents Gui/main.cpp Gui/Connection.cpp Gui/Subscribe.cpp Gui/Home.cpp Modules/Network/UClientInfo.cpp Modules/Network/UNetwork.cpp Modules/Opus/BabelEncoder.cpp Modules/PortAudio/BabelSound.cpp Modules/OpenCV/OpenCV.cpp Modules/Network/WNetwork.cpp Modules/Network/WClientInfo.cpp .tmp/Babel1.0.0/ && $(COPY_FILE) --parents Gui/Ui/Connection.ui Gui/Ui/Subscribe.ui Gui/Ui/Home.ui .tmp/Babel1.0.0/ && (cd `dirname .tmp/Babel1.0.0` && $(TAR) Babel1.0.0.tar Babel1.0.0 && $(COMPRESS) Babel1.0.0.tar) && $(MOVE) `dirname .tmp/Babel1.0.0`/Babel1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Babel1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_Connection.cpp moc_Subscribe.cpp moc_Home.cpp moc_OpenCV.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_Connection.cpp moc_Subscribe.cpp moc_Home.cpp moc_OpenCV.cpp
moc_Connection.cpp: Includes/IGui.hh \
		Includes/Connection.hh
	/usr/bin/moc $(DEFINES) $(INCPATH) Includes/Connection.hh -o moc_Connection.cpp

moc_Subscribe.cpp: Includes/IGui.hh \
		Includes/Subscribe.hh
	/usr/bin/moc $(DEFINES) $(INCPATH) Includes/Subscribe.hh -o moc_Subscribe.cpp

moc_Home.cpp: Includes/Network.hh \
		Includes/INetwork.hh \
		Includes/WClientInfo.hh \
		Includes/UClientInfo.hh \
		Includes/BabelSound.hh \
		Includes/IBabelSound.hh \
		Includes/BabelEncoder.hh \
		Includes/IBabelEncoder.hh \
		Includes/OpenCV.hh \
		Includes/IModule.hh \
		Includes/Home.hh
	/usr/bin/moc $(DEFINES) $(INCPATH) Includes/Home.hh -o moc_Home.cpp

moc_OpenCV.cpp: Includes/IModule.hh \
		Includes/OpenCV.hh
	/usr/bin/moc $(DEFINES) $(INCPATH) Includes/OpenCV.hh -o moc_OpenCV.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_Connection.h ui_Subscribe.h ui_Home.h
compiler_uic_clean:
	-$(DEL_FILE) ui_Connection.h ui_Subscribe.h ui_Home.h
ui_Connection.h: Gui/Ui/Connection.ui
	/usr/bin/uic Gui/Ui/Connection.ui -o ui_Connection.h

ui_Subscribe.h: Gui/Ui/Subscribe.ui
	/usr/bin/uic Gui/Ui/Subscribe.ui -o ui_Subscribe.h

ui_Home.h: Gui/Ui/Home.ui
	/usr/bin/uic Gui/Ui/Home.ui -o ui_Home.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: Gui/main.cpp Includes/IGui.hh \
		Includes/Connection.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o Gui/main.cpp

Connection.o: Gui/Connection.cpp Includes/IGui.hh \
		Includes/Connection.hh \
		Includes/Subscribe.hh \
		Includes/Home.hh \
		Includes/Network.hh \
		Includes/INetwork.hh \
		Includes/WClientInfo.hh \
		Includes/UClientInfo.hh \
		Includes/BabelSound.hh \
		Includes/IBabelSound.hh \
		Includes/BabelEncoder.hh \
		Includes/IBabelEncoder.hh \
		Includes/OpenCV.hh \
		Includes/IModule.hh \
		ui_Connection.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Connection.o Gui/Connection.cpp

Subscribe.o: Gui/Subscribe.cpp Includes/Subscribe.hh \
		Includes/IGui.hh \
		Includes/Connection.hh \
		ui_Subscribe.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Subscribe.o Gui/Subscribe.cpp

Home.o: Gui/Home.cpp Includes/Home.hh \
		Includes/Network.hh \
		Includes/INetwork.hh \
		Includes/WClientInfo.hh \
		Includes/UClientInfo.hh \
		Includes/BabelSound.hh \
		Includes/IBabelSound.hh \
		Includes/BabelEncoder.hh \
		Includes/IBabelEncoder.hh \
		Includes/OpenCV.hh \
		Includes/IModule.hh \
		ui_Home.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Home.o Gui/Home.cpp

UClientInfo.o: Modules/Network/UClientInfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o UClientInfo.o Modules/Network/UClientInfo.cpp

UNetwork.o: Modules/Network/UNetwork.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o UNetwork.o Modules/Network/UNetwork.cpp

BabelEncoder.o: Modules/Opus/BabelEncoder.cpp Includes/BabelEncoder.hh \
		Includes/IBabelEncoder.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BabelEncoder.o Modules/Opus/BabelEncoder.cpp

BabelSound.o: Modules/PortAudio/BabelSound.cpp Includes/BabelSound.hh \
		Includes/IBabelSound.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BabelSound.o Modules/PortAudio/BabelSound.cpp

OpenCV.o: Modules/OpenCV/OpenCV.cpp Includes/OpenCV.hh \
		Includes/IModule.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OpenCV.o Modules/OpenCV/OpenCV.cpp

WNetwork.o: Modules/Network/WNetwork.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o WNetwork.o Modules/Network/WNetwork.cpp

WClientInfo.o: Modules/Network/WClientInfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o WClientInfo.o Modules/Network/WClientInfo.cpp

moc_Connection.o: moc_Connection.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Connection.o moc_Connection.cpp

moc_Subscribe.o: moc_Subscribe.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Subscribe.o moc_Subscribe.cpp

moc_Home.o: moc_Home.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Home.o moc_Home.cpp

moc_OpenCV.o: moc_OpenCV.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_OpenCV.o moc_OpenCV.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

