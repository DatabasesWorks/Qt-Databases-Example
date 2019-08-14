QT -= gui
QT += core sql
CONFIG += c++11
TARGET = DBManager
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
    src/dbconnectionmanager.cpp \
    src/dbselector.cpp \
    src/dbmanager.cpp \
    src/dbprocessing.cpp \
    src/dbmanipulator.cpp

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

DESTDIR = $$PWD/bin

INCLUDEPATH += $$PWD/include

HEADERS += \
    include/dbconnectionmanager.h \
    include/dbselector.h \
    include/dbmanager.h \
    include/dbtypes.h \
    include/dbprocessing.h \
    include/dbmanipulator.h