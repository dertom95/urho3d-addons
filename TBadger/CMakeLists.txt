#
# Copyright (c) 2008-2015 the Urho3D project.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

# Define target name

cmake_minimum_required (VERSION 3.2.3)

project(turbobadger_integration)

add_subdirectory(3rd/TurboBadger)

#==========================================
# turbo badger dependencies
#==========================================
set (inc_dirs   ${CMAKE_CURRENT_SOURCE_DIR}/3rd)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/animation
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/image
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/parser
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/renderers
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/thirdparty
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/utf8
                ${CMAKE_CURRENT_SOURCE_DIR}/3rd/TurboBadger/tests)


list(APPEND INCLUDE_DIRS ${inc_dirs} ${CMAKE_CURRENT_SOURCE_DIR/src})

file( GLOB_RECURSE files FOLLOW_SYMLINKS ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp src/*.h)

add_library(${PROJECT_NAME} ${files})

link_libraries(TurboBadger)
list(APPEND LIBS ${PROJECT_NAME} TurboBadger)

set(LIBS ${LIBS} PARENT_SCOPE)
set(INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)
