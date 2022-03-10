#ifndef __SHOP_HPP__
#define __SHOP_HPP__    

#include <string>
#include <iostream>
#include <vector>

#include "../header/character.hpp"

class Item {
    private:
        int price;
        std::string itemDetails;
    public:
        Item(int p,std::string s): price(p), itemDetails(s) {}
        ~Items();
        std::string getItemDetails() const { return itemDetails; }
        int getPrice() const { return price; }

};

class Shop: public Item {
    private:
        std::vector<Item*> items;
        int itemID;
    public:
        Shop();
        ~Shop();
        void displayItems() const;
        

        void viewPrice(int) const;
        void viewItemDetails(int) const;
        void buyItem(int);

        void closeShop() const;
};

// class Healing_Potion: public Item { // heal a flat amt of hp
class Healing_Potion : public Item
{
private:
	string itemName = "Healing Potion"; //10 increase in health
public:
	~Healing_Potion() {
		/* ... */
	}

  virtual string getItemName(){
		return itemName;
	}

	int calculatingChangeInHealth(Character* UsingThisItem, Character* UsingThisItemOn)
	{
		if(UsingThisItem == UsingThisItemOn){
            		int healthPoints = UsingThisItem->getHealth();
            		return ((int)((100 - healthPoints)*.10));
        	}else{
            		cout << "Cannot use this item like this." << endl;
                return 0;
        	}
	}

	void useThisItem(Character* UsingThisItem, Character* UsingThisItemOn)
	{
		if(UsingThisItem == UsingThisItemOn){
            		int healthPoints = UsingThisItem->getHealthPoints();
            		UsingThisItem->healthChange((int)((100 - healthPoints)*.10));
                cout << "You have gained: " << (int)((100 - healthPoints)*.10) << " health from the " << itemName << "!" << endl;
        	}else{
            		cout << "Cannot use this item like this." << endl;
        	}
	}
};

// // class Strength_Potion: public Item { // multiply player dmg by 1.5 for entire round
class Strength_Potion : public Item
{
private:
	string itemName = "Strength Potion"; //multiply player dmg by 1.5 for entire round
public:
	~Strength_Potion() {
		/* ... */
	}

  virtual string getItemName(){
		return itemName;
	}

	int calculatingChangeInAttack(Character* UsingThisItem, Character* UsingThisItemOn)
	{
		if(UsingThisItem == UsingThisItemOn){
            		int attackPower = UsingThisItem->getAttack();
            		return ((int)((100 - attackPower)*1.5));
        	}else{
            		cout << "Cannot use this item like this." << endl;
                return 0;
        	}
	}

	void useThisItem(Character* UsingThisItem, Character* UsingThisItemOn)
	{
		if(UsingThisItem == UsingThisItemOn){
            		int attackPower = UsingThisItem->getAttack();
            		UsingThisItem->attackChange((int)((100 - attackPower)*1.5));
                cout << "You now have: " << (int)((100 - attackPower)*1.5) << "attack from the" << itemName << "!" << endl;
        	}else{
            		cout << "Cannot use this item like this." << endl;
        	}
	}
};

// // class Sword_Upgrade: public Item { // permanently increase dmg by flat amt
//
// // };
//
// // class Shield_Upgrade: public Item { // permanently increase health by flat amt
//
// // };
//
// #endif // __SHOP_HPP__
