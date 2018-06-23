TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-system -lsfml-window
SOURCES += \
    src/main.cpp \
    src/snake.cpp \
    src/game.cpp \
    src/config.cpp

HEADERS += \
    src/snake.h \
    src/game.h \
    src/config.h
