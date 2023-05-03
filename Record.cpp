#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include "rank.h"
#include "recordsys.h"

using namespace std;
bool SortByTime(Record a, Record b);
void Insertrecord(Record *a);
void Display();
void k();
struct Record userrank[5] = {{"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0}};
/*
int main()
{
  
}
*/
void  k(Record &b) 
// pass the structure by reference
{
	auto * a = new Record;
	a = &b;
if(a->GameMode=="Classic")
{ switch(a->size)
{
	case 20:
		//SortByTime(Record a, Record b)
		Insertrecord(a);
		Display();
		break;
		
	
	case 30:
		//SortByTime(Record a, Record b)
		Insertrecord(a);
		Display();
		break;
			
	case 40:
		//SortByTime(Record a, Record b)
		Insertrecord(a);
		Display();
		break;
		}
}

if(a->GameMode=="Prey")
{switch(a->size)
{
	case 20:
		//SortByTime(Record a, Record b)
		Insertrecord(a);
		Display();
		break;
		
	case 30:
		//SortByTime(Record a, Record b)
		Insertrecord(a);
		Display();
		break;
		
	case 40:
		//SortByTime(Record a, Record b)
		Insertrecord(a);
		Display();
		break;
	}

delete a;
}
}
bool SortByTime(Record a, Record b)
{
	//if( a.TimeUsed != b.TimeUsed)
		return a.TimeUsed < b.TimeUsed;
}

void Insertrecord(Record *a)
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

	if( a->TimeUsed < userrank[4].TimeUsed ){
		userrank[4].TimeUsed=a->TimeUsed;
		userrank[4].PlayerName=a->PlayerName;
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
