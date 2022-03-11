#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>

using namespace std;

class Character {
	protected:
    	// data for characters (Player and Enemy)
    		string name;
    		int healthPoints;
    		int attackPower;
		int defense;
	public:
    	// constructor:
    		Character();
    
    	// destructor:
    		~Character();

    //accessors:
    inline const string& getName() const { return this->name; }
    inline const int& getLevel() const { return this->characterLevel; }
    inline const int& getExperiencePoints() const { return this->experiencePoints; }
    inline const int& getExperienceNext() const { return this->experienceNext; }
    inline const int& getHealthPoints() const { return this->healthPoints; }
    inline const int& getAttackPower() const { return this->attackPower; }
    inline const int& getCoins() const { return this->coins; }

    //Health Pot add-on variables
    int getHealth(){
        return healthPoints;
    }

    void healthChange(int amountToChange){
        healthPoints = healthPoints + amountToChange;
    }

    //Strength Pot add-on variables
    int getAttack(){
        return attackPower;
    }
    
    void attackChange(int atkToChange){
            attackPower = attackPower + atkToChange;
        }

	// character function 
		virtual void attack() = 0;
};

#endif
