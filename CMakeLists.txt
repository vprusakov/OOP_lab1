cmake_minimum_required(VERSION 3.7)
project(OOP_lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/IniParser/IniParser.cpp
        src/IniParser/IniParser.h
        src/IniParserException/IniParserException.cpp
        src/IniParserException/IniParserException.h)


add_executable(OOP_lab1 ${SOURCE_FILES})