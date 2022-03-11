#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../header/character.hpp";

class Enemy : public Character {
	private:
		int damageTaken;
	public:
		Enemy();
		~Enemy();
		void attack();
		void takeDamage(int damageTaken);
};

#endif
