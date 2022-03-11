#ifndef __PURCHASESTRATEGY_HPP__
#define __PURCHASESTRATEGY_HPP__ 

#include "../header/player.hpp"
#include "../header/shopitem.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class PurchaseStrategy {
private:

public:
    virtual bool increaseStat(Player* player, Shop* item) {

        if (player->getCoins() < item->getPrice()) {
            cout << "Not enough to purchase. Going back to shop menu." << endl;
            return false;
        }
        else {
            player->setCoins(player->getCoins() - item->getPrice());
            player->setAttackPower(player->getAttackPower() + item->getSword());
            player->setAttackPower(player->getAttackPower() * item->getAttackPower());
            player->setHealthPoints(player->getHealthPoints() + item->getHealth());
            player->setDefense(player->getDefense() + item->getDef());
            return true;
        }

        
    }
};

#endif
