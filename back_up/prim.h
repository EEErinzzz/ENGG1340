#include <vector>
using namespace std;

#ifndef Generator_H
#define Generator_H

typedef pair<int, int> PII;

class maze_generation
{
public:
	void maze_generator();
	//use prim algorithm to generator the maze

	void maze_printer();
	//print the maze

	maze_generation(int s);
	// a constructor 
	// initialize all grids to be the wall
	// set the outmost periphery as the land
private:
	int size;
	vector<vector<int>> maze;
	//maze is a 2-D vector
	int wall = 0;
	int land = 1;
	vector<PII> frontiers;
	// frontiers is the up, down, left, right grid that is wall around the current grid
	// all frontiers are saved in this vector

};


#endif
