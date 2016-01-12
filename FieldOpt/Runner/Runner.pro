include(../defaults.pri)

CONFIG   -= app_bundle

TARGET = FieldOpt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

CONFIG += c++11
LIBS += -L$$OUT_PWD/../Model -lmodel
LIBS += -L$$OUT_PWD/../Optimization -loptimization
LIBS += -L$$OUT_PWD/../Simulation -lsimulation
LIBS += -L$$OUT_PWD/../Utilities -lutilities
LIBS += -L$$OUT_PWD/../ERTWrapper -lertwrapper
LIBS += -lpthread -lgtest -pthread
LIBS += -lboost_program_options

SOURCES += main.cpp \
    runtime_settings.cpp \
    runners/main_runner.cpp \
    runners/abstract_runner.cpp

HEADERS += \
    runtime_settings.h \
    runners/main_runner.h \
    runners/abstract_runner.h

