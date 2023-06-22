cmake_minimum_required(VERSION 3.23)
project(MTMCHKIN_HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MTMCHKIN_HW4
        utilities.cpp
        utilities.h
        Players/Player.cpp
        Players/Player.h
        HealthPoints/HealthPoints.cpp
        HealthPoints/HealthPoints.h
        Players/Ninja.cpp
        Players/Ninja.h
        Players/Healer.h
        Players/Healer.cpp
        Players/Warrior.h
        Players/Warrior.cpp
        Cards/Card.cpp
        Cards/Card.h
        Cards/Gremlin.cpp
        Cards/Gremlin.h
        Cards/BattleCards/BattleCard.cpp
        Cards/BattleCards/BattleCard.h
        Cards/Witch.cpp
        Cards/Witch.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Merchant.cpp
        Cards/Merchant.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Well.cpp
        Cards/Well.h
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Mana.cpp
        Cards/Mana.h
        Mtmchkin.h
        Mtmchkin.cpp

        main.cpp
#        test.cpp

        main.cpp)

#add_executable(MTMCHKIN_HW4
#        Mtmchkin.h
#        test.cpp
#        utilities.cpp
#        utilities.h
#        Player/Player.cpp
#        Player/Player.h
#        main.cpp
#        )
