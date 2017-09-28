cmake_minimum_required(VERSION 2.8)

project(OOP_lab1)

add_subdirectory(src) 


set(SOURCE_FILES src/main.cpp src/source.cpp src/header.h)


add_executable(OOP_lab11 ${SOURCE_FILES})