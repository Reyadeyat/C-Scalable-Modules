cmake_minimum_required(VERSION 3.26)
project(c-lib)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_C_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

set(SOURCE_DIRECTORY "./src")
set(INCLUDE_DIRECTORY "../../c-server/include")
file(MAKE_DIRECTORY ${INCLUDE_DIRECTORY})

file(GLOB_RECURSE SOURCE_FILE_LIST "${SOURCE_DIRECTORY}/*.c")
#message("${SOURCE_FILE_LIST}")
foreach(SOURCE_FILE IN LISTS SOURCE_FILE_LIST)
message("${SOURCE_FILE}")
endforeach()
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILE_LIST})

file(MAKE_DIRECTORY ${INCLUDE_DIRECTORY})
file(GLOB_RECURSE HEADER_FILE_LIST "${SOURCE_DIRECTORY}/*.h")
#message("${HEADER_FILE_LIST}")
foreach(HEADER_FILE IN LISTS HEADER_FILE_LIST)
	string(REPLACE ${SOURCE_DIRECTORY} ${INCLUDE_DIRECTORY} NEW_INCLUDE_HEADER_FILE ${HEADER_FILE})
	get_filename_component(NEW_INCLUDE_HEADER_DIRECTORY ${NEW_INCLUDE_HEADER_FILE} DIRECTORY)
	file(MAKE_DIRECTORY ${NEW_INCLUDE_HEADER_DIRECTORY})
	message("Copying header: ${HEADER_FILE} TO ${NEW_INCLUDE_HEADER_DIRECTORY}")
	file(COPY_FILE ${HEADER_FILE} ${NEW_INCLUDE_HEADER_FILE})
	#add_custom_command(TARGET ${INCLUDE_DIRECTORY} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${HEADER_FILE} ${INCLUDE_DIRECTORY})
	#file( INSTALL ${HEADER_FILE} DESTINATION ${INCLUDE_DIRECTORY} )
endforeach()

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

#cd /linux/MODULE-ORIENTED-C
#mkdir ./c-lib
#mkdir ./c-lib/build
#mkdir ./c-lib/include
#mkdir ./c-lib/lib
#mkdir ./c-lib/src
#nano ./c-lib/build/CMakeLists.txt
#cmake ./c-lib -B./c-lib/build
#cmake --build ./c-lib/build --target all -j 4
#cmake --install ./c-lib/build --prefix=./c-lib
#readelf -s ./c-lib/lib/libc-lib.so
#objdump -T ./c-lib/lib/libc-lib.so
