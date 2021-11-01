TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Res/ResCBC1024.cpp \
    Res/ResCBC1536.cpp \
    Res/ResCBC512.cpp \
    Res/ResECB1024.cpp \
    Res/ResECB1536.cpp \
    Res/ResECB512.cpp

HEADERS += \
    Hex.h \
    Res/ResCBC1024.h \
    Res/ResCBC1536.h \
    Res/ResCBC512.h \
    Res/ResECB1024.h \
    Res/ResECB1536.h \
    Res/ResECB512.h \
    Res/_private/ResDeclarations.h
