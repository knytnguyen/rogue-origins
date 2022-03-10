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
            		int userHealth = UsingThisItem->getHealth();
            		return ((int)((100 - userHealth)*.10));
        	}else{
            		cout << "Cannot use this item this." << endl;
                return 0;
        	}
	}

	void useThisItem(Character* UsingThisItem, Character* UsingThisItemOn)
	{
		if(UsingThisItem == UsingThisItemOn){
            		int userHealth = UsingThisItem->getHealth();
            		UsingThisItem->healthChange((int)((100 - userHealth)*.10));
                cout << "You have gained: " << (int)((100 - userHealth)*.10) << " health from the " << itemName << "!" << endl;
        	}else{
            		cout << "Cannot use this item this." << endl;
        	}
	}
};


// // };
//
// // class Strength_Potion: public Item { // multiply player dmg by 1.5 for entire round
//
// // };
//
//
// // class Sword_Upgrade: public Item { // permanently increase dmg by flat amt
//
// // };
//
// // class Shield_Upgrade: public Item { // permanently increase health by flat amt
//
// // };
//
// #endif // __SHOP_HPP__
