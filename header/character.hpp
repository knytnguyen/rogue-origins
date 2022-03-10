#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>

using namespace std;

class Character {
private:
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

    //functions:
    void createInitialCharacter(string name);
    void initializeEasy(string name); // depending on the difficulty, we are going to initilize the character;
    void initializeMedium(string name); // depending on the difficulty, we are going to initilize the character;
    void initializeHard(string name); // depending on the difficulty, we are going to initilize the character;

    //accessors:
    inline const string& getName() const { return this->name; }
    inline const int& getLevel() const { return this->characterLevel; }
    inline const int& getExperiencePoints() const { return this->experiencePoints; }
    inline const int& getExperienceNext() const { return this->experienceNext; }
    inline const int& getHealthPoints() const { return this->healthPoints; }
    inline const int& getAttackPower() const { return this->attackPower; }
    inline const int& getCoins() const { return this->coins; }

    //Health Pot add-ons
    int getHealth(){
        return healthPoints;
    }

    void healthChange(int amountToChange){
        healthPoints = healthPoints + amountToChange;
    }
};

#endif
