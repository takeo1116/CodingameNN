cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")
project(UTTTLearning CXX)
add_executable(a.out
    main.cpp
    engine/board.cpp
    engine/cell.cpp
    learn/learndata.cpp
)
