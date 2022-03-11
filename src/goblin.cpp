#include "../header/goblin.hpp"

Goblin::Goblin() {
	name = "Goblin";
	healthPoints = 50;
	attackPower = 15;
	defense = 5;
}

Goblin::~Goblin() {
}

void Goblin::attack() {
	cout << "Goblin attack!" << endl;
}
