#include <vector>
#include <string>
using namespace std;

#ifndef Gernerator_H
#define Generator_H

typedef pair<int, int> PII;

class maze_generation
{
public:
	void maze_generator(string command);
	//use prim algorithm to generator the maze

	void maze_printer();
	//print the maze
	void maze_printer_Foggy(int sight);
	maze_generation(int s);
	// a constructor 
	// int s is the size desired
	// initialize all grids to be the wall
	// set the outmost periphery as the land
	void player_insertion(char player, int y, int x);
	void update_player_location(int y1, int x1, int y2, int x2); //This function will update the player's location on the maze
	bool check_wall(int y, int x);
	void just_update_player(int y1, int x1, int y2, int x2);



private:
	int size;
	vector<vector<int>> maze;
	int wall = 0;
	int land = 1;
	vector<PII> frontiers;
	int player_x;
	int player_y;

};


#endif
