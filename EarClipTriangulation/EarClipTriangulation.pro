QT       += core gui

TARGET = EarClipTriangulation
CONFIG   += console

TEMPLATE = app


SOURCES += src/algo/main.cpp \
    src/algo/EarClipper.cpp \
    src/gui/MainWidget.cpp \
    src/gui/Drawer.cpp \
    src/objects/Point2D.cpp \
    src/objects/Vector2D.cpp \
    src/objects/Triangle2D.cpp

HEADERS += src/algo/EarClipper.h \
    src/gui/MainWidget.h \
    src/gui/Drawer.h \
    src/objects/Graph.h \
    src/objects/Point2D.h \
    src/objects/Vector2D.h \
    src/objects/Triangle2D.h \
    src/algo/PolygonInputParser.h
