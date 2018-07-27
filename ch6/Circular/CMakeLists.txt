#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(Circular)

# Configuration
#

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
  ./
  ./src
)
add_executable(Circular
  src/main.cpp
)

