#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>

using namespace std;

class Character {
	protected:
    	/* data */
    		string name;
    		int characterLevel;
    		int experiencePoints;
    		int experienceNext;
    		int healthPoints;
    		int attackPower;
    		int coins;

	public:
    	//constructors:
    		Character();
    
    	//destructors:
    		~Character();

	// character function 
		virtual void attack() = 0;
		inline const int& getHealthPoints() const { return this->healthPoints; }

};

#endif
