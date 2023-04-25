#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include "rank.h"
using namesapce std;
bool SortByTime(Record a, Record b);
void Addrecord(string name, int time);
void Insertrecord(string name, int time);
void Display();
struct Record rank[5];

int main() // read the output from other cpp files and write it to the txt file
{
   
}
int rank(string name, int time)
{
	fstream fin("rank_classic.txt",ios::in)
}

bool SortByTime(Record a, Record b)
{
	if( a.TimeUsed != b.TimeUsed)
		return a.TimeUsed < b.TimeUsed;
}
void Addrecord(string name, int time) // in case there are less than 5 players play the game
{
	fstream fin("rank_classic.txt",ios::in);
	ofstream fout("rank_classic.txt");
	char c;
	int line = 0;
	while(fin.get(c))
	{
		if(c == "\n")
			line++;
	}
    if(line<=1)
	{
			rank[line].TimeUsed=time;
			rank[line].PlayerName=name;
	}
	elseif(line>1)
	{
			rank[line].TimeUsed=time;
			rank[line].PlayerName=name;
			sort(rank, rank +line, SortByTime);
			for (int i = 0; i < line;i++){
				fout <<i+1<<" "<<rank[i].PlayerName <<" "<<rank[i].TimeUsed<<endl;					
	}
	fin.close();
	fout.close();
}

void Insertrecord(string name, int time) // check and adjust the rank
{
	ofstream fout;
	fout.open("rank_Classic.txt");
	if ( fout.fail() ){
		cout << "Error in opening the file !" << endl;
	}else{
		if( time < rank[5].TimeUsed){
			rank[5].TimeUsed=time;
			rank[5].PlayerName=name;
			sort(rank, rank +5, SortByTime);
			for (int i = 0; i < 5;i++){
				fout <<i+1<<" "<<rank[i].PlayerName <<" "<<rank[i].TimeUsed<<endl;
		}
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
