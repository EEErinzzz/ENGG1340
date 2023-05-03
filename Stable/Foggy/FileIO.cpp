#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include "rank.h"
#include "recordsys.h"

using namespace std;
bool SortByTime(Record a, Record b);
void Insertrecord(string name, int time, string mode, int siz);
void Display();
void k();
struct Record userrank[5] = {{"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0}};
/*
int main()
{
  
}
*/
void  k(Record &a) 
// pass the structure by reference
{
if(a.GameMode=="Classic")
{ switch(a.size)
{
	case 20:
		//SortByTime(Record a, Record b)
		Insertrecord(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		Display();
		break;
		
	
	case 30:
		//SortByTime(Record a, Record b)
		Insertrecord(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		Display();
		break;
			
	case 40:
		//SortByTime(Record a, Record b)
		Insertrecord(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		Display();
		break;
		}
}

if(a.GameMode=="Prey")
{switch(a.size)
{
	case 20:
		//SortByTime(Record a, Record b)
		Insertrecord(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		Display();
		break;
		
	case 30:
		//SortByTime(Record a, Record b)
		Insertrecord(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		Display();
		break;
		
	case 40:
		//SortByTime(Record a, Record b)
		Insertrecord(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		Display();
		break;
	}
}
}
bool SortByTime(Record a, Record b)
{
	//if( a.TimeUsed != b.TimeUsed)
		return a.TimeUsed < b.TimeUsed;
}

void Insertrecord(string name, int time, string mode, int siz)
{
	ifstream fin;
	fin.open("rank_Classic.txt");
	string line;
	int count = 0;
	int temp = 0;
	while (getline(fin, line)){
		istringstream line_in(line);
		line_in >> userrank[count].PlayerName;
		line_in >> userrank[count].TimeUsed;
		count += 1;
	}
	fin.close();
	ofstream fout;
	fout.open("rank_Classic.txt");
	if ( fout.fail() ){
		fout.open("rank_Classic.txt", ios::out);
	}

	if( time < userrank[4].TimeUsed ){
		userrank[4].TimeUsed=time;
		userrank[4].PlayerName=name;
		sort(userrank, userrank + 5, SortByTime);
		for (int i = 0; i < 5;i++){
			fout <<i+1<<" "<<userrank[i].PlayerName <<" "<<userrank[i].TimeUsed<<endl;
	}
}
	fout.close();
}

void Display()
{
	ifstream fin;
	fin.open("rank_Classic.txt");
	string line;
	while (getline(fin, line)){
		cout<<line<<endl;
	}
	fin.close();
}
