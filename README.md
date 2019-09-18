# CS-Project-Consequences
Final Project for PIC 10C taken at UCLA. By Lucy(Ruoshi) Huang and Naomi(Youjun) Chen

Welcome to our scenario game ***Consequence***! We hope you have fun playing!


## Description
This is a scenario game that determines its ending based on a series of user response to prompt scenarios. In our case, the scenarios will be coherent to a dating-themed storyline.

The player will first be assigned a character depending on their gender selection and choices of words. They will then proceed to play the scenario game. Some responses will score more points than others. However, the player’s assigned character will restrict the responses they can choose from in each scene, meaning their character can give them an advantage or a disadvantage. The player must endure the ‘consequences’ of choosing that character, hence the name of the game. 
The player can only win if they exceed a certain amount of points in each round (calculations will be done on the backend). User’s interaction with application is mainly via pushbuttons. 

## Initial Setup
To make sure everything runs smoothly on your computer, please take the following steps:
1. After opening our project in Qt Creator, go to the “Projects” tab on the left toolbar of Qt Creator.
2. Go into Projects > Run > Working Directory
3. Change the working directory to the folder of our project
4. Delete all previous builds of our project from your computer, if any exists. This is to ensure that Qt will run the latest and correct version of our project.

## Other Notes
- Qt Version used in PIC Lab: Qt 5.9.1 MinGW 32bit
- Qt Version used on Mac:  Qt 5.12.1 clang 64bit
- Program has been tested on both versions.
- Program is optimized for display on a Mac, but it will also run smoothly on Windows.
- We used qDebug in our program when testing our backend, and we’ve left it as it is. You may look at the Application Output if you wish to see how our backend works in depth.
- See the presentation slides for more information about class hierarchies and how the program works in general.

---------------------------------------------------------------------------------------------------------------------
The following contains details about all possibilities of our game to help with grading. However, we recommend you play the game yourself a few times first to not ruin the experience!
__(SPOILER ALERT!!!)__

### Characters
There are a total of six possible characters:
1. Male
   - Alexander
   - Benjamin
   - Carter
2. Female
   - Emily
   - Fiona
   - Gemma
- The ‘a’ characters are the ones that a player is most likely to be assigned, and generally have a higher success rate than the other characters.
- The ‘c’ characters are the ones that a player is least likely to be assigned, and they generally have a lower success rate in reaching a happy ending.

### Walkthroughs 
***Ending 1: Happy Ending (Date is successful)***

The following is one of the many ways that you can get to a happy ending. This path will also ensure that the player reaches both minigames.

1. Gender Selection: Female
2. Word Selections: sun > passion > lion > coffee > triangle (You should be assigned the character “Emily” after this step)
3. Scenario Game Round 1
   - Arrive just on time
   - Give them a hug
   - Cocktail
   - Tell them directly about it
   - Leave the food and evacuate
4. Minigame: Fire Game
5. Scenario Game Round 2
   - Romance Movie
   - Ask for popcorn to share
   - Kindly hint to the parents
   - Look back and smile at him
   - Tell him your real opinion
   - Say yes of course
6. Minigame: Ice Cream Game
Happy ending reached

***Ending 2: Sad Ending (Date is unsuccessful)***

The following is one of the many ways that you can get to a sad ending. Note that you can get to a sad ending at the end of round 1 or round 2, but for efficiency, we will delineate the path that ends after round 1 here. This means the player will not get to play either minigames in this path.

1. Gender Selection: Male
2. Word Selections: stars > adventure > dolphin > boba > circle (This will yield the character “Carter”)
3. Scenario Game Round 1:
   - Be fashionably late
   - Shaking their hands
   - Champagne
   - Give them a small hint
   - Grab all the food and leave
Sad ending reached

***Ending 3: Fire Ending (Character dies in a fire)***

The following is a surprise ending. For any character, if at the end of round 1, the player chooses the choice “Ignore [the fire alarm] and continue to eat”, they will reach the ending where they die from the fire.

***Other Possibilities:***

The walkthroughs above have shown the methods of getting the characters ‘a’ and ‘c’. If you would like to be assigned character ‘b’, you can choose the following for word selection:

moon > virtue > swan > tea > square.


