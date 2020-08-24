cmake_minimum_required(VERSION 3.5)
project(moviestore)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

# need to load data files from current directory as cpp files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(moviestore.exe main.cpp store_test.cpp movie.cpp classiccollection.cpp classicmovie.cpp comedycollection.cpp comedymovie.cpp customer.cpp customercollection.cpp dramacollection.cpp dramamovie.cpp hashtable.cpp moviecollection.cpp store.cpp movieutils.cpp)
