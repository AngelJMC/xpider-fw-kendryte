# DO NOT MODIFY THIS FILE, IT WILL BE OVERRIDE!!!

# set this will supress some warnings
set(BUILDING_SDK "yes" CACHE INTERNAL "")

# basic config
if (NOT PROJ)
    get_filename_component(PROJ ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)
    get_filename_component(PROJ ${PROJ} NAME)
    string(REPLACE " " "_" PROJ ${PROJ})
    message(STATUS "PROJ not set, use ${PROJ} as PROJ. Also, you can set it manually. e.g. -DPROJ=hello_world")
else()
    message("PROJ = ${PROJ}")
endif ()
cmake_minimum_required(VERSION 3.0)
include( ./kendryte-freertos-sdk/cmake/common.cmake)
project(${PROJ})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/kendryte-freertos-sdk/lib/arch/include ${CMAKE_CURRENT_LIST_DIR}/kendryte-freertos-sdk/lib/utils/include)
# config self use headers
header_directories(${SDK_ROOT}/kendryte-freertos-sdk/lib)
# build library first
add_subdirectory(kendryte-freertos-sdk/lib SDK)
add_subdirectory(kendryte-freertos-sdk/third_party third_party)

# compile project
add_source_files(src/*.c src/*.s src/*.S src/*.cpp)
include(./kendryte-freertos-sdk/cmake/executable.cmake)
