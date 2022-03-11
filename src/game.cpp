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
	archmageBattle();	
        break;
    case '2':
        cout << endl;
        cout << "You have chosen the MEDIUM difficulty." << endl;
        cout << "Good luck and safe journeys, " << this->playableCharacter[currentPlayer].getName() << "." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeMedium(this->playableCharacter[currentPlayer].getName());
        archmageBattle();
	break;
    case '3':
        cout << endl;
        cout << "You have chosen the HARD difficulty." << endl;
        cout << "Good luck, " << this->playableCharacter[currentPlayer].getName() << ", you're gonna need it..." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeHard(this->playableCharacter[currentPlayer].getName());
        archmageBattle();
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

void Game::archmageBattle() {
	finalBattleStatus = true;
	cout << endl;
	cout << "The Archmage has appeared! Get ready for the battle!" << endl;
	while (finalBattleStatus) {
		playerBattleInterface();				
	} 
}

void Game::playerBattleInterface() {
	Archmage* finalBoss = new Archmage();
	char battleChoice;
	cout << endl;
	cout << "Battle Interface" << endl;
	cout << "[A] - Attack" << endl;
	cout << "[M] - Open Menu" << endl << endl;
	cout << "What would you like to do?: ";
	cout << endl;

	if (finalBoss->getHealth() <= 0) {
		cout << "You have defeated the Archmage!" << endl;
		cout << "Congrats!" << endl;
		finalBattleStatus = false;
		gameStatus = false;		
	}

	cin >> battleChoice;

	switch(battleChoice) {
	case 'A':
	case 'a':
		playableCharacter[currentPlayer].attack(finalBoss);
		cout << endl;
		cout << this->playableCharacter[currentPlayer].getName() << " deals a whopping " << this->playableCharacter[currentPlayer].getAttackPower() << " damage to the Archmage." << endl;
		cout << "The Archmage is left with: " << finalBoss->getHealth() << " HP." << endl;
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
