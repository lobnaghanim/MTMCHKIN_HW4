#include "Player.h"
#include "utilities.h"
#include "HealthPoints/HealthPoints.h"

#define INITIAL_FORCE 5
#define INITIAL_LVL 1
#define INITIAL_COINS 10

Player::Player(const std::string& name){
    this->m_name = name;
    this->m_HP = MAXHP;
    this->m_force = INITIAL_FORCE;
    this->m_level = INITIAL_LVL;
    this->m_coins = INITIAL_COINS;
}

//void Player::printInfo() {
//    printPlayerInfo(this->m_name.c_str(), this->m_level, this->m_force, this->m_HP, this->m_coins);
//}

void Player::levelUp() {
    if(this->m_level == 10){
        return;
    }
    this->m_level++;
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int f) {
    this->m_force += f;
}

void Player::heal(int hp) {
//    if(hp < 0){
//        return;
//    }
    if(this->m_HP + hp > MAXHP){
        this->m_HP = MAXHP;
    } else {
        this->m_HP += hp;
    }
}

void Player::damage(int dmg) {
    if(dmg < 0){
        return;
    }

    if(this->m_HP - dmg < 0){
        this->m_HP = 0;
    } else {
        this->m_HP -= dmg;
    }
}

bool Player::isKnockedOut() const {
    if(this->m_HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int c){
    if(c < 0){
        return;
    }
    this->m_coins += c;
}

bool Player::pay(int amount) {
    if(amount < 0){
        return false;
    }
    if(this->m_coins - amount >= 0){
        this->m_coins -= amount;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}

std::string Player::getName() const {
    return this->m_name;
}

HealthPoints Player::getHP() const {
    return this->m_HP;
}

int Player::getForce() const {
    return m_force;
}

int Player::getCoins() const {
    return m_coins;
}

void Player::wellFall(){
    this->damage(10);
    printWellMessage(false);
}

void Player::barFight() {
    this->damage(8);
    printBarfightMessage(false);
}

void Player::manaApply() {
    printManaMessage(false);
}
