# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = BOMLibrary
DESTDIR = ./Win32/Release
QT += core gui xml
CONFIG += release
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL QT_XML_LIB
DEFINES += BOMLIBRARY_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/release
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles

#RC_FILE = BOMLibrary.rc
include(BOMLibrary.pri)
