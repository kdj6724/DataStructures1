#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(ArrayStack)

# Configuration
#

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
  ./
)
add_executable(ArrayStack
  src/ArrayStack.cpp
  src/CheckMatching.cpp
)

