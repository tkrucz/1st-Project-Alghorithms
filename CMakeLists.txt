cmake_minimum_required(VERSION 3.27)
project(1st_project___Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(1st_project___Calculator main.cpp
    Define.cpp
    OperandList.cpp
    OperandList.h
    OperatorList.cpp
    OperatorList.h
    GeneralFunctions.cpp
        GeneralFunctions.h)
