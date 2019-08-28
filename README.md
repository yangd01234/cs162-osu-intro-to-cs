# osu-intro-to-cs
Collection of work from Fall 2017 Introduction to Computer Science (CS 162) course at Oregon State University.

## Project 1 - Langston's Ant (C++11)
Implementation of langston's ant using 2d arrays.  An Ant is placed on a board with n number of rows and columns.

For each step forward, the Ant will:
1.  If the ant is on a white space, turn right 90 degrees and change the space to black.
2.  If the ant is on a black space, turn left 90 degrees and change the space to white.

After that the ant moves to the next step and continue moving forward. The ant will follow these rules, and continue moving 
around the board, until the number of steps runs out.  The program will be able to accomodate cases where the Ant reaches the
edge of the board.  In which case it will turn around.


## Project 2 - Zoo Tycoon (C++11)
Implementation of a zoo tycoon game which must use classes and inheritance.  Zoo tycoon is a game that allows players to run a
zoo business. Different types of animals cost different prices, have different maintenance costs, and of course, return a 
different profit at the end of each day. For this game, the player will be the proud owner of a virtual zoo that has spaces 
to house tigers, penguins and turtles.


## Project 3 - Fantasy Combat Game (C++11)
Part 1 of a fantasy combat game implementation which must use classes and polymorphism.  

-Each combat between 2 characters ends when one of the characters die.
-Each round consists of two attacks, one for each character. For each attack, attacker and defender both generate dice rolls. 
The type and number of dice is listed above in the table.

The actual damage inflicted from the attacker onto the defender is calculated as follows:
Damage = attacker’s roll – defender’s roll – defender’s armor
Then the value of that damage is subtracted from the defender’s strength
points.


## Project 4 - Fantasy Combat Game Part 2 (C++11)
Part 2 of a fantasy combat game implementation which must use classes and polymorphism.  

At the start of the tournament, the program will prompt the user to enter the number of fighters for both teama. After that, 
for each fighter, the game will ask the user to choose the type of character, and enter a name for the fighter. For
example: assume the user chooses Harry Potter for player No.1’s team lineup, the user can name the Harry Potter character 
“Larry Snotter” or just “Harry Potter No.1”. The game should allow more than 1 of the same character for team lineups. For example, Team A has 3 members: 2 barbarians and 1 Harry Potter. The order of the lineup will be the same as the order user entered. After the user supplied the lineup of fighters in order, for Team No.1, and Team No.2, the tournament starts. In the tournament, the fighter at the head/front of each lineup will battle, in the same way they fight in project 3. The winner of each fight gets put at the back of their lineup, while loser goes to the top of the loser container (There should only be one containers to hold defeated fighters on both team). If a fighter won, it may have taken damage, so the game will restore some percentage of the damage they took when they get back in line. The lineup order cannot be changed, meaning that the game cannot modify the order of the lineup except when putting


## Project 5 Final - Heart and Brain Game (C++11)
Final project room navigation game implementation which must use classes, inheritance, and polymorphism.  

In this game, you will guide our two main characters: Brain and Heart.  Brain is the more logical fellow, but doesn't have much fun.
Heart follows his gut feeling and is the spontaneous of the two.  Your job is to guide Brain and Heart through the turmoils of a quarter of CS 162.
Each room in this game represents selected parts and topics of CS162.  The player will need to go through the rooms and collect serotonin to play the game.
Each room has a TA, aka Temper Analyzer.  The TA will analyze heart's current temper and give serotonin to brain. Brain uses serotonin to calm Heart down. If the user runs out of serotonin, Brain and Heart will explode.  The player then loses the game and does not continue.  TA's are hidden within topic rooms.  The player will need to navigate the room in order to find the TA.  Once the player has found the TA, they will receive a random amount of serotonin.  The TA's will also assign a pass/fail for the topic room.  Think of this as an item to collect.  The TA's will also assign a pass/fail for the topic room.  Think of this as an item to collect.  The player will need to collect MAX 5 out of 6 topic masteries.  When the player navigates past the major topics and reaches the end, they will win the game.

