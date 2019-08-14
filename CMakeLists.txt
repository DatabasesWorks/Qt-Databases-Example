cmake_minimum_required(VERSION 3.0.0)

project(DBManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(INSERT_TEST_DATA ЩТ)

if (INSERT_TEST_DATA)
    add_definitions(-DINSERT_TEST_DATA)
endif()

if (BUILD_TESTS)
    add_definitions(-DBUILD_TESTS)
endif()

find_package(Qt5Core)
find_package(Qt5Sql)

set(LIB_SOURCES
    "src/dbconnectionmanager.cpp"
    "src/dbselector.cpp"
    "src/dbmanager.cpp"
    "src/dbprocessing.cpp"
    "src/dbmanipulator.cpp")

set(LIB_HEADERS
    "include/dbconnectionmanager.h"
    "include/dbselector.h"
    "include/dbmanager.h"
    "include/dbtypes.h"
    "include/dbprocessing.h"
    "include/dbmanipulator.h"
    )

add_library(${PROJECT_NAME} SHARED ${LIB_SOURCES}
                                   ${LIB_HEADERS}
                                   ${PUBLIC_HEADERS})

target_include_directories(DBManager
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set_target_properties(PROPERTIES PUBLIC_HEADER
                      "include/dbtypes.h;
                       include/dbprocessing.h")

include(GNUInstallDirs)

install(
    TARGETS DBManager
    EXPORT "${TARGETS_EXPORT_NAME}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    )

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Sql)
