cmake_minimum_required(VERSION 3.23)
project(MTMCHKIN_HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MTMCHKIN_HW4
        Players/Player.cpp
        Players/Player.h
        main.cpp
        HealthPoints/HealthPoints.cpp
        HealthPoints/HealthPoints.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Healer.h
        Players/Healer.cpp
        Players/Warrior.h
        Players/Warrior.cpp
        )

#add_executable(MTMCHKIN_HW4
#        Mtmchkin.h
#        test.cpp
#        utilities.cpp
#        utilities.h
#        Player/Player.cpp
#        Player/Player.h
#        main.cpp
#        )
