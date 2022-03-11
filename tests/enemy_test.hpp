#ifndef ENEMY_TEST_HPP
#define ENEMY_TEST_HPP

#include "gtest/gtest.h"
#include "../header/enemy.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST(ArchmageTest, ArchmageConstructor) {
    Archmage* test = new Archmage();
    EXPECT_EQ(200, test->getHealth());
}

TEST(ArchmageTest, ArchmageAttack) {
    Archmage* test1 = new Archmage();
    Archmage* test2 = new Archmage();
    test1->attack(test2);
    EXPECT_EQ(185, test2->getHealth());
}

#endif
