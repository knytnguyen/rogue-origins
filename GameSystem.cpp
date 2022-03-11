#include <iostream>
#include <string>
#include <vector>


void Game::loadStories(){
    /* *** LOAD WITH STORIES *** */
    listOfStories.push_back(new Event(true, "You spot a group of enemies, clearly guarding something valuable.", "You walk silently past them, not attracting any attention to your presence.", "You retrieve what they were hiding, and take it for yourself.", "Avoid the enemies", "Charge the enemies", "You charge at the enemies, and they prepare for battle!", player));
    listOfStories.push_back(new Event(true, "You see a gold chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "After defeating them, you open the chest and take what’s inside.", "Walk away", "Open the chest", "You go to open the chest, but are ambushed by a group of enemies!", player));
    listOfStories.push_back(new Event(false, "You see a wooden chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "You open the chest, and find an item!.", "Walk away", "Open the chest", "", player));
}

void Game::runGame(){
    cout << endl;
    cout << "You leave your village on a quest to rid the world of the evil final four archmages who has been terrorizing the lands
            \nand oppressing the people with their wicked magic for as long as you can remember. With your expert skills,
            \nyou are sure you can finally stop them. You set off on the road, walking to the sorcerer’s dark castle, until you
            \ncome across something." << endl << endl;

    int numOfStoriesToRun = listOfStories.size(); 
    int eventsPassed = 0;
    int storyChoice;
    bool validInputTaken = false;
    while(numOfStoriesToRun != 0){
        int randomNumber =  rand() % listOfStories.size();
        Event* currentEvent = listOfStories.at(randomNumber);
        listOfStories.erase(listOfStories.begin() + randomNumber);
        cout << endl;
        currentEvent->startEvent();
        ++eventsPassed;
        if(eventsPassed == 1) { /* FIRST STORY PROMPT */
          cout << endl;
          cout << "You proceed on the road until you get to the castle. It looks evil and terrifying from the outside, but you are
                  \nconfident in your abilities, and manage to get inside through the doors.
                  \nApproaching the stairs to ascend to the castle’s higher levels, something catches your eye." << endl << endl;
        }
        else if (eventsPassed == 2) { /* SECOND STORY PROMPT */
          cout << endl;
          cout << "As you move around the upper floors looking for a way to get to the top of the castle, which is where 
                  \nthe sorcerer’s throne room is, you hear something in the distance. It sounds like a scream; someone must be in need!
                  \nDo you go and help them?" << endl << endl;

          cout << "What would you like to do?" << endl;
          cout << "1 - Investigate the scream" << endl;
          cout << "2 - Keep progressing" << endl;
          while (!validInputTaken) {
            cout << ">> ";
            cin >> storyChoice;
            if (storyChoice == 1 || storyChoice == 2) {
                  validInputTaken = true;
            } else {
                cout << "Please input either 1 or 2." << endl;
            }
          }
          if (storyChoice == 1) {
            cout << endl;
            cout << "You reach the source of the scream and find an old man, chained up to the wall. After freeing him, he thanks you and
                    \nexplains that he too was here to try to stop the sorcerer, but he failed as the sorcerer had a secret effigy that
                    \nprevented him from dying in battle. He tells you that he will join you to destroy the effigy as you fight the
                    \nsorcerer. You proceed to the final flight of stairs in the castle; the sorcerer’s throne room is just above.
                    \nJust before you make the ascent to the top however, you notice something." << endl << endl;
            changePath(1);
          }
          if (storyChoice == 2) {
            cout << endl;
            cout << "You don’t investigate the scream; it was more than likely a trap or trick set up by the sorcerer. You proceed
                    \nto the final flight of stairs in the castle; the sorcerer’s throne room is just above. Just before you make the
                    \nascent to the top however, you notice something." << endl << endl;
            changePath(2);
          }
        }
        else if (eventsPassed == 3) { /* THIRD STORY PROMPT */
          cout << endl;
          cout << "You proceed to the sorcerer’s throne room and see the wicked figure seated in his gilded throne. He says nothing,
                 \nas he knows why you are here, and instead prepares for battle, laughing maniacally. The challenge is at hand,
                  \nprepare for battle!" << endl << endl;
        }
        if(currentEvent->gameResult()){
            delete currentEvent;
            --numOfStoriesToRun;
            return;
        }
        delete currentEvent;
        --numOfStoriesToRun;
    }

    runFinalChallenge();
    cout << "CONGRATULATIONS! YOU HAVE BEAT THE BOSS" << endl;
}

void GameSystem::runFinalChallenge(){
    std::vector<Enemy> boss;
    Enemy b1(200, 15, 20, 60, "Archmage");
    boss.push_back(b1);
    Battle bossFight(&boss, player);

    bossFight.initiateBattle();
    if (getPath() == 1) {
      cout << "You land the final blow on the mage. He stumbles around, laughing, still confident that the trick the old man
              \ntold you about will work yet again. He is frozen in terror, however, as the old man walks into the room with the
              \ndestroyed effigy in hand. The sorcerer shrieks in rage, and then collapses, dead. The lands are now free of his
              \nwicked presence, and you have secured the future for you and your village." << endl << endl << endl; /* GOOD ENDING */
    }
    else {
      cout << "You land the final blow on the mage. He stumbles around, laughing, then collapses. You know you have finished
              \nyour adventure and secured a bright future for the land, but, to your horror, the sorcerer gets back up, unscathed,
              \nand already in the process of casting a spell. He somehow managed to resurrect himself! The last thing you hear
              \nis his evil laugh, as his wicked, terrifying, lightning puts an end to you. This land was not saved after all." << endl << endl << endl; /* BAD ENDING */
    }
}




//GAME.HPP LOLOLOLOLOLOLLOLOLOLOLOLOLLOLOLOLOLOLOLLOLOLOLOLOLOL
#ifndef GAME_HPP
#define GAME_HPP

#include "../header/character.hpp"
#include "../header/player.hpp"
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
    	vector<Player> playableCharacter;
    	int currentPlayer;
		vector<Event*> listOfStories;
		Character* player;


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
    
    	// getter functions:
    	inline bool getGameStatus() const {return this->gameStatus;}

		//load Stories
		void loadStories();
		void runGame();

};

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
};

#endif




//GAME.CPP
#include "../header/game.hpp"

using namespace std;

Game::Game() {
    mainMenuChoice = 'q';
    gameStatus = true;          // indicates whether the game is active or not
    playerMenuStatus = true;    // used when player accesses the player menu
    quitGameChoice = 'q';	// used when player choose to quit game via player menu
    currentPlayer = 0;
}

Game::~Game() {
}

void Game::mainMenu() {
    cout << "╔══════════════════════════════════ Rogue Origins ══════════════════════════════════╗" << endl;
    cout << endl;
    cout << "                                      Main Menu" << endl << endl;
    cout << "                                  [S] - Start Game" << endl;
    cout << "                                  [I] - Instructions" << endl;
    cout << "                                  [Q] - Quit Game" << endl;
    cout << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════════════╝" << endl;

    cout << endl;
    cout << "Your choice: ";
    cin >> mainMenuChoice;

    switch(mainMenuChoice) {
        case 'S' :
        case 's' :
            continueGame();
            break;
        case 'I' :
        case 'i' :
            printInstructions();
            break;
        case 'Q' :
        case 'q' :
            cout << "Quitting game..." << endl;
            gameStatus = false;
            break;
        default :
            cout << endl;
            cout << "Please select a valid option (S, I, Q)." << endl;
            cout << endl;
            mainMenu();
    }
}

void Game::printInstructions() {
    string userInput = "";

    cout << endl;
    cout << "Welcome to the world of Rogue Origins, traveler." << endl;
    cout << "Below you will find the rules that govern this game: " << endl;
    cout << "1. Placeholder" << endl;
    cout << "2. Placeholder" << endl;
    cout << "3. Placeholder" << endl;
    cout << "4. Placeholder" << endl;
    cout << "5. Placeholder" << endl;
    cout << endl;

    do {
        cout << "Press the ENTER key to return back to the main menu: ";
        cin.ignore();
        getline(cin, userInput);
        userInput = "";
    } while (userInput.length() != 0);

    cout << endl;
    mainMenu();
}

void Game::continueGame() {
    string characterName = "";

    cout << endl;
    cout << "Welcome to Rogue Origins." << endl;
    cout << "Please enter the name for your character: ";
    cin.ignore();
    getline(cin, characterName);

    playableCharacter.push_back(Player());
    currentPlayer = playableCharacter.size() - 1;
    playableCharacter[currentPlayer].createInitialPlayer(characterName);

    selectDifficulty();
}

void Game::selectDifficulty() {
    char difficultySelection = '0';

    cout << endl;
    cout << "Hello, " << this->playableCharacter[currentPlayer].getName() << "." << " Please select a difficulty:" << endl;
    cout << "[1] - Easy" << endl;
    cout << "[2] - Medium" << endl;
    cout << "[3] - Hard" << endl;

    cout << endl;
    cout << "Difficulty Selection: ";
    cin >> difficultySelection;

    switch (difficultySelection)
    {
    case '1':
        cout << endl;
        cout << "You have chosen the EASY difficulty." << endl;
        cout << "Good luck and safe journeys, " << this->playableCharacter[currentPlayer].getName() << "." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeEasy(this->playableCharacter[currentPlayer].getName());
	while(playerMenuStatus) {
		playerMenu();
	}
        break;
    case '2':
        cout << endl;
        cout << "You have chosen the MEDIUM difficulty." << endl;
        cout << "Good luck and safe journeys, " << this->playableCharacter[currentPlayer].getName() << "." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeMedium(this->playableCharacter[currentPlayer].getName());
        while(playerMenuStatus) {
		playerMenu();
	}
	break;
    case '3':
        cout << endl;
        cout << "You have chosen the HARD difficulty." << endl;
        cout << "Good luck, " << this->playableCharacter[currentPlayer].getName() << ", you're gonna need it..." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeHard(this->playableCharacter[currentPlayer].getName());
        while(playerMenuStatus) {
		playerMenu();
	}
	break;
    default:
        cout << endl;
        cout << "Please enter a valid difficulty (1-3)." << endl;
        selectDifficulty();
    }
}

void Game::playerMenu() {
	cout << "┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ PLAYER MENU ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑" << endl;
	cout << endl;
	cout << "			       Select an option: " << endl;
	cout << "			      [P] - View Player Stats" << endl;
	cout << "			      [S] - View Shop" << endl;
	cout << "			      [E] - Exit Menu" << endl;
	cout << "			      [Q] - Quit Game" << endl;
	cout << endl;
	cout << "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙" << endl << endl;
	
	cout << "Your choice: ";
	cin >> playerMenuChoice;

	switch(playerMenuChoice) {
	case 'P':
	case 'p':
		playableCharacter[currentPlayer].printPlayerStats();
		break;
	case 'S':
	case 's':
		// printShop(); to display shop function
		playerMenuStatus = false;
		break;
	case 'E':
	case 'e':
		playerMenuStatus = false;
		break;
	case 'Q':
	case 'q':
		quitGamePrompt();
		break;
	default:
	cout << "Please select a valid choice (P, S, E, Q)" << endl;
		playerMenu();
	}
}

void Game::quitGamePrompt() {
	cout << "Are you sure you want to quit the game? (y/n)" << endl;
	cin >> quitGameChoice;
	switch(quitGameChoice) {
	case 'Y':
	case 'y':
		cout << "Quitting game..." << endl;
		playerMenuStatus = false;
		gameStatus = false;
		break;
	case 'N':
	case 'n':
		cout << "You have chosen not to quit the game. Returning back to the Player Menu..." << endl;
		playerMenu();
		break;
	default:
		cout << "Please select a valid choice (y/n)" << endl;
		quitGamePrompt();
	}
}

void Game::loadStories(){
    /* *** LOAD WITH STORIES *** */
    listOfStories.push_back(new Event(true, "You spot a group of enemies, clearly guarding something valuable.", "You walk silently past them, not attracting any attention to your presence.", "You retrieve what they were hiding, and take it for yourself.", "Avoid the enemies", "Charge the enemies", "You charge at the enemies, and they prepare for battle!", player));
    listOfStories.push_back(new Event(true, "You see a gold chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "After defeating them, you open the chest and take what’s inside.", "Walk away", "Open the chest", "You go to open the chest, but are ambushed by a group of enemies!", player));
    listOfStories.push_back(new Event(false, "You see a wooden chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "You open the chest, and find an item!.", "Walk away", "Open the chest", "", player));
}

void Game::runGame(){
    cout << endl;
    cout << "You leave your village on a quest to rid the world of the evil final four archmages who has been terrorizing the lands\nand oppressing the people with their wicked magic for as long as you can remember. With your expert skills,\nyou are sure you can finally stop them. You set off on the road, walking to the sorcerer’s dark castle, until you\ncome across something." << endl << endl;

    int numOfStoriesToRun = listOfStories.size(); 
    int eventsPassed = 0;
    int storyChoice;
    bool validInputTaken = false;
    while(numOfStoriesToRun != 0){
        int randomNumber =  rand() % listOfStories.size();
        Event* currentEvent = listOfStories.at(randomNumber);
        listOfStories.erase(listOfStories.begin() + randomNumber);
        cout << endl;
        //currentEvent->startEvent();
        ++eventsPassed;
        if(eventsPassed == 1) { /* FIRST STORY PROMPT */
          cout << endl;
          cout << "You proceed on the road until you get to the castle. It looks evil and terrifying from the outside, but you are\nconfident in your abilities, and manage to get inside through the doors.\nApproaching the stairs to ascend to the castle’s higher levels, something catches your eye." << endl << endl;
        }
        else if (eventsPassed == 2) { /* SECOND STORY PROMPT */
          cout << endl;
          cout << "As you move around the upper floors looking for a way to get to the top of the castle, which is where 
                  \nthe sorcerer’s throne room is, you hear something in the distance. It sounds like a scream; someone must be in need!
                  \nDo you go and help them?" << endl << endl;

          cout << "What would you like to do?" << endl;
          cout << "1 - Investigate the scream" << endl;
          cout << "2 - Keep progressing" << endl;
          while (!validInputTaken) {
            cout << ">> ";
            cin >> storyChoice;
            if (storyChoice == 1 || storyChoice == 2) {
                  validInputTaken = true;
            } else {
                cout << "Please input either 1 or 2." << endl;
            }
          }
          if (storyChoice == 1) {
            cout << endl;
            cout << "You reach the source of the scream and find an old man, chained up to the wall. After freeing him, he thanks you and
                    \nexplains that he too was here to try to stop the sorcerer, but he failed as the sorcerer had a secret effigy that
                    \nprevented him from dying in battle. He tells you that he will join you to destroy the effigy as you fight the
                    \nsorcerer. You proceed to the final flight of stairs in the castle; the sorcerer’s throne room is just above.
                    \nJust before you make the ascent to the top however, you notice something." << endl << endl;
            changePath(1);
          }
          if (storyChoice == 2) {
            cout << endl;
            cout << "You don’t investigate the scream; it was more than likely a trap or trick set up by the sorcerer. You proceed
                    \nto the final flight of stairs in the castle; the sorcerer’s throne room is just above. Just before you make the
                    \nascent to the top however, you notice something." << endl << endl;
            changePath(2);
          }
        }
        else if (eventsPassed == 3) { /* THIRD STORY PROMPT */
          cout << endl;
          cout << "You proceed to the sorcerer’s throne room and see the wicked figure seated in his gilded throne. He says nothing,
                 \nas he knows why you are here, and instead prepares for battle, laughing maniacally. The challenge is at hand,
                  \nprepare for battle!" << endl << endl;
        }
        if(currentEvent->gameResult()){
            delete currentEvent;
            --numOfStoriesToRun;
            return;
        }
        delete currentEvent;
        --numOfStoriesToRun;
    }

    runFinalChallenge();
    cout << "CONGRATULATIONS! YOU HAVE BEAT THE BOSS" << endl;
}

