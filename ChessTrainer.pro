QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess Trainer 1.0
TEMPLATE = app


SOURCES += main.cpp \
    chesspiece/bishop.cpp \
    chesspiece/king.cpp \
    chesspiece/knight.cpp \
    chesspiece/pawn.cpp \
    chesspiece/queen.cpp \
    chesspiece/rook.cpp \
    game.cpp \
    chessbox.cpp \
    chessboard.cpp \
    chesspiece.cpp \
    button.cpp \
    rules/rules.cpp

HEADERS  += \
    chesspiece/bishop.h \
    chesspiece/king.h \
    chesspiece/knight.h \
    chesspiece/pawn.h \
    chesspiece/queen.h \
    chesspiece/rook.h \
    game.h \
    chessbox.h \
    chessboard.h \
    chesspiece.h \
    button.h \
    rules/rules.h

FORMS    += \
    rules/rules.ui

RESOURCES += \
    resource.qrc
