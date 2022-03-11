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
   
    // character functions: 
    //Health Pot add-on variables
    int getHealth(){
        return healthPoints;
    }

    // character function 
    virtual void attack() = 0;

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
};

#endif
