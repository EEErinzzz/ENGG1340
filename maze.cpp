#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include <thread> 
#include <string> 
using namespace std;

const int BH = 16;
const int BW = 16;

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

void display(char board[][16]) 
{
    for (int i = 0; i < BH; i++) 
    {
        for (int j = 0; j < BW; j++) 
        {
            mvaddch(i,j,board[i][j]);
        }
    }
}

bool initiategame() 
{
    printw("Welcome to the maze! \n");
    sleep(1);
    refresh();
    printw("Try to leave the maze ASAP!\n");
    sleep(1);
    refresh();
    printw("press any button to start \n");
    sleep(1);
    refresh();
    printw("Press Esc to quit \n");
    int ch = getch();
    if (ch == 27) 
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main() 
{   
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    char board[BH][BW] = {
                            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                            {' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#'},
                            {'#','#','#',' ','#','#','#','#',' ','#','#',' ','#',' ',' ','#'},
                            {'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#',' ','#'},
                            {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                            {'#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#'},
                            {'#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ','#'},
                            {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','#',' ','#'},
                            {'#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#',' ','#'},
                            {'#',' ','#','#','#',' ','#',' ','#',' ',' ',' ','#','#',' ','#'},
                            {'#',' ',' ',' ',' ',' ','#',' ','#','#','#',' ','#','#',' ','#'},
                            {'#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#',' ','#'},
                            {'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
                            {'#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ',' ','#'},
                            {'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '},
                            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
                         };
    if (not initiategame()) {
        endwin();
        exit(0);
    }

    clear();
    int player_x = 0;
    int player_y = 1;
    board[player_y][player_x] = 'X';
    printw("ready?\n");
    refresh();
    sleep(1);
    clear();
    printw("set\n");
    refresh();
    sleep(1);
    clear();
    printw("go!\n");
    refresh();
    sleep(1);
    clear();
    int timer_height = 3;
    int timer_width = 30;
    int timer_x = 18 ;
    int timer_y = 8 ;
    WINDOW* timer_window = newwin(timer_height,timer_width,timer_y,timer_x);
    box(timer_window, 0 ,0);
    wrefresh(timer_window);

    std::thread timer(timer_thread,timer_window);
    
    while (board[14][15] != 'X') 
    {
        display(board);
    
        int ch = getch();
        mvaddch(17,17,ch);
        mvaddch(18,17,player_x);
        mvaddch(18,17,player_y);
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
    }
    sleep(3);
    timer.join();
    delwin(timer_window);
    endwin();
    return 0;
}