cmake_minimum_required (VERSION 3.2.3)

project(componentexporter)

source_group("Source" ${PROJECT_SOURCE_DIR})

add_library(${PROJECT_NAME} base64.cpp ComponentExporter.h ComponentExporter.cpp)

list(APPEND LIBS componentexporter)

message("ComponentExporterLibs: ${LIBS}")

set(LIBS ${LIBS} PARENT_SCOPE)
