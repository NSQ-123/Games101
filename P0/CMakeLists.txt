cmake_minimum_required (VERSION 3.10)
project (Transformation)

#find_package(Eigen3 REQUIRED)
include_directories(../Eigen3/include/eigen3)

add_executable (Transformation main.cpp)
