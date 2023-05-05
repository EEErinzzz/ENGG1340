# ENGG1340 Group 118 (Maze Explore Adventure)
List of contents
- [Team Members](#a1)
- [Game Description](#a2)
- [Features](#a3)
	- [Player Movement](#a31)
	- [Window Size Detection](#a32)
	- [Classic Mode](#a33)
	- [Dark Maze](#a34)
	- [Customizable Size](#a35)
	- [Random Maze Generation](#a36)
	- [Data Structures for Storing Game Status](#a37)
	- [Dynamic Memory Management](#a38)
	- [File Input/Output](#a39)
	- [Program Codes in Multiple Files](#a310)
- [How to run the game](#a4)

<a id="a1"></a>
## Team Members (In alphabetical order)
- Tsang Ka Yu    **UID**: 3036067602
- Wu Ziye    **UID**: 3036094576
- Yang Haozhe    **UID**: 3035973725
- Zhong Ching Yu    **UID**: 3036066452
- Zhou Ziyue    **UID**: 3035980314

<a id="a2"></a>
## Game Description

Feeling bored while playing a traditional maze game? Try the Maze Explore Adventure now by downloading folder `Finalized_our_maze`! The maze is now full of fog and darkness, so you won't be able to see everything. As the name suggests, you have to explore the maze yourself and find the exit with limited vision.
<a id="a3"></a>
## Features
<a id="a31"></a>
### Player Movement

-   We used the `getch()` function from `<ncurses.h>`, a useful library for creating an interactive user interface. The user can move the game character using WASD, like most games.
<a id="a32"></a>
### Window Size Detection

- We used `ioctl()` function from `<sys/ioctl.h>` to detect the window size
-   ***The game won't start if the system detects that the current window size is not big enough.***
- Minimum  window size: 45\*45
<a id="a33"></a>
### Classic Mode

-   A classic maze game where all objects are visible.
-   Please note that the record system will only be available in this mode.
-   Use WASD to move.
<a id="a34"></a>
### Dark Maze

-   A special version of the maze game where only objects near you are visible.
-   You can increase your sight by pressing 'z'
-   You can reduce your sight by pressing '-'
-   Use WASD to move.
<a id="a35"></a>
### Customizable Size

-   You can change the size of the maze.
-   Recommended range: 10-40.
-   If the size is larger than 40, please make sure you have sufficient space (window size) to display the maze.
<a id="a36"></a>
### Random Maze Generation

-   We used Prim's algorithm to generate the maze randomly.
<a id="a37"></a>
### Data Structures for Storing Game Status

-   We used a 2D vector to store the maze.
-   The game status, namely time used, player's name, size of the maze, and game mode are stored in a structure called "Record." Upon completing the game, this data will be displayed on the screen and exported to a txt file.
<a id="a38"></a>
### Dynamic Memory Management

-   Once the game is ended, the system will insert all the game status as a new record to the txt file. We used a dynamic array to store all the records (including the latest one) and sort them using the `SortByTime` function. After that, the records will be exported to a txt file, and the array will be deleted using `delete[]`.
<a id="a39"></a>
### File Input/Output

1.  All records are stored in the corresponding txt file.
2.  If the game is ended, the system will read records from the txt file.
3.  The system will insert a new record and sort all the records.
4.  Finally, the system will output all results to the txt file.
5.  Repeat steps 2-4 until the end of the program.

Example:

Assuming that you have just finished a classic maze with a size of 20\*20, a text file called "rank_Classic.txt" will be generated afterward.
```txt
Please enter your name: Erin
------------------------------
Player:                   Erin
Gamemode:              Classic
Size:                       20
Gametime:                   14
------------------------------
Top 5 records in Classic
1 9
2 14
3 60
4 999
5 999
------------------------------
Enter 0 if you wish to exit, else enter anything else to continue:
```
Our system will display the records in chronological order on the terminal.
```txt
1 9
2 14
3 60
4 999
5 999
```
You will see something like this if you open the txt file

<a id="a310"></a>
### Program Codes in Multiple Files

-   The `main.cpp` file controls the core functions, such as player movement, game mode selection, etc.
-   The `Maze_generation.cpp` and `Maze_generation.h` files contain functions that can generate the maze randomly, print the UI, update the player's location, etc.
<a id="a4"></a>
## How to run the game
1. Download the folder `Finalized_our_maze`
2. Unzip the folder which you downloaded just now
3. Type `make main` in your terminal under the parent directory `Finalized_our_maze`
4. The executable file `main` should appeared, type `./main` to run it
5. Enjoy the game
