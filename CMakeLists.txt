#cmake_minimum_required(VERSION 3.16)
#project(DoodleJump)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(DoodleJump src/main.cpp)


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


project(DoodleJump)
cmake_minimum_required(VERSION 3.10.2)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC src/main.cpp)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(DoodleJump ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(DoodleJump ${SFML_LIBRARIES})

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)