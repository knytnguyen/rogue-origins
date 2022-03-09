#ifndef GAME_HPP
#define GAME_HPP

#include "../header/character.hpp"
#include "../header/player.hpp"
#include <iostream>
#include <string>
#include <vector>

class Game {
	private:
    		char userMenuChoice;
    		bool gameStatus;
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
    
    		// getter functions:
    		inline bool getGameStatus() const { return this->gameStatus; }
};

#endif
