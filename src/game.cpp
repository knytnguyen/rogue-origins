#include "../header/game.hpp"

using namespace std;

Game::Game() {
    userMenuChoice = 'q';
    gameStatus = true;          // indicates whether the game is active or not
    currentPlayer = 0;
}

Game::~Game() {
}

void Game::mainMenu() {
    cout << "|=============================== Rogue Origins ===============================|" << endl;
    cout << endl;
    cout << "                                   Main Menu" << endl;
    cout << "                               s - Start Game" << endl;
    cout << "                               i - Instructions" << endl;
    cout << "                               q - Quit Game" << endl;
    cout << endl;
    cout << "|=============================================================================|" << endl;

    cout << endl;
    cout << "Your choice: ";
    cin >> userMenuChoice;

    switch(userMenuChoice) {
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
            cout << "Please enter a valid input (s, i, q)." << endl;
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
        break;
    case '2':
        cout << endl;
        cout << "You have chosen the MEDIUM difficulty." << endl;
        cout << "Good luck and safe journeys, " << this->playableCharacter[currentPlayer].getName() << "." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeMedium(this->playableCharacter[currentPlayer].getName());
        break;
    case '3':
        cout << endl;
        cout << "You have chosen the HARD difficulty." << endl;
        cout << "Good luck, " << this->playableCharacter[currentPlayer].getName() << ", you're gonna need it..." << endl;
        cout << endl;
        this->playableCharacter[currentPlayer].initializeHard(this->playableCharacter[currentPlayer].getName());
        break;
    default:
        cout << endl;
        cout << "Please enter a valid difficulty (1-3)." << endl;
        selectDifficulty();
    }
}
