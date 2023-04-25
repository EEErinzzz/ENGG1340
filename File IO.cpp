#include<iostream>
#include<fstream>
#include<string>
#include "rank.h"
using namesapce std;
int main()
{
  
}

Record rank[5];

bool SortByTime(rank a, rank b)
{
	if( a.TimeUsed != b.TimeUsed)
		return a.TimeUsed < b.TimeUsed;
}

void Insertrecord(string name, int time)
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
