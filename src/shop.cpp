#include "../header/shop.hpp"

using namespace std;

Shop::Shop() {
    
}

Shop::~Shop() {
}

void Shop::displayItems() const {
    int shopChoice, buyChoice;
   // Item *hp = new Healing_Potion();
   // cout << hp->getPrice() << hp->getItemDetails();

    cout << "|=============================== Shop ====================================================================================================================|" << endl;
    cout << endl;
    cout << "                      1 - Healing Potion: 30 coins               Heals 60 hp" << endl;
    cout << "                      2 - Strength Potion: 20 coins              Multiplies the character's damage by 1.5 for an entire round" << endl;
    cout << "                      3 - Sword Upgrade: 50 coins                Permanently increases sword damage by 50" << endl;
    cout << "                      4 - Shield Upgrade: 50 coins               Permanently increases shield health by 50" << endl;
    cout << "                      5 - Buy Item" << endl;
    cout << "                      6 - Exit Shop" << endl;
    cout << endl;
    cout << "|=========================================================================================================================================================|" << endl;

    cout << "Shop choice: ";
    cin >> shopChoice;

    switch (shopChoice) {
    case 5:
        cout << "What item do you want to purchase? ";
        cin >> buyChoice;
        if (buyChoice == 1 || buyChoice == 2 || buyChoice == 3 || buyChoice == 4) {
            buyItem(buyChoice);
        }
        else {
            cout << "Invalid item" << endl;
            cout << "Going back to shop menu..." << endl;
            displayItems();
        }
        break;
    case 6:
        closeShop();
        break;
    default:
        cout << endl;
        cout << "Please enter a valid input" << endl;
        cout << endl;
    }
}

void Shop::viewPrice(int shopChoice) const {
}

void Shop::viewItemDetails(int shopChoice) const {
}

void Shop::buyItem(int buyChoice /*, *Player player */) const {
    switch (buyChoice) {
    case 1: 
        cout << "Bought Healing Potion; subtract coins from player" << endl; //subtract coins from player->coins
       // Item* h = new Healing_Potion();
       // items.push_back(h);
        break;
    case 2: 
        cout << "Bought Strength Potion; subtract coins from player" << endl; //subtract coins from player->coins
        break;
    case 3:
        cout << "Bought Sword Upgrade; subtract coins from player" << endl; //subtract coins from player->coins
        break;
    case 4:
        cout << "Bought Shield Upgrade; subtract coins from player" << endl; //subtract coins from player->coins
        break;
    }
    displayItems();
}

void Shop::closeShop() const {
   // go back to player class when made
}


