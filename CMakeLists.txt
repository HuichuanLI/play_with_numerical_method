cmake_minimum_required(VERSION 3.20)
project(play_with_algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ./Test.cpp SoulutionofNonLinearEquation.cpp SoulutionofNonLinearEquation.h Test.h)
add_executable(play_with_algo ${SOURCE_FILES})
