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

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
            ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE}
            ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY
            ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API
documentation" VERBATIM)
endif(DOXYGEN_FOUND)


link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

FILE(GLOB gameRepresentationFiles
        src/game_representation/*.cpp)

FILE(GLOB logicLibraryFiles
        src/logic_library/*.cpp)

ADD_EXECUTABLE(DoodleJump
        src/main.cpp
        src/LoadFileException.cpp
        ${gameRepresentationFiles})

ADD_LIBRARY(logicLibrary STATIC
        ${logicLibraryFiles})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

target_link_libraries(DoodleJump
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
        logicLibrary)

INSTALL(TARGETS DoodleJump DESTINATION ${PROJECT_SOURCE_DIR}/bin)