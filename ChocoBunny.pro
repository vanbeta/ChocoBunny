TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt


HEADERS +=            \
    src/BlackWorker.h \

SOURCES +=              \
    src/main.cpp        \
    src/BlackWorker.cpp \

LIBS += -lpthread
