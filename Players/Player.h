#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "../HealthPoints/HealthPoints.h"

#include <string>
using namespace std;

class Player {
    string m_name;
    int m_level; // gives off warning
    int m_force;
    HealthPoints m_HP;
    int m_coins;
    string m_job;
public:
    explicit Player(const std::string &name);
    explicit Player(const std::string &name, const std::string &job);
    Player& operator=(const Player& other) = default;
//    void printInfo();
    ~Player() = default; // change later
    Player() = default;
    void levelUp();
    void buff(int f);
    virtual void heal(int hp);
    virtual void addCoins(int c);
    virtual int getAttackStrength() const;
    void damage(int dmg);
    bool isKnockedOut() const;
    bool pay(int amount);
    int getForce() const;
    int getLevel() const;
    int getCoins() const;
    string getName() const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual void wellFall();
    virtual void barFight();
    virtual void manaApply();

    int HP_asInteger() const;
};

#endif