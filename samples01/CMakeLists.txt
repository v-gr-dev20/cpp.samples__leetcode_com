cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)
if(NOT CMAKE_BUILD_TYPE)
	message("Defaulting to Debug build.")
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

project(samples01 CXX)

include(CTest)
include(../CMake/Utils.cmake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_subdirectory(test)

