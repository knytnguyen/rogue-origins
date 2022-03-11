#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "../header/enemy.hpp"

class Goblin : public Enemy {
	private:
	public:
		Goblin();
		~Goblin();
		void attack();
}
