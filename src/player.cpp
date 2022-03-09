#include "../header/player.hpp"

#include <iostream>
using namespace std;

Player::Player() {
    	name = "NONE";
    	characterLevel = 1;
	playerHP = 0;
	playerAttackPower = 0;
    	experiencePoints = 0;
    	experienceNext = 0;
	coins = 0;
}

Player::~Player(){
}

void Player::createInitialPlayer(string name) {
    	this->name = name;
    	this->characterLevel = 1;
	this->playerHP = 0;
	this->playerAttackPower = 0;
    	this->experiencePoints = 0;
    	this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    	this->coins = 0;
}

void Player::initializeEasy(string name) {
    	this->name = name;
    	this->characterLevel = 1;
	this->playerHP = 100;
	this->playerAttackPower = 25;
    	this->experiencePoints = 0;
    	this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    	this->coins = 0;
}

void Player::initializeMedium(string name) {
	this->name = name;
        this->characterLevel = 1;
        this->playerHP = 75;
        this->playerAttackPower = 20;
        this->experiencePoints = 0;
        this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
        this->coins = 0;
}

void Player::initializeHard(string name) {
	this->name = name;
        this->characterLevel = 1;
        this->playerHP = 50;
        this->playerAttackPower = 15;
        this->experiencePoints = 0;
        this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
        this->coins = 0;
}

void Player::attack() {
	cout << "Player attacks!" << endl;
}
