cmake_minimum_required(VERSION 3.23)
project(MTMCHKIN_HW4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MTMCHKIN_HW4
        utilities.cpp
        utilities.h
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
        Cards/Card.cpp
        Cards/Card.h
        Cards/BattleCards/Gremlin.cpp
        Cards/BattleCards/Gremlin.h
        Cards/BattleCards/BattleCard.cpp
        Cards/BattleCards/BattleCard.h
        Cards/BattleCards/Witch.cpp
        Cards/BattleCards/Witch.h
        Cards/BattleCards/Dragon.cpp
        Cards/BattleCards/Dragon.h
        Cards/MerchantCards/MerchantCard.cpp
        Cards/MerchantCards/MerchantCard.h
        Cards/TreasureCards/TreasureCard.cpp
        Cards/TreasureCards/TreasureCard.h
        Cards/WellCards/WellCard.cpp
        Cards/WellCards/WellCard.h
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
