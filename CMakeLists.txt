cmake_minimum_required(VERSION 3.7)

project(OOP_lab1)

set(SOURCE_FILES src/main.cpp src/IniParser/header.h src/IniParser/source.cpp src/IniParserException/IniParserException.h src/IniParserException/IniParserException.cpp)

add_executable(OOP_lab1 ${SOURCE_FILES})