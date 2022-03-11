#include "../header/enemy.hpp"

Enemy:Enemy() {
	this->name = "None"
	this->healthPoints = 0;
	this->attackPower = 0;
	this->defense = 0;
}

~Enemy:Enemy() {
}

void Enemy::takeDamage(int damageTaken) {
	this->healthPoints -= damageTaken;
	if (this->healthPoints <= 0) {
		this->healthPoints = 0;
	}
}
