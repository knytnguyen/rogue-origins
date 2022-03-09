#include "GameSystem.hpp"

void GameSystem::loadStories(){
    /* *** LOAD WITH STORIES *** */
    listOfStories.push_back(new Event(true, "You spot a group of enemies, clearly guarding something valuable.", "You walk silently past them, not attracting any attention to your presence.", "You retrieve what they were hiding, and take it for yourself.", "Avoid the enemies", "Charge the enemies", "You charge at the enemies, and they prepare for battle!", player));
    listOfStories.push_back(new Event(true, "You see a gold chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "After defeating them, you open the chest and take what’s inside.", "Walk away", "Open the chest", "You go to open the chest, but are ambushed by a group of enemies!", player));
    listOfStories.push_back(new Event(false, "You see a wooden chest, sitting alone in a room.", "You walk away from the chest, unsure if it is a trap.", "You open the chest, and find an item!.", "Walk away", "Open the chest", "", player));
}

