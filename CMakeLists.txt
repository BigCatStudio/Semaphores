cmake_minimum_required(VERSION 3.22)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)   # it is necessary to use threads in C++

add_executable(Lab2 src/main.cpp hdr/Consumer.h hdr/Producer.h hdr/Buffer.h hdr/Semaphore.h)
