cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 20)
project(UTTTLearning CXX)
add_subdirectory(engine)
add_executable(a.out main.cpp)
target_link_libraries(a.out engine)
