#ifndef GAME_HPP
#define GAME_HPP

#include "../header/character.hpp"
#include "../header/player.hpp"
#include "../header/enemy.hpp"

#include <iostream>
#include <string>
#include <vector>

class Event {
    private:
        bool isBattle;
        int eventDecision;
        std::string eventStoryBeginning;
        std::string eventStoryEnd;
        std::string eventStoryEndAlt;
        std::string op1Text;
        std::string op2Text;
        std::string battleText;
        Character* player;
        std::vector<string> listOfNames;
        bool userLost;
    public:
          Event(bool isb, std::string begin, std::string end, std::string alt, std::string op1, std::string op2, std::string bt, Character* user) {
              isBattle = isb;
              eventStoryBeginning = begin;
              eventStoryEnd = end;
              eventStoryEndAlt = alt;
              op1Text = op1;
              op2Text = op2;
              battleText = bt;
              player = user;
              userLost = false;
          }
	void startEvent(){
              std::cout << eventStoryBeginning; /* make sure string ends with \n */
              std::cout << std::endl << std::endl;
              std::cout << "What would you like to do?" << std::endl;
              std::cout << "1 - " << op1Text << std::endl << "2 - " << op2Text << std::endl;
              bool validInputTaken = false;
              while (!validInputTaken) {
                  std::cout << ">> ";
                  std::cin >> eventDecision;
                  if (eventDecision == 1 || eventDecision == 2) {
                      validInputTaken = true;
                  } else {
                      std::cout << "Please input either 1 or 2." << std::endl;
                  }
              }
	}
		bool gameResult(){
              return userLost;
          }
};

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
		vector<Event*> listOfStories;
		Character* player;
		int path;


	public:
    	// constructors:
    	Game();

    	// destructors:
    	~Game(){
			if(listOfStories.size() != 0){
        			for(int i = 0; i < listOfStories.size(); ++i){
        	  			delete listOfStories.at(i);
        			}
      			}
    		}

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

		//load Stories
		void loadStories();
		void runGame();
		void changePath(int p){
			path = p;
		}

};


#endif

