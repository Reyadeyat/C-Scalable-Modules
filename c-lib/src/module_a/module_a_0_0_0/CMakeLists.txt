cmake_minimum_required(VERSION 3.26)
project(c-lib-module-a.0.0.0)
#set(PREFIX "")
#set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
#set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS "${CFLAGS} -fPIC -Wall -Werror -fPIC -O3 -fstack-protector --save-temps")
message("CFLAGS ${CMAKE_C_FLAGS}")

set(SOURCE_DIRECTORY ".")
file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILE_LIST})

set_target_properties("${PROJECT_NAME}" PROPERTIES LINKER_LANGUAGE C)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
