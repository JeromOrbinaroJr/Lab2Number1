cmake_minimum_required(VERSION 3.10)
project(Lab2Number1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyExecutable SquareMatrix.h main.cpp  SquareMatrix.cpp)
