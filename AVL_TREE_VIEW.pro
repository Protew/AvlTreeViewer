######################################################################
# Automatically generated by qmake (2.01a) qui jun 7 18:18:27 2012
######################################################################

TEMPLATE  = app
LANGUAGE  = C++

QT += core gui
QT += opengl

INCLUDEPATH += "C:\MinGW\mingw32\include"

LIBS   += -lopengl32
LIBS   += -lglu32

LIBS += -L"C:\Users\protew\Downloads\freeglut-MinGW-3.0.0-1.mp\freeglut\lib" -llibfreeglut


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AvlTreeViewer

# Input
HEADERS += AvlNode.h \
           AvlTree.h \
           GLWorldViewer.h \
           GLWorldWidget.h \
           MainWindow.h \
           RotationDisplay.h
SOURCES += AvlNode.cpp \
           AvlTree.cpp \
           GLWorldViewer.cpp \
           GLWorldWidget.cpp \
           main.cpp \
           MainWindow.cpp \
           RotationDisplay.cpp

RESOURCES += \
    setting.qrc