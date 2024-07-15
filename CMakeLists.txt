cmake_minimum_required(VERSION 3.28)
project(Yahtzee_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Yahtzee_Game main.cpp
        src/ConsoleUI.cpp
        include/ConsoleUI.h
        src/Die.cpp
        include/Die.h
        src/GameLogic.cpp
        include/GameLogic.h)
