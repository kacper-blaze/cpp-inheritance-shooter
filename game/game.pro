QT += widgets multimedia multimediawidgets
CONFIG += c++23
TARGET = game_gui

SOURCES += \
    ../engine.cpp \
    ../enemy.cpp \
    ../object.cpp \
    ../stage.cpp \
    ../bullet.cpp \
    gameMain.cpp \
    mainwindow.cpp

HEADERS += \
    ../engine.h \
    ../enemy.h \
    ../object.h \
    ../stage.h \
    ../bullet.h \
    ../direction.h \
    ../position.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc

INCLUDEPATH += ..

# Fix line ending issues
QMAKE_CXXFLAGS += -Wall -Wextra
