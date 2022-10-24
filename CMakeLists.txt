cmake_minimum_required(VERSION 3.20)
project(play_with_algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ./RVector.cpp RMatrix.h RVector.cpp  RMatrix.cpp CurvingFitting.cpp CurvingFitting.h Test.h Test.cpp )
add_executable(play_with_algo ${SOURCE_FILES})
