#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>

class Game {
	private:
		char userMenuChoice;
		bool gameStatus;
	public:
		//constructors:
		Game();
		//destructors:
		~Game();
		//functions:
		void mainMenu();
		void continueGame();
		//getter functions:
		inline bool getGameStatus() const { return this->gameStatus; }
};

#endif
