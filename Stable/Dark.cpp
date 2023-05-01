#include<iostream>
#include<fstream>
#include<string>
#include<ncurses.h>
#include<unistd.h>
#include "maze_generator.h"
#include "Dark.h"
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

vector<vector<int>> maze = pass_maze();
void dark_printer(int y, int x);
void game_start();

void dark_printer(int y, int x)
{
	if(maze[y][x] == 'X') mvaddch(y, x, 'X');
	if (maze[y - 1][x - 1] == 1)mvaddch(y - 1, x - 1, ' ');
	else mvaddch(y - 1, x - 1, '#');
	if (maze[y - 1][x] == 1)mvaddch(y - 1, x, ' ');
	else mvaddch(y - 1, x, '#'); 
	if (maze[y - 1][x+1] == 1)mvaddch(y - 1, x+1, ' ');
	else mvaddch(y - 1, x+1, '#');
	if (maze[y][x-1] == 1)mvaddch(y, x-1, ' ');
	else mvaddch(y, x-1, '#');
	if (maze[y][x + 1] == 1)mvaddch(y, x + 1, ' ');
	else mvaddch(y, x + 1, '#');
	if (maze[y+1][x - 1] == 1)mvaddch(y+1, x - 1, ' ');
	else mvaddch(y+1, x - 1, '#');
	if (maze[y+1][x] == 1)mvaddch(y+1, x , ' ');
	else mvaddch(y+1, x , '#');
	if (maze[y + 1][x+1] == 1)mvaddch(y+1, x+1, ' ');
	else mvaddch(y + 1, x+1, '#');

}