#include "../header/game.hpp"

using namespace std;

int main() {
    Game game;

    while(game.getGameStatus()) {
        game.mainMenu();
    }
    return 0;
}
