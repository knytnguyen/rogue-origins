#ifndef PLAYER_TEST_HPP
#define PLAYER_TEST_HPP

#include "gtest/gtest.h"
#include "../header/player.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST(Player_Test, GetPlayerName) {
	string playerName = "Valor";
	vector<Player> playableCharacter;
    	int currentPlayer;
	playableCharacter.push_back(Player());
    	currentPlayer = playableCharacter.size() - 1;
    	playableCharacter[currentPlayer].createInitialPlayer(playerName);

	string playerNameTest = playableCharacter[currentPlayer].getName();
	EXPECT_EQ("Valor", playerNameTest);
}

#endif
