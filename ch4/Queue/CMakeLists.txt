#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(Stack)

# Configuration
#

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(
  ./
  ./src
)
add_executable(Stack
  src/main.cpp
  #  src/stack_type.cpp
)

