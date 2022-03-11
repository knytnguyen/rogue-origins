#ifndef __SHOPITEM_HPP__
#define __SHOPITEM_HPP__  

#include "../header/player.hpp"
#include "../header/shop.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Healing_Potion : public Shop
{
private:
    string itemName = "Healing Potion"; /*10 increase in health*/
    int price = 150;
    string itemDetails = "Heals 10 hp";

    int health = 10;
    int def = 0;
    int sword = 0;
    int atkp = 1;
public:
    Healing_Potion() {

    }

    ~Healing_Potion() {
        /* ... */
    }

    virtual string getItemName() { return itemName; }
    virtual int getPrice() { return price; }
    virtual string getItemDetails() { return itemDetails; }
    virtual int getHealth() { return health; }
    virtual int getAttackPower() { return atkp; }
    virtual int getDef() { return def; }
    virtual int getSword() { return sword; }
};

class Strength_Potion : public Shop
{
private:
    string itemName = "Strength Potion";
    int price = 400;
    string itemDetails = "Multiplies the character's damage by 2 for an entire round";

    int health = 0;
    int def = 0;
    int sword = 0;
    int atkp = 2;
public:
    Strength_Potion() {

    }

    ~Strength_Potion() {
        /* ... */
    }

    virtual string getItemName() { return itemName; }
    virtual int getPrice() { return price; }
    virtual string getItemDetails() { return itemDetails; }
    virtual int getHealth() { return health; }
    virtual int getAttackPower() { return atkp; }
    virtual int getDef() { return def; }
    virtual int getSword() { return sword; }
};

class Sword_Upgrade : public Shop
{
private:
    string itemName = "Strength Potion";
    int price = 200;
    string itemDetails = "Multiplies the character's damage by 1.5 for an entire round";
    int health = 0;
    int def = 0;
    int sword = 10;
    int atkp = 1;
public:
    Sword_Upgrade() {

    }

    ~Sword_Upgrade() {
        /* ... */
    }

    virtual string getItemName() { return itemName; }
    virtual int getPrice() { return price; }
    virtual string getItemDetails() { return itemDetails; }
    virtual int getHealth() { return health; }
    virtual int getAttackPower() { return atkp; }
    virtual int getDef() { return def; }
    virtual int getSword() { return sword; }
};

class Shield_Upgrade : public Shop
{
private:
    string itemName = "Strength Potion";
    int price = 200;
    string itemDetails = "Multiplies the character's damage by 1.5 for an entire round";

    int health = 0;
    int def = 5;
    int sword = 0;
    int atkp = 1;
public:
    Shield_Upgrade() {

    }

    ~Shield_Upgrade() {
        /* ... */
    }

    virtual string getItemName() { return itemName; }
    virtual int getPrice() { return price; }
    virtual string getItemDetails() { return itemDetails; }
    virtual int getHealth() { return health; }
    virtual int getAttackPower() { return atkp; }
    virtual int getDef() { return def; }
    virtual int getSword() { return sword; }

};

#endif