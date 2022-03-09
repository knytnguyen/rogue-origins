#include "GameSystem.hpp"

void GameSystem::loadStories(){
    /* *** LOAD WITH STORIES *** */
    listOfStories.push_back(new Event(true, "You spot a group of enemies, clearly guarding something valuable.", "You walk silently past them, not attracting any attention to your presence.", "You retrieve what they were hiding, and take it for yourself.", "Avoid the enemies", "Charge the enemies", "You charge at the enemies, and they prepare for battle!", player));
    listOfStories.push_back(new Event(true, "You see a gold chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "After defeating them, you open the chest and take what’s inside.", "Walk away", "Open the chest", "You go to open the chest, but are ambushed by a group of enemies!", player));
    listOfStories.push_back(new Event(false, "You see a wooden chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "You open the chest, and find an item!.", "Walk away", "Open the chest", "", player));
}

void GameSystem::runGame(){
    cout << endl;
    cout << "You leave your village on a quest to rid the world of the four evil mages who has been terrorizing the lands\nand oppressing the people with their wicked magic for as long as you can remember. With your expert skills,\nyou are sure you can finally stop him. You set off on the road, walking to the sorcerer’s dark castle, until you\ncome across something." << endl << endl;

    /* *** CAN BE CHANGED TO VARY LENGTH OF GAME. *** */
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
          cout << "You proceed on the road until you get to the castle. It looks evil and terrifying from the outside, but you are\nconfident in your abilities, and manage to get inside through the doors.\nApproaching the stairs to ascend to the castle’s higher levels, something catches your eye." << endl << endl;
        }
        else if (eventsPassed == 2) { /* SECOND STORY PROMPT */
          cout << endl;
          cout << "As you move around the upper floors looking for a way to get to the top of the castle, which is where\nthe sorcerer’s throne room is, you hear something in the distance. It sounds like a scream; someone must be in need!\nDo you go and help them?" << endl << endl;
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
            cout << "You don’t investigate the scream; it was more than likely a trap or trick set up by the sorcerer. You proceed\nto the final flight of stairs in the castle; the sorcerer’s throne room is just above. Just before you make the\nascent to the top however, you notice something." << endl << endl;
            changePath(2);
          }
        }
        else if (eventsPassed == 3) { /* THIRD STORY PROMPT */
          cout << endl;
          cout << "You proceed to the sorcerer’s throne room and see the wicked figure seated in his gilded throne. He says nothing,\nas he knows why you are here, and instead prepares for battle, laughing maniacally. Your final challenge is at hand,\nprepare for battle!" << endl << endl;
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
    cout << "CONGRATULATIONS! YOU HAVE REACHED THE END OF THE GAME!" << endl;
}

void GameSystem::runFinalChallenge(){
    std::vector<Enemy> boss;
    Enemy b1(200, 15, 20, 60, "Sorcerer");
    boss.push_back(b1);
    Battle bossFight(&boss, player);

    bossFight.initiateBattle();
    if (getPath() == 1) {
      cout << "You land the final blow on the sorcerer. He stumbles around, laughing, still confident that the trick the old man\ntold you about will work yet again. He is frozen in terror, however, as the old man walks into the room with the\ndestroyed effigy in hand. The sorcerer shrieks in rage, and then collapses, dead. The lands are now free of his\nwicked presence, and you have secured the future for you and your village." << endl << endl << endl; /* GOOD ENDING */
    }
    else {
      cout << "You land the final blow on the sorcerer. He stumbles around, laughing, then collapses. You know you have finished\nyour adventure and secured a bright future for the land, but, to your horror, the sorcerer gets back up, unscathed,\nand already in the process of casting a spell. He somehow managed to resurrect himself! The last thing you hear\nis his evil laugh, as his wicked, terrifying, lightning puts an end to you. This land was not saved after all." << endl << endl << endl; /* BAD ENDING */
    }
}
