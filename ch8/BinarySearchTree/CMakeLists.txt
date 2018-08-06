#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(Tree)

# Configuration
#

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
  ./
  ./src
)
add_executable(Tree
  src/main.cpp
)

