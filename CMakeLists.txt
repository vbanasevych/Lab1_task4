cmake_minimum_required(VERSION 4.0)
project(Lab1_task4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1_task4 main.cpp
        stacks.h
        stacks.cpp
        card.cpp
        deck_dealer.cpp
        deck_dealer.h)
