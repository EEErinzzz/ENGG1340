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

int size = 5;
Record* userrank[size] = { {"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0} };
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
/*
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
}
*/
delete a;
}
bool SortByTime(Record a, Record b)
{
	//if( a.TimeUsed != b.TimeUsed)
		return a.TimeUsed < b.TimeUsed;
}



void Insertrecord(Record* a, &size)
{
	Record* temp = new Record[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = userrank[i];
	}
	delete[]usererank;
	size++;
	userrank = new Record[size];
	for (int j = 0; j < size - 1; j++)
	{
		userrank[j] = temp[j];
	}
	userrank[size - 1] = *a;
	delete[]temp;

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

	if( a->TimeUsed < userrank[size -1].TimeUsed ){
		userrank[size -1].TimeUsed=a->TimeUsed;
		userrank[size -1].PlayerName=a->PlayerName;
		sort(userrank, userrank + size, SortByTime);
		for (int i = 0; i < size;i++){
			fout <<i+1<<" "<<userrank[i].PlayerName <<" "<<userrank[i].TimeUsed<<endl;
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
