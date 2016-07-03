TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Button.cpp \
    ButtonTest.cpp


LIBS += -L/usr/local/lib -lsfml-system-d -lsfml-window-d -lsfml-graphics-d
INCLUDEPATH +=/usr/local/include

HEADERS += \
    Button.hpp \
    ButtonTest.hpp

