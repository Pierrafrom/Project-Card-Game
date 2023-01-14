cmake_minimum_required(VERSION 3.23)
project(Project_Card_Game_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_Card_Game_main
        main.cpp
        Card.cpp
        Card.h
        Player.cpp
        Player.h
        Game.cpp
        Game.h
        Tests.cpp
        Tests.h)
