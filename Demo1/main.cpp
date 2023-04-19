//main.cpp: How to compile: g++ main.cpp maze_gernerator.cpp -o main -l ncurses

#include<iostream>
#include<fstream>
#include<string>
#include<ncurses.h>
#include<unistd.h>
#include "maze_generator.h"
#include <ctime>
#include <chrono>

using namespace std;

struct Record
{
	string GameMode;
	string PlayerName;
	int TimeUsed;
	int size;
};

Record record;

void GameSelection();
void GameSetting();
void GamePlay();
void welcomepage()
{
	record.size = 20; //Default size
	record.GameMode = "Game not started";
	clear();	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	printw("Game title here");
	refresh();
	for(int i = 1; i <= 10; i++) //A stuid way to print out multiple empty lines
	{
		printw("\n");
		refresh();
	}
	printw("1. Start Game	2. Setting	Press any other key:Quit");
	refresh();
	char choice = getch();
	switch(choice)
	{
	case'1': GameSelection(); break;
	case'2':GameSetting(); break;
	}
}
	
void GameSelection()
{
	char ModeSelection;
	clear();
	printw("This is game selection page\n");
	refresh();
	printw("1. Classic   2.Prey  3.Return   Press any other key:Quit");
	refresh();
	ModeSelection=getch();
	switch(ModeSelection)
	{
	case '1': record.GameMode = "Classic";break;
	case '2': record.GameMode = "Prey"; break;
	case '3': welcomepage(); break;
	}
	GamePlay();
}

void GameSetting()
{

	clear();
	printw("This is the game setting page");
	refresh();
	sleep(3);
	welcomepage();
}

void GamePlay()
{
	clear();
	char player = 'X';
	int px= 1;
	int py = 2;
	//Player's X and Y coordinate
	int endx = 18;
	int endy = 17;
	//X, Y coordinate of exit
	maze_generation our_maze(record.size);
	// create the object
	our_maze.maze_generator();
	// generate the maze
	our_maze.player_insertion(player, py, px);
	// Insert player to the maze
	
	char move;
	auto start_time = std::chrono::system_clock::now();
	while (px != endx | py != endy)
	{
		clear();
		our_maze.maze_printer();
		// print the maze
		cout << py << " " << px << endl;
		move = getch();
		switch (move)
		{
		case 'w': if (our_maze.check_wall(py -1, px)) { our_maze.update_player_location(py, px, py -1, px); py -= 1; }  break;
		case 'a': if (our_maze.check_wall(py, px-1)) { our_maze.update_player_location(py, px, py, px - 1); px -= 1; } break;
		case 's': if (our_maze.check_wall(py + 1, px)) { our_maze.update_player_location(py, px, py + 1, px); py += 1; } break;
		case 'd': if (our_maze.check_wall(py, px + 1)) { our_maze.update_player_location(py, px, py, px + 1); px += 1; }  break;
		}
	}
	auto end_time = std::chrono::system_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time-start_time);
	int seconds = static_cast<int>(elapsed_time.count());
	record.TimeUsed = seconds;
}

int main()
{
	system("clear");
	welcomepage();
	endwin();
	cout<<"Testing the record system"<<endl;
	cout<<"Gamemode:"<<record.GameMode<<endl;
	cout << "Size:" << record.size << endl;
	cout << "Gametime: " << record.TimeUsed << endl;
}
