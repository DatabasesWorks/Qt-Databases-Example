QT -= gui
QT += core sql
CONFIG += c++11
TEMPLATE = lib

DEFINES += BUILD_TESTS
DEFINES += INSERT_TEST_DATA
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/ConnectionManager.cpp \
    src/Selector.cpp \
    src/Executor.cpp \
    src/Processor.cpp \
    src/Manipulator.cpp

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

DESTDIR = $$PWD/../shared/lib/

INCLUDEPATH += $$PWD/include

HEADERS += \
    include/ConnectionManager.h \
    include/Selector.h \
    include/Executor.h \
    include/dbtypes.h \
    include/dbmapper.h \
    include/Processor.h \
    include/Manipulator.h

headers.path = ../shared/include
headers.files = include/dbtypes.h \
                include/Processor.h

INSTALLS += headers
