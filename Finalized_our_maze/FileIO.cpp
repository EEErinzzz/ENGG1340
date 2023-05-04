#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include "rank.h"
#include "recordsys.h"


using namespace std;
bool SortByTime(Record a, Record b);
void Insertrecord_30(string name, int time, string mode, int siz);
void Insertrecord_40(string name, int time, string mode, int siz);
void Insertrecord_20(string name, int time, string mode, int siz);
void Display(int size);
void k(Record& a);



//Record userrank[5] = { {"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0}, {"","",999,0} };
/*
int main()
{
  
}
*/
void  k(Record& a)
// pass the structure by reference
{
if(a.GameMode=="Classic")
{ switch(a.size)
{
	case 20:
		Insertrecord_20(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		break;


	case 30:
		Insertrecord_30(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		break;

	case 40:
		Insertrecord_40(a.PlayerName, a.TimeUsed, a.GameMode, a.size);
		break;
		}
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

bool SortByTime(Record a, Record b)
{
	//if( a.TimeUsed != b.TimeUsed)
		return a.TimeUsed < b.TimeUsed;
}

//Record* userrank[5];
//userrank[0] = { "","",999,0 };
//userrank[1] = { "","",999,0 };
//userrank[2] = { "","",999,0 };
//userrank[3] = { "","",999,0 };
//userrank[4] = { "","",999,0 };

void Insertrecord_20(string name, int time, string mode, int siz)
{
	int size;
	ifstream fin;
	fin.open("len.txt");
	fin >> size;
	fin.close();
	Record* userrank;
	userrank = new Record[size];
	fin.open("rank_Classic.txt");
	string line;
	int count = 0;
	while (getline(fin, line)) {
		istringstream line_in(line);
		line_in >> userrank[count].PlayerName;
		line_in >> userrank[count].TimeUsed;
		count += 1;
	}
	fin.close();
	Record* temp = new Record[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = userrank[i];
	}
	delete[]userrank;
	size++;
	userrank = new Record[size];
	for (int j = 0; j < size - 1; j++)
	{
		userrank[j] = temp[j];
	}
	/*userrank[size - 1].PlayerName = name;
	userrank[size - 1].TimeUsed = time;
	userrank[size - 1].GameMode = mode;
	userrank[size - 1].size = siz;*/


	delete[]temp;

	ofstream fout;
	fout.open("len.txt",ios_base::trunc);
	fout << size;
	fout.close();
	fout.open("rank_Classic.txt");
	if (fout.fail()) {
		fout.open("rank_Classic.txt", ios::out);
	}

	if (time < userrank[size - 2].TimeUsed) {
		userrank[size - 1].TimeUsed = time;
		userrank[size - 1].PlayerName = name;
		sort(userrank, userrank + size, SortByTime);
		for (int i = 0; i < size; i++) {
			fout << i + 1 << " " << userrank[i].TimeUsed << endl;
		}
		fout.close();
	}
}
void Insertrecord_30(string name, int time, string mode, int siz)
{
	int size;
	ifstream fin;
	fin.open("len_30.txt");
	fin >> size;
	fin.close();
	Record* userrank;
	userrank = new Record[size];
	fin.open("rank_Classic_30.txt");
	string line;
	int count = 0;
	while (getline(fin, line)) {
		istringstream line_in(line);
		line_in >> userrank[count].PlayerName;
		line_in >> userrank[count].TimeUsed;
		count += 1;
	}
	fin.close();
	Record* temp = new Record[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = userrank[i];
	}
	delete[]userrank;
	size++;
	userrank = new Record[size];
	for (int j = 0; j < size - 1; j++)
	{
		userrank[j] = temp[j];
	}
	/*userrank[size - 1].PlayerName = name;
	userrank[size - 1].TimeUsed = time;
	userrank[size - 1].GameMode = mode;
	userrank[size - 1].size = siz;*/


	delete[]temp;

	ofstream fout;
	fout.open("len_30.txt", ios_base::trunc);
	fout << size;
	fout.close();
	fout.open("rank_Classic_30.txt");
	if (fout.fail()) {
		fout.open("rank_Classic_30.txt", ios::out);
	}

	if (time < userrank[size - 2].TimeUsed) {
		userrank[size - 1].TimeUsed = time;
		userrank[size - 1].PlayerName = name;
		sort(userrank, userrank + size, SortByTime);
		for (int i = 0; i < size; i++) {
			fout << i + 1 << " " << userrank[i].TimeUsed << endl;
		}
		fout.close();
	}
}
void Insertrecord_40(string name, int time, string mode, int siz)
{
	int size;
	ifstream fin;
	fin.open("len_40.txt");
	fin >> size;
	fin.close();
	Record* userrank;
	userrank = new Record[size];
	fin.open("rank_Classic_40.txt");
	string line;
	int count = 0;
	while (getline(fin, line)) {
		istringstream line_in(line);
		line_in >> userrank[count].PlayerName;
		line_in >> userrank[count].TimeUsed;
		count += 1;
	}
	fin.close();
	Record* temp = new Record[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = userrank[i];
	}
	delete[]userrank;
	size++;
	userrank = new Record[size];
	for (int j = 0; j < size - 1; j++)
	{
		userrank[j] = temp[j];
	}
	/*userrank[size - 1].PlayerName = name;
	userrank[size - 1].TimeUsed = time;
	userrank[size - 1].GameMode = mode;
	userrank[size - 1].size = siz;*/


	delete[]temp;

	ofstream fout;
	fout.open("len_40.txt", ios_base::trunc);
	fout << size;
	fout.close();
	fout.open("rank_Classic_40.txt");
	if (fout.fail()) {
		fout.open("rank_Classic_40.txt", ios::out);
	}

	if (time < userrank[size - 2].TimeUsed) {
		userrank[size - 1].TimeUsed = time;
		userrank[size - 1].PlayerName = name;
		sort(userrank, userrank + size, SortByTime);
		for (int i = 0; i < size; i++) {
			fout << i + 1 << " " << userrank[i].TimeUsed << endl;
		}
		fout.close();
	}
}

void Display(int size)
{
	ifstream fin;
	switch (size)
	{
	case 20 : fin.open("rank_Classic.txt"); break;
	case 30 : fin.open("rank_Classic_30.txt"); break;
	case 40 : fin.open("rank_Classic_40.txt"); break;
	default: cout << "Record system for size " << size << " is currently unavailable." << endl;
	}
	if (fin.fail())
	{
		cout << "Record system for size " << size << " is currently unavailable." << endl;
	}
	else
	{
	string line;
	int count = 0;
	while (getline(fin, line)) {
		if (count > 4) break;
		cout << line << endl;
		count += 1;
	}
	fin.close();
	}
}

