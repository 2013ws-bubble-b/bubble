
BIN_DIR = bin

INC_DIRS = /home_nfs/2013ws_bubble_b/kinect/openni/Platform/Linux-x86/Redist/Include /usr/include/ni

SRC_FILES = \
	main.cpp \
	SceneDrawer.cpp

EXE_NAME = bubbleXtreme

USED_LIBS += glut
USED_LIBS += OpenNI

LIB_DIRS += /usr/lib
include /home_nfs/2013ws_bubble_b/kinect/openni/Platform/Linux-x86/Redist/Samples/Build/Common/CommonCppMakefile

