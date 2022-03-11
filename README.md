
# Rogue Origins (A Text-Based RPG) ![Badge](https://img.shields.io/badge/build-passing-brightgreen)
 
 > Authors: [Kenny Nguyen](https://github.com/knytnguyen), [Carine Tham](https://github.com/carinetham), [Ethan Hsu](https://github.com/ehsu092), [Alvin Vo](https://github.com/alvin-vo)
 
 
## Project Description

> Rogue Origins is a text-based role-playing game (RPG) where the player controls their virtual character through a virtual world. Set in a medieval time with fantasy characters, enemies, and weapons, the player progresses through the world of Rohendel with the end goal of defeating the four bosses that terrorize the continent. 
This is an interesting and important project for us because it gives us the opportunity to implement a program that gives the players opportunities to explore through a narrative while exploring and strengthening our fundamentals such as data structures, algorithms, and system design skills. Creating a text-based RPG in C++ allows us to not only formulate how to design and integrate many different moving pieces together, but it also allows us to create a narrative and express ourselves creatively for others to explore as well which is why this project is so interesting for us. 

> For our game, we plan to use the following languages and tools that have been learned throughout this class.
* C++ - Programming Language
* Git – The version control software to accelerate collaboration and handle files
* Github – Online Repository Storage and File Hosting Service
* PuTTY – Client and Terminal
* CMake – Software Compiler, Tester, and Builder
* Vim – Text Editor for PuTTY
* Valgrind – Memory Debugging and Leak Detection Tool
* GoogleTest – Testing Framework

> In Rogue Origins, to control your character and explore Rohendel, the player will be putting in user selections. The player can customize their character to best represent themselves and as they progress through the narrative, they’ll have to battle their way through a turn-based system against enemies. Stats like health, attack power, and their defense will have to be monitored as they fight their way to completion. In the end, the player will have to use all their accumulated knowledge and items to beat the last obstacle to victory. The Final Four.

> When it comes to staying organized and implementing these features, we are using a composite design pattern. By using classes specific to each feature, we give each class specific elements and utilize the classes and the objects they make into other classes. In our turn-based combat, the enemy system class will go through which enemy to fight, as well as determining the attack power of those enemies. To spice up each playthrough and each dungeon, the rand() function is used to make each dungeon unique.  


## Class Diagram

 > ![Rogue Origins UML Diagram](https://user-images.githubusercontent.com/74081658/157890366-d8d038ac-b1ef-4743-b053-d1b3ade5f6b4.png)
 
 > **Class Diagram Description:** 
 > Set in a text-based RPG in medieval times with fantasy characters and enemies, the user interacts with the Origin System by choosing character specific attacks, managing their health and resources to follow through a story. The player makes their choices as they take turns fighting the enemy until defeated. After each completed dungeon, the player can obtain the enemy’s loot as well as access a shop to stock back up on resources.

 ## Screenshots
 > ***Main Menu:*** 
 > 
 > <img src="https://user-images.githubusercontent.com/97259950/157841718-fa55ed75-0cab-4052-9354-6c242c9294ab.png" width="10000" height="550">

 > ***Player Menu:***
 >
 ><img src="https://cdn.discordapp.com/attachments/935084367720624168/951776092514025582/unknown.png" width="10000" height="550">

 > ***Gameplay:***
 > 
 >![Gameplay RO](https://cdn.discordapp.com/attachments/279448838245187584/951847761618280588/unknown.png)


 ## Installation/Usage
 > Rogue Origins will be ran through PuTTY through the terminal emulator serial console. To check for test cases, it will be using CMake to compile and test those specific values in the game. After cloning the files into PuTTY, one needs to compile the program using CMake by typing these commands in order: (cmake3 .) (make) (./test). Doing so will bring you to the test cases results that presents features within our system and if it is performing as expected. To begin the journey into Rogue Origins, one can simply run the a.exe (or a.out) and they will be summoned into the land of Rohendel.
 ## Testing ![image](https://user-images.githubusercontent.com/97259950/157893479-b2c58c27-72da-463d-b52a-ee26128cc925.png)

 > This project was tested and validated through continuous intergration (CI). When working on the project, we set aside time in each of our schedules to work on the project together so that everything that is done on the project, everyone is there to see it. Combine that with constant pushes into the branches allowed us to be able to keep track of what's going on at basically all times. The project was tested through valgrind in PuTTy through a linux terminal, as well as through github workflow to make sure everyone had access for testing. 
 
