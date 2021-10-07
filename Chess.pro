QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aiscene.cpp \
    bishop.cpp \
    cannon.cpp \
    chess.cpp \
    chessboard.cpp \
    chesschain.cpp \
    chessplace.cpp \
    chessscene.cpp \
    guard.cpp \
    jsonparser.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    mesh.cpp \
    pawn.cpp \
    recorder.cpp \
    rehearsalscene.cpp \
    resourcemanager.cpp \
    rook.cpp \
    searchengine.cpp

HEADERS += \
    aiscene.h \
    bishop.h \
    cannon.h \
    chess.h \
    chessboard.h \
    chesschain.h \
    chessfactory.h \
    chessplace.h \
    chessscene.h \
    guard.h \
    jsonparser.h \
    king.h \
    knight.h \
    mainwindow.h \
    mesh.h \
    pawn.h \
    recorder.h \
    rehearsalscene.h \
    resourcemanager.h \
    rook.h \
    searchengine.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/resource.qrc
