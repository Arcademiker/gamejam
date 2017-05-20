cmake_minimum_required(VERSION 3.7)
project(cmaketest)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(opencv ${SOURCE_FILES})
#FIND_PACKAGE( OpenCV REQUIRED core highgui imgproc)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(opencv ${OpenCV_LIBS})