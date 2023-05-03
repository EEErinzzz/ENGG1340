#ifndef RECORDSYS_H
#define RECORDSYS_H

#include<iostream>
#include<string>
using namespace std;

/*
struct Record
{
	std::string GameMode;
	std::string PlayerName;
	int TimeUsed;
	int size;
};
*/

bool SortByTime(Record a, Record b);
void Insertrecord(Record*a);
void Display();
void k();

#endif
