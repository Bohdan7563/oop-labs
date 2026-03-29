cmake_minimum_required(VERSION 3.20)
project(oop_lab)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "lab2/*.cpp")

add_executable(app ${SOURCES})