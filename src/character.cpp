#include "../header/character.hpp"

Character::Character() {
    name = "NONE";
    characterLevel = 1;
    experiencePoints = 0;
    experienceNext = 0;
    healthPoints = 0;
    attackPower = 0;
}

Character::~Character() {
}

void Character::createInitialCharacter(string name) {
    this->name = name;
    this->characterLevel = 1;
    this->experiencePoints = 0;
    this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    this->healthPoints = 0;
    this->attackPower = 0;
    this->coins = 0;
}

void Character::initializeEasy(string name) {
    this->name = name;
    this->characterLevel = 1;
    this->experiencePoints = 0;
    this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    this->healthPoints = 100;
    this->attackPower = 25;
    this->coins = 0;
}

void Character::initializeMedium(string name) {
    this->name = name;
    this->characterLevel = 1;
    this->experiencePoints = 0;
    this->experienceNext = 0;      // need to come up with algorithm to calculate level up system
    this->healthPoints = 75;
    this->attackPower = 20;
    this->coins = 0;
}

void Character::initializeHard(string name) {
    this->name = name;
    this->characterLevel = 1;
    this->experiencePoints = 0;
    this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    this->healthPoints = 50;
    this->attackPower = 15;
    this->coins = 0;
}
