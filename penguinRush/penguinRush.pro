TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    GameManger.cpp \
    Penguin.cpp \
    Background.cpp \
    Obstacle.cpp \
    ObstacleManager.cpp

HEADERS += \
    GameManger.hpp \
    Penguin.hpp \
    Background.hpp \
    Obstacle.hpp \
    Constants.hpp \
    ObstacleManager.hpp

