cmake_minimum_required(VERSION 3.0.0)

project(GoodsAppDBManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(INSERT_TEST_DATA OFF)

if (INSERT_TEST_DATA)
    add_definitions(-DINSERT_TEST_DATA)
endif()

if (BUILD_TESTS)
    add_definitions(-DBUILD_TESTS)
endif()

find_package(Qt5Core)
find_package(Qt5Sql)

set(LIB_SOURCES
    "dbconnectionmanager.cpp"
    "dbselector.cpp"
    "dbmanager.cpp"
    "dbmanipulator.cpp"
    "dbprocessing.cpp")

set(LIB_HEADERS
    "dbconnectionmanager.h"
    "dbselector.h"
    "dbmanager.h"
    "dbmanipulator.h"
    "dbtypes.h"
    "dbprocessing.h")

add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Sql)
