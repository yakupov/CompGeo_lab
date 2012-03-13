QT       += core gui

TARGET = EarClipTriangulation
CONFIG   += console

TEMPLATE = app


SOURCES += src/algo/main.cpp \
    src/gui/MainWidget.cpp \
    src/gui/Drawer.cpp \
    src/algo/Graph.cpp \
    src/algo/EarClipper.cpp \
    src/algo/Point2D.cpp \
    src/algo/Vector2D.cpp

HEADERS += src/gui/MainWidget.h \
    src/gui/Drawer.h \
    src/algo/Graph.h \
    src/algo/EarClipper.h \
    src/algo/Point2D.h \
    src/algo/Vector2D.h
