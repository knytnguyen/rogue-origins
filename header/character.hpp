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

	// character function 
		virtual void attack(Character*) = 0;
};

#endif
