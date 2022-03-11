#ifndef __SHOP_TEST__
#define __SHOP_TEST__

#include "gtest/gtest.h"
#include "../header/shop.hpp"
#include "../header/player.hpp"
#include "../header/PurchaseStrategy.hpp"
#include "../header/shopItem.hpp"

TEST(ShopTest, HealingPotion){
    Player* ch = new Player();
    ch->setCoins(4000);
    ch->setHealthPoints(10);

    Shop* potion = new Healing_Potion();

    PurchaseStrategy p;
    p.increaseStat(ch, potion);

    EXPECT_EQ(20, ch->getHealthPoints());
}


TEST(ShopTest, StrengthPotion){
    Player* ch = new Player();
    ch->setCoins(4000);
    ch->setAttackPower(20);
    
    Shop* potion = new Strength_Potion();
    
    PurchaseStrategy p;
    p.increaseStat(ch, potion);
    
    EXPECT_EQ(40, ch->getAttackPower());
}


TEST(ShopTest, SwordUpgrade){
Player* ch = new Player();
    ch->setCoins(4000);
    ch->setAttackPower(0);
    
    Shop* sword = new Sword_Upgrade();
    
    PurchaseStrategy p;
    p.increaseStat(ch, sword);
    
    EXPECT_EQ(10, ch->getAttackPower());
}


TEST(ShopTest, ShieldUpgrade){
Player* ch = new Player();
    ch->setCoins(4000);
    ch->setDefense(4);
    
    Shop* shield = new Shield_Upgrade();
    
    PurchaseStrategy p;
    p.increaseStat(ch, shield);

    EXPECT_EQ(9, ch->getDefense());
}

#endif // __SHOP_TEST__

