cmake_minimum_required (VERSION 3.2.3)

project(urhoimgui)

include(../cmake/CPM.cmake)

CPMAddPackage(
   NAME imgui
   GIT_REPOSITORY https://github.com/ocornut/imgui.git
   VERSION 1.67
   DOWNLOAD_ONLY YES
)



message("IMGUI ${imgui_ADDED} | ${imgui_SOURCE_DIR}")
if (imgui_ADDED)
   
   include_directories(${PROJECT_NAME} ${imgui_SOURCE_DIR})
   list(APPEND INCLUDE_DIRS ${imgui_SOURCE_DIR})

#    add_library(imgui INTERFACE)
#    target_include_directories(imgui SYSTEM INTERFACE ${imgui_SOURCE_DIR})
#    link_libraries(CLI11)
endif()

include_directories(${PROJECT_NAME} ImGuizmo)


source_group("Source" ${PROJECT_SOURCE_DIR})


file( GLOB_RECURSE files FOLLOW_SYMLINKS ${CMAKE_CURRENT_SOURCE_DIR} 
            SystemUI/*.cpp 
            SystemUI/*.h
            ImGuizmo/*.cpp
            ImGuizmo/*.h
)

set(IMGUI_HEADERS
        ${imgui_SOURCE_DIR}/imconfig.h
        ${imgui_SOURCE_DIR}/imgui.h
        ${imgui_SOURCE_DIR}/imgui_internal.h
)

set(IMGUI_SRC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
)


add_library(${PROJECT_NAME} ${files} ${IMGUI_HEADERS} ${IMGUI_SRC})


list(APPEND LIBS ${PROJECT_NAME})

set(LIBS ${LIBS} PARENT_SCOPE)
set(INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
