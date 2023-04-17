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
	int wall = 0;
	int land = 1;
	vector<PII> frontiers;

};


#endif
