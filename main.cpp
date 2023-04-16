//main.cpp: How to compile: g++ main.cpp -o main -l ncurses


#include<iostream>
#include<fstream>
#include<string>
#include<ncurses.h>
#include<unistd.h>
using namespace std;

struct Record
{
	string GameMode;
	string PlayerName;
	int TimeUsed;
};

Record record;

void GameSelection();
void GameSetting();
void welcomepage()
{
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
	case '1': record.GameMode = "Classic"; break;
	case '2': record.GameMode = "Prey"; break;
	case '3': welcomepage(); break;
	}
}

void GameSetting()
{

	clear();
	printw("This is the game setting page");
	refresh();
	sleep(3);
	welcomepage();
}


int main()
{
	welcomepage();
	endwin();
	cout<<"Testing the record system"<<endl;
	cout<<"Gamemode:"<<record.GameMode<<endl;
}
