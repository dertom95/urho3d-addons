cmake_minimum_required (VERSION 3.2.3)

project(defaultcomponents)

source_group("Source" ${PROJECT_SOURCE_DIR})

file( GLOB_RECURSE files FOLLOW_SYMLINKS ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

add_library(${PROJECT_NAME} ${files})

list(APPEND LIBS ${PROJECT_NAME})


set(LIBS ${LIBS} PARENT_SCOPE)
