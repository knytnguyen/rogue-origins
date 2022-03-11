#include "../header/game.hpp"

using namespace std;

Game::Game() {
    mainMenuChoice = 'q';
    gameStatus = true;          // indicates whether the game is active or not
    playerMenuStatus = true;    // used when player accesses the player menu
    quitGameChoice = 'q';	// used when player choose to quit game via player menu
    finalBattleStatus = true;   // used when player battles archmage
    currentPlayer = 0;
}

//Game::~Game() {}

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
    cout << "In this mysterious world, you are left to fend for yourself against the almighty Archmage, " << endl;
    cout << "a powerful wizard with immense magic spells and power. Here are the rules of the game:" << endl << endl;
    cout << "1. Selecting the Difficulty Level (1-3) will initialize your stats in respect to the difficulty you have chosen." << endl;
    cout << "2. When spawned into the world, you are immediately greeted by the Archmage." << endl;
    cout << "3. You have 2 options: Attack or access your Menu to fight." << endl;
    cout << "4. Attacking the Archmage will prompt an immediate attack back, choose wisely." << endl;
    cout << "5. By defeating the Archmage, you will fully complete the game. Otherwise, you must start all over." << endl;
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
	    runGame();	
        break;
    case '2':
        cout << endl;
        cout << "You have chosen the MEDIUM difficulty." << endl;
        cout << "Good luck and safe journeys, " << this->playableCharacter[currentPlayer].getName() << "." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeMedium(this->playableCharacter[currentPlayer].getName());
        runGame();
	break;
    case '3':
        cout << endl;
        cout << "You have chosen the HARD difficulty." << endl;
        cout << "Good luck, " << this->playableCharacter[currentPlayer].getName() << ", you're gonna need it..." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeHard(this->playableCharacter[currentPlayer].getName());
        runGame();
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
		finalBattleStatus = false;
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
          cout << "As you move around the upper floors looking for a way to get to the top of the castle, which is where \nthe sorcerer’s throne room is, you hear something in the distance. It sounds like a scream; someone must be in need!\nDo you go and help them?" << endl << endl;

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
            cout << "You reach the source of the scream and find an old man, chained up to the wall. After freeing him, he thanks you and\nexplains that he too was here to try to stop the sorcerer, but he failed as the sorcerer had a secret effigy that\nprevented him from dying in battle. He tells you that he will join you to destroy the effigy as you fight the\nsorcerer. You proceed to the final flight of stairs in the castle; the sorcerer’s throne room is just above.\nJust before you make the ascent to the top however, you notice something." << endl << endl;
            changePath(1);
          }
          if (storyChoice == 2) {
            cout << endl;
            cout << "You don’t investigate the scream; it was more than likely a trap or trick set up by the sorcerer. You proceed\nto the final flight of stairs in the castle; the sorcerer’s throne room is just above. Just before you make the \nascent to the top however, you notice something." << endl << endl;
            changePath(2);
          }
        }
        else if (eventsPassed == 3) { /* THIRD STORY PROMPT */
          cout << endl;
          cout << "You proceed to the sorcerer’s throne room and see the wicked figure seated in his gilded throne. He says nothing,\nas he knows why you are here, and instead prepares for battle, laughing maniacally. The challenge is at hand,\nprepare for battle!" << endl << endl;
        }
        if(currentEvent->gameResult()){
            delete currentEvent;
            --numOfStoriesToRun;
            return;
        }
        delete currentEvent;
        --numOfStoriesToRun;
    }

    //run Archmage Fight Here
    archmageBattle();
}



void Game::archmageBattle() {
	finalBattleStatus = true;
	cout << endl;
	cout << "The Archmage has appeared! Get ready for the battle!" << endl;
	// while (finalBattleStatus) {
	//	playerBattleInterface();				
	// }
	playerBattleInterface(); 
}

void Game::playerBattleInterface() {
	Archmage* finalBoss = new Archmage();
	Player* ptrToPlayer = &playableCharacter[currentPlayer];
	while (finalBattleStatus) {
	char battleChoice;
        cout << endl;
        cout << "Battle Interface" << endl;
        cout << "[A] - Attack" << endl;
        cout << "[M] - Open Menu" << endl << endl;
        // cout << "What would you like to do?: ";
        // cout << endl;
	
        if (finalBoss->getHealth() <= 0) {
                cout << "You have defeated the Archmage!" << endl;
                cout << "Congrats, you have beaten the game!" << endl;
                finalBattleStatus = false;
                gameStatus = false;
        }
	else if (playableCharacter[currentPlayer].getHealth() <= 0) {
		cout << playableCharacter[currentPlayer].getName() << " has been slain by the Archmage!" << endl;
        cout << "GAME OVER" << endl;
		finalBattleStatus = false;
		gameStatus = false;
	}

	else {
	cout << "What would you like to do?: ";
        cin >> battleChoice;
	cout << endl;

        switch(battleChoice) {
        	case 'A':
        	case 'a':
                	playableCharacter[currentPlayer].attack(finalBoss);
                	cout << endl;
                	cout << this->playableCharacter[currentPlayer].getName() << " deals a whopping " << this->playableCharacter[currentPlayer].getAttackPower() << " damage to the Archmage." << endl;
                	cout << "The Archmage is left with: " << finalBoss->getHealth() << " HP." << endl;
			cout << endl;
			cout << endl;
        		finalBoss->attack(ptrToPlayer);
        		cout << "Oh no!" << endl;
        		cout << "The Archmage attacks, dealing an immense " << finalBoss->getArchmageAttackPower() << " damage to " << ptrToPlayer->getName() << "!" << endl;
        		cout << this->playableCharacter[currentPlayer].getName() << " has " << ptrToPlayer->getHealth() << " HP remaining." << endl;
                	break;
        	case 'M':
        	case 'm':
                	playerMenuStatus = true;
                	while(playerMenuStatus) {
                        	playerMenu();
                	}
                	break;
        	default:
                	cout << "Please select a valid option. (A, M)" << endl;
        	}
	    }
    }
    delete finalBoss;
}

