#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "../header/character.hpp"

#include <string>

class Enemy: public Character {
    
};

class Archmage: public Enemy {
    public:
        Archmage() {this->healthPoints = 200; this->attackPower = 15;}
        // ~Archmage();
    
        void attack(Character* p) {
            p->healthChange(-this->getAttack());
        }
	inline const int& getArchmageAttackPower() const { return this->attackPower; }
};

#endif
