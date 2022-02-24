#include "../header/game.hpp"

using namespace std;

Game::Game() {
    userMenuChoice = 'q';
    gameStatus = true;  // indicates whether the game is active or not
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
            gameStatus = true;
            break;
        case 'I' :
        case 'i' :
            gameStatus = true;
            break;
        case 'Q' :
        case 'q' :
            cout << "Quitting game..." << endl;
            gameStatus = false;
            break;
        default :
            cout << endl;
            cout << "Please enter a valid input" << endl;
            cout << endl;
            mainMenu();
    }
}
