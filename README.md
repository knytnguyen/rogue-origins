# Rogue Origins (A Text-Based RPG)
 
 > Authors: [Kenny Nguyen](https://github.com/knytnguyen), [Carine Tham](https://github.com/carinetham), [Ethan Hsu](https://github.com/ehsu092), [Alvin Vo](https://github.com/alvin-vo)
 
 
## Project Description

> Rogue Origins is a text-based role-playing game (RPG) where the player controls their personally defined character through a virtual world. Set in a medieval time with fantasy characters, enemies, and weapons, the player progresses through the world of Rohendel with the end goal of defeating the four bosses that terrorize the continent. 
This is an interesting and important project for us because it gives us the opportunity to implement a program that gives the players opportunities to explore through a narrative while exploring and strengthening our fundamentals such as data structures, algorithms, and system design skills. Creating a text-based RPG in C++ allows us to not only formulate how to design and integrate many different moving pieces together, but it also allows us to create a narrative and express ourselves creatively for others to explore as well which is why this project is so interesting for us. 

> For our game, we plan to use the following languages and tools that have been learned throughout this class.
* C++ - Programming Language
* Git – The version control software to accelerate collaboration and handle files
* GitHub – Online Repository Storage and File Hosting Service
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

 > ***Instructions:***
 > 
 >![](images/instructions.png)

 > ***Story Introduction:***
 > 
 >![](images/story%20introduction.png)

 > ***Finishing Attack:***
 > 
 > ![](images/finishing%20attack.png)

 > ***Victory / Game Over Screens***
 > 
 > ![](images/victory.png)
 > 
 > ![](images/game%20over.png)


 ## Installation/Usage
 > Rogue Origins will be ran through PuTTY through the terminal emulator serial console. To check for test cases, it will be using CMake to compile and test those specific values in the game. After cloning the files into PuTTY, one needs to compile the program using CMake by typing these commands in order: 
 > ```
 > cmake3 . 
 > make 
 > ./test
 > ```
 > Doing so will bring you to the test cases results that presents features within our system and if it is performing as expected. To begin the journey into Rogue Origins, one can simply run the a.exe (or a.out) and they will be summoned into the land of Rohendel.
 ## Testing ![Badge](https://img.shields.io/badge/build-passing-brightgreen)
 > This project was tested and validated through continuous intergration (CI). When working on the project, we set aside time in each of our schedules to work on the project together so that everything that is done on the project, everyone is there to see it. Combine that with constant pushes into the branches allowed us to be able to keep track of what's going on at basically all times. The project was tested through valgrind in PuTTy through a linux terminal, as well as through github workflow to make sure everyone had access for testing. 
 


# Full Project Instructions Below





 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
 
 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list, start thinking about the features you will implement, what design patterns can help you implement them, and why. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). Your project needs to implement at least one design pattern iteratively, which you will have to justify in later phases.The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings. While Daily Scrums are not required we highly encourage you to practice them.

 
 > ## Expectations
 > * Incorporate **at least one** design pattern
 >   * It is recommended that you include a design pattern that we will teach this session (Composite, Strategy, or Visitor)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * Each member of the group must actively participate in the Github Project board and reviewing commited code.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two scrum/check-in meetings with your lab TA/reader in two different weeks in addition to the final demo.


## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you?
 >   * This project is important to us because it allows us to further explore and strengthen many fundamental data structures, algorithm, and system design skills in a fun and interactive way through various design patterns. Creating a text-based RPG in C++ allows us to not only formulate how to design and integrate many different moving pieces together, but it also allows us to create our own narrative and express ourselves creatively which is why this project is also so interesting to us.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++
 > * What will be the input/output of your project? What are the features that the project provides?
 >   * The input will consist of a user selecting different options of what they want to do in the game including attack, run, access inventory, use a heal item, quit game, etc. The output of the game will have texts that reflect what the user selects along with a story that follows with what the user selects.
 >   * The features that the game provides include a menu that allows the user to select what to do in game and an engaging and choice-driven story.
 > 
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board by choosing the  “Automated kanban with review” option on Github. You should also have a Backlog and In testing columns added.

## Class Diagram
 > **Class Diagram Description:**
 > The project's goal is to set a text-based RPG set in medieval times with fantasy characters, enemies and weapons with the end goal getting to the final four bosses. The main class that mostly every other class goes to is the Character Class. When the game first starts, we have it go to the Main Menu, and from there it connects to the character class. From there, when fighting a enemy, it tells the Character class on the stats of the enemy, as well as the type of enemy, with each one set with different values. The different rooms corrospond with the enemies for the rooms determine what kind and how mnay enemies of each. In the different rooms, there will be a shop room for the player to take a break and recover, displaying items for the player to purchase to help make their adventure easier.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with a reader (using Calendly). Your entire team must be present. This meeting will occur on week 8 but NOT during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
