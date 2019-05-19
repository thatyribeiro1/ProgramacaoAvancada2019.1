TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    figurageometrica.cpp \
    sculptor.cpp \
    putvoxel.cpp \
    cutvoxel.cpp \
    putbox.cpp \
    cutbox.cpp \
    putsphere.cpp \
    cutsphere.cpp \
    putellipsoid.cpp \
    cutellipsoid.cpp

HEADERS += \
    figurageometrica.h \
    sculptor.h \
    putvoxel.h \
    cutvoxel.h \
    putbox.h \
    cutbox.h \
    putsphere.h \
    cutsphere.h \
    putellipsoid.h \
    cutellipsoid.h
