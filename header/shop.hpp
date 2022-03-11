#ifndef __SHOP_HPP__
#define __SHOP_HPP__    

#include "../header/player.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Shop {
private:
    //int price;
    //std::string itemDetails;
    //string itemName;
    ////std::vector<Item*> items;
    //int itemID;
public:
    Shop() {}
    ~Shop() {}
    void displayItems(Player*);
    void buyItem(int value, Player*);
    virtual string getItemName() = 0;
    virtual int getPrice() = 0;
    virtual string getItemDetails() = 0;
    virtual int getAttackPower() = 0;
    virtual int getHealth() = 0;
    virtual int getDef() = 0;
    virtual int getSword() = 0;
};

#endif
