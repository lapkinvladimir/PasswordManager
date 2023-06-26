cmake_minimum_required(VERSION 3.24)
project(ProjectC)
set(CMAKE_CXX_STANDARD 20)

add_executable(ProjectC main.cpp Encryption.h Encryption.cpp Methods.h Methods.cpp Time.h Time.cpp)
