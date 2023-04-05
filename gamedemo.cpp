#include <ncurses.h>
// "ncurses.h" is one of the cpp libraries I think we can use in our game design because it creates a interactive interface and can detect keyboard hit.
// However, it may not be so easy to learn (TAT).
// compile process is a little different as we need to specify -lncurses in compilation.
/* here is the script for compilation
g++ -pedantic-errors -std=c++11 gamedemo.cpp -o game -lncurses
./game
*/
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
            if (player_x < BW - 1 ) {
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