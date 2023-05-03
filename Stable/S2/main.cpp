//main.cpp: How to compile: g++ main.cpp maze_gernerator.cpp -o main -l ncurses

#include<iostream>
#include<fstream>
#include<string>
#include<ncurses.h>
#include<unistd.h>
#include "maze_generator.h"
#include <ctime>
#include <chrono>
#include "rank.h"
#include "recordsys.h"

using namespace std;

/*
struct Record
{
	string GameMode;
	string PlayerName;
	int TimeUsed;
	int size;
};
*/
Record record;

void Game_Mode_Selection();
void GameSetting(int mode);
void GamePlay_Classic();
void GamePlay_Foggy();
void welcomepage()
{
	record.size = 20; //Default size
	record.GameMode = "Game not started";
	clear();
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	printw("Game title here");
	refresh();
	for (int i = 1; i <= 10; i++) //A stuid way to print out multiple empty lines
	{
		printw("\n");
		refresh();
	}
	printw("1. Start Game	Press any other key:Quit");
	refresh();
	char choice = getch();
	switch (choice)
	{
	case'1': Game_Mode_Selection(); break;
	}
}


void Game_Diffculty_Selection(int mode)
{
	char SizeSelection;
	clear();
	printw("Select the difficulty levels\n");
	refresh();
	printw("1. Easy(20*20)   2.Hard(30*30)  3.Insane(40*40) 4.Custom  5.Return    Press any other key:Quit");
	refresh();
	SizeSelection = getch();
	switch (SizeSelection)
	{
	case '1': record.size = 20; if (mode == 1)GamePlay_Classic(); else GamePlay_Foggy(); break;
	case '2': record.size = 30; if (mode == 1)GamePlay_Classic(); else GamePlay_Foggy(); break;
	case '3': record.size = 40; if (mode == 1)GamePlay_Classic(); else GamePlay_Foggy(); break;
	case '5': Game_Mode_Selection(); break;
	case '4': GameSetting(mode); break;
	}
	
}
void Game_Mode_Selection()
{
	char ModeSelection;
	clear();
	printw("This is game selection page\n");
	refresh();
	printw("1. Classic   2. Foggy  3.Return   Press any other key:Quit");
	refresh();
	ModeSelection = getch();
	switch (ModeSelection)
	{
	case '1': record.GameMode = "Classic"; Game_Diffculty_Selection(1); break;
	case '2': record.GameMode = "Foggy"; Game_Diffculty_Selection(2); break;
	case '3': welcomepage(); break;
	}
}

void GameSetting(int mode)
{
	endwin();
	bool exit = 1;
	while (exit)
	{
		system("clear");
		cout << "This is the game setting page\nRecord system will be disable if you changed the size\n";
		printf("\n\n1. Current Size: %d", record.size);
		printf("\n2. Return");
		cout << "\n\n Please enter your choice: ";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "\r Current Size: " << record.size << " --> "; cin >> record.size; break;
		case 2: exit = 0; break;
		default: cout << "\r Invaild Input! Please enter again";
		}
	}
		initscr();
		cbreak();
		noecho();
		keypad(stdscr, true);
		curs_set(0);
		if (mode == 1)
			GamePlay_Classic();
		else
			if (mode == 2)
				GamePlay_Foggy();
}

void GamePlay_Classic()
{
	clear();
	char player = 'X';
	int px = 1;
	int py = 2;
	//Player's X and Y coordinate
	int endx = record.size - 2;
	//X coordinate of exit (only check if the character has reached the last column)
	maze_generation our_maze(record.size);
	// create the object
	our_maze.maze_generator("open");
	// generate the maze
	our_maze.player_insertion(player, py, px);
	// Insert player to the maze

	char move;
	auto start_time = std::chrono::system_clock::now();
	our_maze.maze_printer();
	while (px != endx)
	{
		move = getch();
		switch (move)
		{
		case 'w': if (our_maze.check_wall(py - 1, px) && py > 1) { our_maze.update_player_location(py, px, py - 1, px); our_maze.just_update_player(py, px, py - 1, px); py -= 1; }  break;
		case 'a': if (our_maze.check_wall(py, px - 1) && px > 1) { our_maze.update_player_location(py, px, py, px - 1); our_maze.just_update_player(py, px, py, px - 1); px -= 1; } break;
		case 's': if (our_maze.check_wall(py + 1, px) && py < (record.size - 2)) { our_maze.update_player_location(py, px, py + 1, px); our_maze.just_update_player(py, px, py + 1, px); py += 1; } break;
		case 'd': if (our_maze.check_wall(py, px + 1) && px < (record.size - 2)) { our_maze.update_player_location(py, px, py, px + 1); our_maze.just_update_player(py, px, py, px + 1); px += 1; }  break;
		}
	}
	auto end_time = std::chrono::system_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
	int seconds = static_cast<int>(elapsed_time.count());
	record.TimeUsed = seconds;
}

void GamePlay_Foggy()
//function controlling the game in foggy mode
{
	clear();
	char player = 'X';
	int px = 1;
	int py = 2;
	//Player's X and Y coordinate
	int endx = record.size - 2;
	//X coordinate of exit (only check if the character has reached the last column)
	maze_generation our_maze(record.size);
	// create the object
	our_maze.maze_generator("open");
	// generate the maze
	our_maze.player_insertion(player, py, px);
	// Insert player to the maze

	char move;
	auto start_time = std::chrono::system_clock::now();

	int sight = 5;
	while (px != endx)
	{
		clear();
		

		our_maze.maze_printer_Foggy(sight);
		// print the maze
		move = getch();
		switch (move)
		{
		case 'w': if (our_maze.check_wall(py - 1, px) && py > 1) { our_maze.update_player_location(py, px, py - 1, px); py -= 1; }  break;
		case 'a': if (our_maze.check_wall(py, px - 1) && px > 1) { our_maze.update_player_location(py, px, py, px - 1); px -= 1; } break;
		case 's': if (our_maze.check_wall(py + 1, px) && py < (record.size - 2)) { our_maze.update_player_location(py, px, py + 1, px); py += 1; } break;
		case 'd': if (our_maze.check_wall(py, px + 1) && px < (record.size - 2)) { our_maze.update_player_location(py, px, py, px + 1); px += 1; }  break;
		}
		if (move == '+' && sight < record.size / 3) sight += 2;
		// press '+' to increase the sight
		else if (move == '-' && sight > 0) sight -= 2;
		// pree '-' to decrease the sight
	}
	auto end_time = std::chrono::system_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
	int seconds = static_cast<int>(elapsed_time.count());
	record.TimeUsed = seconds;
}



int main()
{
	system("clear");
	welcomepage();
	endwin();
	cout << "Testing the record system" << endl;
	cout << "Gamemode:" << record.GameMode << endl;
	cout << "Size:" << record.size << endl;
	cout << "Gametime: " << record.TimeUsed << endl;
	k(record);
}
