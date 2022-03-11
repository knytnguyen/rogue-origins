#include "../header/player.hpp"

#include <iostream>
using namespace std;

Player::Player() {
    	name = "NONE";
    	playerLevel = 1;
	healthPoints = 0;
	attackPower = 0;
	defense = 0;
    	experiencePoints = 0;
    	experienceNext = 0;
	coins = 0;
}

Player::~Player(){
}

void Player::createInitialPlayer(string name) {
    	this->name = name;
    	this->playerLevel = 1;
	this->healthPoints = 0;
	this->attackPower = 0;
	this->defense = 0;
    	this->experiencePoints = 0;
    	this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    	this->coins = 0;
}

void Player::initializeEasy(string name) {
    	this->name = name;
    	this->playerLevel = 1;
	this->healthPoints = 100;
	this->attackPower = 25;
	this->defense = 10;
    	this->experiencePoints = 0;
    	this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
    	this->coins = 0;
}

void Player::initializeMedium(string name) {
	this->name = name;
        this->playerLevel = 1;
        this->healthPoints = 75;
        this->attackPower = 20;
	this->defense = 7;
        this->experiencePoints = 0;
        this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
        this->coins = 0;
}

void Player::initializeHard(string name) {
	this->name = name;
        this->playerLevel = 1;
        this->healthPoints = 50;
        this->attackPower = 15;
	this->defense = 5;
        this->experiencePoints = 0;
        this->experienceNext = 0;       // need to come up with algorithm to calculate level up system
        this->coins = 0;
}

void Player::attack() {
	cout << "Player attacks!" << endl;
}

void Player::printPlayerStats() {
	string userInput = "";
	cout << endl;
	cout << "╔============================== " << this->name << "'s Stats ==============================╗ " << endl << endl;
	cout << "				 Level:   " << this->playerLevel << endl;
	cout << "				 Health:  " << this->healthPoints << endl;
	cout << "				 Attack:  " << this->attackPower  << endl;
	cout << "				 Defense: " << this->defense  << endl;
	cout << "				 Coins:   " << this->coins  << endl;
	cout << endl;
	cout << "╚============================================================================╝" << endl << endl;
	do {
        cout << "            Press the ENTER key to return back to the Player Menu: ";
                cin.ignore();
                getline(cin, userInput);
                userInput = "";
        } while (userInput.length() != 0);
}
