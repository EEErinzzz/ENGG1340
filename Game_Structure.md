# Game_Structure
| created by Yang Haozhe Thomas.

| This is a feasible structure proposal of the group project of ENGG1340, aiming to provide you with detailed and clear structure how to create the game.

---

## Maze game
**Table of Content**

*since the markdown file is too long to scroll through, if necessary, please refer to the Table of Content and locate your part quickly via hyperlink*
- [Overview](#item-one)
- [Random Maze Generation](#item-two)
- [Player Movement](#item-three)
- [Timer](#item-four)
- [Record System](#item-five)
- [Hunters](#item-six)
- [main.cpp](#item-n)
- [Dependency List](#appendix-one)
- [Quick Guide to "ncurses.h"](#appendix-two)

<a id="item-one"></a>
### Overview
suggested library to import: "ncurses.h" in cpp linux

a powerful library to create an interactive user interface and allows in-time keyboard response

for quick guide press [here](#appendix-two)

---

<a id="item-two"></a>
### Random Maze Generation 
Description:
1. code:
```cpp
#ifndef MAZE_GENERATOR_H_
#define MAZE_GENERATOR_H_

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

namespace maze
{
  class maze_generator
  {
    public:
      explicit maze_generator(uint32_t height, uint32_t width);

      static constexpr uint32_t wall     = 0u;
      static constexpr uint32_t hole     = 1u;
      static constexpr uint32_t solution = 2u;

      void set_cell(uint32_t y, uint32_t x, uint32_t value);
      uint32_t get_cell(uint32_t y, uint32_t x);

      std::vector<std::vector<uint32_t>> get_maze(void);
      void set_maze(std::vector<std::vector<uint32_t>> vect);

      void reshape(uint32_t new_height, uint32_t new_width);

      uint32_t get_height(void);
      uint32_t get_width(void);

    protected:
      std::random_device random_device;

      static constexpr uint32_t vertical    = 0u;
      static constexpr uint32_t horizontal  = 1u;

      static constexpr uint8_t north  = 0u;
      static constexpr uint8_t south  = 1u;
      static constexpr uint8_t west   = 2u;
      static constexpr uint8_t east   = 3u;

      std::vector<std::vector<uint32_t>> area;

      
  };
}

#endif /* MAZE_GENERATOR_H_ */
```
2. classes, functions and files created

3. others
    *(specify any requirement in input output format or anything else that is worth pay attention to)*

---

<a id="item-three"></a>
### Player Movement
Description:
1. suggested coding scheme: ncurses + key board detection 

*here is a sample use of user control*
``` cpp
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int getmillis() {
    // This is a self-defined function for getting the system time in millisecond.
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast < std::chrono::milliseconds>(now);
    auto value = now_ms.time_since_epoch();
    return static_cast<int>(value.count());
}


const int BW = 40;
const int BH = 20;
// BW BH stand for Borad Width and Board Height, respectively.


int main() {
    // set up of the gameplace
    initscr();
    cbreak();
    noecho();
    // noecho denotes there will be no standard output in the terminal (console) 
    keypad(stdscr, TRUE);
    curs_set(0);
    
    // The follwing lines of code is the board initiation (line 29-34)
    char board[BH][BW];
    for (int i = 0; i < BH;i++) {
        for (int j = 0; j < BW; j++) {
        board[i][j] = ' ';
        }
    }
  
    int player_x = BW / 2;
    int player_y = BH - 1;
    board[player_y][player_x] = 'X';
    
    srand(time(NULL)); // random initiation
    int ball_x = rand() % BW;
    int ball_y = 0;
    board[ball_y][ball_x] = '*';
    
    const int Game_Speed = 100; 
    const int Scan_Interval = 1000;
  
  
    while (true) {
        // The follwing lines prints out the board by mvaddch(int y_coordinate, int x_coordinate, const char obj.)
        for (int i = 0; i < BH; i++) {
            for (int j = 0; j < BW; j++) {
            mvaddch(i,j,board[i][j]);
            }
        }

        board[ball_y][ball_x] = ' ';    
        ball_y++;
        if (ball_y >= BH) {
        ball_x = rand() % BW;
        ball_y = 0;
        }
        board[ball_y][ball_x] = '*';

        int ch = getch(); // getting keyboard input
        switch (ch) {
        case KEY_LEFT:
            if (player_x > 0) {
                board[player_y][player_x] = ' ';
                player_x--;
                board[player_y][player_x] = 'X';
            }
            break;
        case KEY_RIGHT:
            if (player_x < BW - 1) {
                board[player_y][player_x] = ' ';
                player_x++;
                board[player_y][player_x] = 'X';
            }
            break;
        }
    // note: we can find the corresponding code representation for keyboard input
    // E.g., KEY_LEFT for "left key"

    move(0,0);
    napms(Game_Speed);
    // napms sets the "refreshing time of the game" to 100 millisecond.
    }

endwin();
// window close.
return 0;
}
```
The basic Idea of using this library is to create a new window interface (instead of using the shell console to input and output)

We can use getch() to timely get which key is being pressed.

In our game, panel control could be **w a s d** or **KEY_LEFT KEY_RIGHT KEY_UP KEY_DOWN** so the switch flow could look like:

```cpp
 switch (ch) 
        {
            case KEY_LEFT: case 'a':
                if (board[player_y][player_x-1] != '#') 
                {
                    board[player_y][player_x-1] = 'X';
                    board[player_y][player_x] = ' ';
                    player_x -= 1;
                }
                break;

            case KEY_UP: case 'w':
                if (board[player_y-1][player_x] != '#') 
                {
                    board[player_y-1][player_x] = 'X';
                    board[player_y][player_x] = ' ';
                    player_y -= 1;
                }
                break;
            
            case KEY_DOWN: case 's':
                if (board[player_y+1][player_x] != '#') 
                {
                    board[player_y+1][player_x] = 'X';
                    board[player_y][player_x] = ' ';
                    player_y += 1;
                }
                break;

            case KEY_RIGHT: case 'd':
                if (board[player_y][player_x+1] != '#') 
                {
                    board[player_y][player_x+1] = 'X';
                    board[player_y][player_x] = ' ';
                    player_x += 1;
                }
                break;                            
        
    }
```
2. classes, functions and files created

| Note that the player movement is really important part of our game! 
    
---

<a id="item-four"></a>
### Timer
Description:
1. feasible plan (some codes included)
| How to implement the Timer has not be decided, I came up with two plans:

1) display the timer on the game window (visible to player) and time flows.
    The first plan is a little tricky to implement because if we want the timer be displayed we will have to make the main.cpp and timer.cpp parallel other wise the user will find the game process be impeded. 
    (for example, the keyboard hit detection will not be continues 因为计时器程序需要sleep(1); 休眠，然后second++; )
    
    I came up with two plans to solve the problem:

   a. by using new-thread
   ```cpp
   void timer_thread (WINDOW* timer_window) 
   {
       auto start_time = std::chrono::system_clock::now();
       while (true) {
           auto current_time = std::chrono::system_clock::now();
           auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time-start_time);

           werase(timer_window);
           wprintw(timer_window,"%ld seconds has passed", elapsed_time.count());
           wrefresh(timer_window);

           std::this_thread::sleep_for(std::chrono::seconds(1));

       }
   }
   ```
   In this way, we can create a sub-window in our ncurses window that could run the timer and display the timer correctly
   *here is how we can initialize the thread window in the main program*

   ```cpp
   // initiation of the timer_thread
       int timer_height = 3;
       int timer_width = 30;
       int timer_x = 18 ;
       int timer_y = 8 ;
       WINDOW* timer_window = newwin(timer_height,timer_width,timer_y,timer_x);
       box(timer_window, 0 ,0);
       wrefresh(timer_window);

       std::thread timer(timer_thread,timer_window);
   ```

   b. by directly taking system time
       Getting systemtime directly and do calculation to obtain game time

2) Do not display timer to the user
    measuring system time at the begining and the end of the game, do subtraction and obtain the elapsed_time

2. classes, functions and files created
    return value -> elapsed time
    use in the [Record System （游戏记录系统）](#item-five)

---

<a id="item-five"></a>
### Record System
Description:
**Features: record comparision, insertion and display**

1. code (file IO)

   require data from timer and user input -> name of the user

   (just keep the top 5 of each mode we have) 

*code here*

```cpp
```

2. classes, functions and files created
    temporary files to store the information
    functions:
        
        ```cpp
        Insertrecord()
        ```
        ```cpp
        Display()
        ```
    file:
        
        Record.h
        
        Record.cpp

3. others

---

<a id="item-six"></a>
### Hunters
Description:
**randomly generate hunters to hunt player in the maze**

1. coding scheme
    randomly generate the 2-3 monsters in the map
    
    a. DFS search for all the possible path in the maze with respect to the start point of the hunter

    b. record the path

    c. the hunter will randomly select path and hunt with in a distance（设置半径 int R，所有路径仅仅访问 <= R 个node）

    d. visiting pace: one node/second

    e. 实体碰撞detection -> deduction in HP for player; reset the position of the monster
    
    *code here*
    
    
    ```cpp
    ```
    
2. classes, functions and files created


3. others


---
<a id="item-n"></a>
### main.cpp
**Main function of the program

1. UI design
2. open ncurses window
3. mode selection
  | different mode
  | record display (include record.h)
4. quit function



<a id="appendix-one"></a>
### Dependency List
---

<a id="appendix-two"></a>
### Quick Guide to "ncurses.h"

1. description
    > ncurses (new curses) is a programming library providing an application programming interface (API) that allows the programmer to write text-based user interfaces (TUI) in a terminal-independent manner. It is a toolkit for developing "GUI-like" application software that runs under a terminal emulator. It also optimizes screen changes, in order to reduce the latency experienced when using remote shells. (quoted from Wiki)
2. basic notes and syntax
```cpp
initscr();
```
| initiate screen/window
```cpp
cbreak();
// input is made available to the program as soon as it is typed. No enter is required after typing by user and the system will automatically receive the content
noecho();
// noecho denotes there will be no standard output in the terminal (console)
```
| note that cbreak() and noecho() are often used together 
```cpp
keypad(stdscr, TRUE);
```
| enable keyboard interaction, special input (E.g., Esc or Backspace) could be received
```cpp
curs_set(0);
```
| used to control the visibility of the cursor on the screen. This fuction takes in one integer value. 0 for hiding, 1 for visible, 2 for highly visible

```cpp
while (true) {
    // The follwing lines prints out the board by mvaddch(int y_coordinate, int x_coordinate, const char obj.)
    for (int i = 0; i < BH; i++) {
        for (int j = 0; j < BW; j++) {
        mvaddch(i,j,board[i][j]);
        }
    }
```
| mvaddch(int y_coordinate, int x_coordinate, constant char object) is how to display item in ncurses window

```cpp
printw("Hello world!");
refresh();
```
| printw prints contents to buffer zone (temporarily invisible in the window) and refresh release the buffer and made contents visible

```cpp
clear();
```
| clear(); clears contents on the screen

```cpp
endwin();
```
| endwin() terminates the current ncurses window

*to be continued*

3. other notes

a. compilation note:
```shell
g++ -pedantic-errors -std=c++11 gamedemo.cpp -o game -lncurses
```
Please compile in this way otherwise an error will be raised. Pay attention to *-lncurses* at the end of the compilation command.

b. Key press detecion:
| Key Code	| Description | 
| --------  | ----------- |
| KEY_CODE_YES | Used to indicate that a wchar_t variable contains a key code |
| KEY_BREAK	| Break key |
| KEY_DOWN  | Down arrow key | 
| KEY_UP	| Up arrow key | 
| KEY_LEFT	| Left arrow key |
| KEY_RIGHT	| Right arrow key | 
| KEY_HOME	| Home key |
| KEY_BACKSPACE	| Backspace |
| KEY_F0	 | Function keys; space for 64 keys is reserved |
| KEY_F(n)	 | For 0 <=n<=63
| KEY_DL	 | Delete line
| KEY_IL	 | Insert line
| KEY_DC	 | Delete character
| KEY_IC	 | Insert char or enter insert mode
| KEY_EIC	 | Exit insert char mode
| KEY_CLEAR	 | Clear screen
| KEY_EOS	 | Clear to end of screen
| KEY_EOL	 | Clear to end of line
| KEY_SF	 | Scroll 1 line forward
| KEY_SR	 | Scroll 1 line backward (reverse)
| KEY_NPAGE	 | Next page
| KEY_PPAGE	 | Previous page
| KEY_STAB	 | Set tab
| KEY_CTAB	 | Clear tab
| KEY_CATAB	 | Clear all tabs
| KEY_ENTER	 | Enter or send
| KEY_SRESET	 | Soft (partial) reset
| KEY_RESET	 | Reset or hard reset
| KEY_PRINT	 | Print or copy
| KEY_LL	 | Home down or bottom
| KEY_A1	 | Upper left of keypad
| KEY_A3	 | Upper right of keypad
| KEY_B2	 | Center of keypad
| KEY_C1	 | Lower left of keypad
| KEY_C3	 | Lower right of keypad

To get more detailed information, please refer to the [ncurses.h docmentation](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html).
