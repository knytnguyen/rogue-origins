#include "../header/shop.hpp"
#include "../header/character.hpp"
#include "../header/player.hpp"
#include "../header/shopItem.hpp"
#include "../header/PurchaseStrategy.hpp"
#include "../header/game.hpp"

using namespace std;


void Shop::displayItems(Player* player) {
    int shopChoice, buyChoice;
    Healing_Potion hp;
    Strength_Potion sp;
    Sword_Upgrade su;
    Shield_Upgrade shu;

    cout << "|=============================== Shop ====================================================================================================================|" << endl;
    cout << endl;
    cout << "                      1 - Healing Potion: " << hp.getPrice() << " coins               Heals " << hp.getHealth() << " hp" << endl;
    cout << "                      2 - Strength Potion: " << sp.getPrice() << " coins              Multiplies the character's damage by " << sp.getAttackPower() << endl;
    cout << "                      3 - Sword Upgrade: " << su.getPrice() << " coins                Permanently increases sword damage by " << su.getSword() << endl;
    cout << "                      4 - Shield Upgrade: " << shu.getPrice() << " coins               Permanently increases defense by " << shu.getDef() << endl;
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
            buyItem(buyChoice, player);
        }
        else {
            cout << "Invalid item" << endl;
            cout << "Going back to shop menu..." << endl;
        }
        displayItems(player);
        break;
    case 6:
        playerMenu();
        break;
    default:
        cout << endl;
        cout << "Please enter a valid input" << endl;
        cout << endl;
        displayItems(player);
    }
}


void Shop::buyItem(int buyChoice, Player* player) {
    PurchaseStrategy ps;
    switch (buyChoice) {
    case 1: {
        Shop* potion = new Healing_Potion();
        if (ps.increaseStat(player, potion) == true)
            cout << "Bought Healing Potion!" << endl; 
        break;
    }
    case 2: {
        Shop* strength = new Strength_Potion();
        if (ps.increaseStat(player, strength) == true)
            cout << "Bought Strength Potion!" << endl; 
        break;
    }
    case 3: {
        Shop* swordUp = new Sword_Upgrade();
        if (ps.increaseStat(player, swordUp) == true)
            cout << "Bought Sword Upgrade!" << endl; 
        break;
    }
    case 4: {
        Shop* shieldUp = new Shield_Upgrade();
        if (ps.increaseStat(player, shieldUp) == true)
            cout << "Bought Shield Upgrade!" << endl; 
        break;
        }
    }
    
}