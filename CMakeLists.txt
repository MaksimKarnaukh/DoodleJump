#cmake_minimum_required(VERSION 3.16)
#project(DoodleJump)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(DoodleJump src/main.cpp)

cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME ProjectAP)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)

# (Windows) path to SFML library
set(SFML_ROOT c:/SFML)
include_directories(headers /usr/include ${SFML_ROOT}/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()