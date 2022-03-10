#ifndef PLAYER_TEST_HPP
#define PLAYER_TEST_HPP

#include "gtest/gtest.h"
#include "../header/player.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST(Player_Test, PlayerConstructorTest) {
	Player userPlayer;
	string playerNameTest = userPlayer.getName();
	EXPECT_EQ("NONE", playerNameTest);
}

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

TEST(Player_Test, GetPlayerHealthEasyDifficulty) {
	string playerName = "Valor";
        vector<Player> playableCharacter;
        int currentPlayer;
        playableCharacter.push_back(Player());
        currentPlayer = playableCharacter.size() - 1;
        playableCharacter[currentPlayer].initializeEasy(playerName);

	int playerHealthTest = playableCharacter[currentPlayer].getHealthPoints();
	EXPECT_EQ(100, playerHealthTest);
}

TEST(Player_Test, GetPlayerAttackMediumDifficulty) {
        string playerName = "Valor";
        vector<Player> playableCharacter;
        int currentPlayer;
        playableCharacter.push_back(Player());
        currentPlayer = playableCharacter.size() - 1;
        playableCharacter[currentPlayer].initializeMedium(playerName);

	int playerAttackTest = playableCharacter[currentPlayer].getAttackPower();
	EXPECT_EQ(20, playerAttackTest);
}

TEST(Player_Test, GetPlayerDefenseHardDifficulty) {
        string playerName = "Valor";
        vector<Player> playableCharacter;
        int currentPlayer;
        playableCharacter.push_back(Player());
        currentPlayer = playableCharacter.size() - 1;
        playableCharacter[currentPlayer].initializeHard(playerName);

	int playerDefenseTest = playableCharacter[currentPlayer].getDefense();
	EXPECT_EQ(5, playerDefenseTest);
}

#endif
