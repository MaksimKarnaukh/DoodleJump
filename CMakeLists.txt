#cmake_minimum_required(VERSION 3.16)
#project(DoodleJump)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(DoodleJump src/main.cpp)

#project(DoodleJump)
#cmake_minimum_required(VERSION 3.10.2)
#set(PROJECT_NAME DoodleJump)
#set(CMAKE_CXX_STANDARD 20)
#
#project(${PROJECT_NAME})
#add_executable(${PROJECT_NAME} src/main.cpp)
#
## (Windows) path to SFML library
#set(SFML_ROOT c:/SFML)
#include_directories(headers /usr/include ${SFML_ROOT}/include)
#
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
#find_package(SFML REQUIRED system window graphics network audio)
#if (SFML_FOUND)
#    include_directories(${SFML_INCLUDE_DIR})
#    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#endif()
#
#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
#
## Copy dlls to build
#if(WIN32)
#    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
#    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
#    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#endif()


#project(DoodleJump)
#cmake_minimum_required(VERSION 3.10.2)
#
#set(SFMLDIR c:/SFML)
## Extend the CMake module path to find the FindSFML.cmake
## file in {project root}/cmake/Modules
#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
#
## Look for SFML >= 2.0, with the specific subcomponents listed below
#FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)
#
## The source files to compile
#SET(SRC src/main.cpp)
#
## Add include dirs for SFML
## (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
#INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
#
## The program we're compiling with the sources set above
#ADD_EXECUTABLE(DoodleJump ${SRC})
#
## Link target to SFML libs
## (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
#TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})
#
#INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)

project(DoodleJump)
set(PROJECT_NAME DoodleJump)
cmake_minimum_required(VERSION 3.10.2)

if(APPLE)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1-MAC/include")
    set( SFML_LIBRARY_DIR "libs/SFML-2.5.1-MAC/build/lib")

elseif (UNIX)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/include/")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/lib/cmake/SFML/")
    set(SFML_SHARE "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/share/")

elseif(WIN32)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/include/")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/lib/cmake/SFML")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/lib/")
    file(GLOB SFML_DLL "${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1_WIN/bin/*.dll")
    file(COPY ${SFML_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

endif()

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

SET(SRC src/main.cpp)
ADD_EXECUTABLE(DoodleJump ${SRC})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

target_link_libraries(DoodleJump sfml-audio sfml-graphics sfml-window sfml-system)
