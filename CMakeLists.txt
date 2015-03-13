cmake_minimum_required(VERSION 2.8)

project(Imac3-MoteursPhysiques-PartyKel)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

ADD_DEFINITIONS( -DGLEW_STATIC=1 )

# Pour gérer un bug a la fac, a supprimer sur machine perso:
#set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

include_directories( ${CMAKE_SOURCE_DIR}/external/stb ) #STB
include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} PartyKel/include third-party/include)

add_subdirectory(PartyKel)

set(ALL_LIBRARIES PartyKel ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

file(GLOB_RECURSE SRC_FILES src/*.cpp)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(FILE ${SRC_FILE} NAME_WE)
    add_executable(${FILE} ${SRC_FILE})
    target_link_libraries(${FILE} ${ALL_LIBRARIES})
endforeach()
