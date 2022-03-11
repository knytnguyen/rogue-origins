#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../header/character.hpp"

#include <string>

using namespace std;

class Player : public Character {
private:
	string name;
	int playerLevel;
	int coins;
public:
	// constructor:
	Player();

	// destructor:
	~Player();

	// Initialize player stats with difficulty:
	void createInitialPlayer(string name);
	void initializeEasy(string name); // depending on the difficulty, we are going to initilize the character;
	void initializeMedium(string name); // depending on the difficulty, we are going to initilize the character;
	void initializeHard(string name); // depending on the difficulty, we are going to initilize the character;	

// Player functions:
	void attack(Character*);
	void fleeBattle();
	void useItem();
	void openPlayerMenu();
	void openShop();
	void printPlayerStats();

	// getter functions:
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->playerLevel; }
	inline const int& getHealthPoints() const { return this->healthPoints; }
	inline const int& getAttackPower() const { return this->attackPower; }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getCoins() const { return this->coins; }

	// setter functions:
	inline void setCoins(int coin) { this->coins = coin; }
	inline void setHealthPoints(int hp) { this->healthPoints = hp; }
	inline void setAttackPower(int ap) { this->attackPower = ap; }
	inline void setDefense(int d) { this->defense = d; }
};

#endif
