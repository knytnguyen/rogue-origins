#ifndef __SHOP_HPP__
#define __SHOP_HPP__    

#include <string>
#include <iostream>
#include <vector>

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

// class Healing_Potion: public Item { // heal a flat amt of hp
//
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
