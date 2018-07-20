#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(List)

# Configuration
#

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
  ./
  ./src
)
add_executable(List
  src/main.cpp
  src/unsorted_type.cpp
)

