TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cJSON_Utils.cpp \
    cJSON_OF.cpp

HEADERS += \
    json.hpp \
    cJSON.h \
    cJSON_Utils.h

DISTFILES += \
    test.json
