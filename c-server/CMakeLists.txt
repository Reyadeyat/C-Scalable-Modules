cmake_minimum_required(VERSION 3.26)
include(./CMakeFunctions.txt)
project(c-server)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS "${CFLAGS} -Wall -Werror -O3 -fstack-protector --save-temps")
message("CFLAGS ${CMAKE_C_FLAGS}")

#Copy Include Directory Header Files from c-lib
set(LIB_SOURCE_DIRECTORY "../c-lib/src")
set(INCLUDE_DIRECTORY "./include")
file(MAKE_DIRECTORY ${INCLUDE_DIRECTORY})
#file(GLOB_RECURSE HEADER_FILE_LIST "${LIB_SOURCE_DIRECTORY}/*.h")
COPY_FILE_LIST_FROM_TO("/module_a/*.h" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY})

file(MAKE_DIRECTORY "./lib")
INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORY})
LINK_DIRECTORIES("../c-lib/lib")

set(SOURCE_DIRECTORY "./src")
file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c")
ADD_EXECUTABLE(c-server ${SOURCE_FILE_LIST})

COPY_FILE_LIST_FROM_TO("/*.so" "../c-lib/lib" "./lib")

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin COMPONENT Binaries)

