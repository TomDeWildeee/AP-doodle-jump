cmake_minimum_required(VERSION 3.22.1)
project(doodle_jump)

SET(CMAKE_CXX_FLAGS "-Wall")
ADD_SUBDIRECTORY(logic)
ADD_SUBDIRECTORY(view)
ADD_SUBDIRECTORY(google_tests)

#include(FetchContent)
#FetchContent_Declare(
#        doxygen-awesome-css
#        URL https://github.com/jothepro/doxygen-awesome-css/archive/refs/heads/main.zip
#)
#FetchContent_MakeAvailable(doxygen-awesome-css)
#
#
#FetchContent_GetProperties(doxygen-awesome-css SOURCE_DIR AWESOME_CSS_DIR)
#
#set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
#set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

INSTALL(TARGETS DoodleJump DESTINATION bin)
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF ()

