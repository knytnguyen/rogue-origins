#ifndef GAME_HPP
#define GAME_HPP

#include "../header/character.hpp"
#include "../header/player.hpp"
#include "../header/enemy.hpp"

#include <iostream>
#include <string>
#include <vector>

class Game {
	private:
    		char mainMenuChoice;
		char playerMenuChoice;
		char quitGameChoice;
    		bool gameStatus;
		bool playerMenuStatus;
		bool finalBattleStatus;
    		vector<Player> playableCharacter;
    		int currentPlayer;

	public:
    		// constructors:
    		Game();

    		// destructors:
    		~Game();

    		// functions:
    		void mainMenu();
    		void continueGame();
    		void selectDifficulty();
    		void printInstructions();
		void playerMenu();
		// void printPlayerStats();
		void quitGamePrompt();
		void archmageBattle();
		void playerBattleInterface();
    
    		// getter functions:
    		inline bool getGameStatus() const { return this->gameStatus; }
};

#endif
