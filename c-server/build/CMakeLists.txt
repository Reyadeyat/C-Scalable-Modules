cmake_minimum_required(VERSION 3.26)
project(c-server)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

SET(INCLUDE_DIRECTORY "../include")

file(MAKE_DIRECTORY "../lib")

INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORY})

LINK_DIRECTORIES("../c-lib/lib")

set(SOURCE_DIRECTORY "../src")
file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c")
ADD_EXECUTABLE(c-server ${SOURCE_FILE_LIST})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin COMPONENT Binaries)


#cd /linux/MODULE-ORIENTED-C
#mkdir ./c-server
#nano ./c-server/build/CMakeLists.txt
#cmake ./c-server/build -B./c-server/build
#cmake --build ./c-server/build --target all -j 4
#cmake --install ./c-server/build --prefix=./c-server
#./c-server/bin/c-server
