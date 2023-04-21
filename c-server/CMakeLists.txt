cmake_minimum_required(VERSION 3.26)
include(./CMakeFunctions.txt)
project(c-server)
#set(PREFIX "")
#set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
#set(CMAKE_SHARED_MODULE_PREFIX "")

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS "${CFLAGS} -Wall -Werror -O3 -fstack-protector --save-temps")
message("CFLAGS ${CMAKE_C_FLAGS}")

#Copy Include Directory Header Files from c-lib
set(LIB_SOURCE_DIRECTORY "../c-lib/src")
set(INCLUDE_DIRECTORY "./include")
COPY_FILE_LIST_FROM_TO("/module-a/*.h" ${LIB_SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} false)

file(MAKE_DIRECTORY "./lib")
INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORY})
LINK_DIRECTORIES("../c-lib/lib")

set(SOURCE_DIRECTORY "./src")
file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c")
ADD_EXECUTABLE(c-server ${SOURCE_FILE_LIST})

COPY_FILE_LIST_FROM_TO("/*.so" "../c-lib/lib" "./lib" false)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin COMPONENT Binaries)

