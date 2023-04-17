#include "maze_generator.h"
#include<time.h>
#include <iostream>
#include <cstdio>
#include <algorithm>


maze_generation::maze_generation(int s)
{
	//initialize all grids in the maze as wall
	size = s;
	maze.resize(size);
	for (int j = 0; j < size; j++)
	{
		maze[j].resize(size);
		for (int i = 0; i < size; i++)
		{

			maze[j][i] = wall;
		}
	}
	// set the outmost periphery as the land to prevent from overriding the boundary
	for (int i = 0; i < size; i++) {
		maze[i][0] = 1;
		maze[0][i] = 1;
		maze[size - 1][i] = 1;
		maze[i][size - 1] = 1;
	}

}

void maze_generation::maze_generator()
{
	frontiers.push_back({ 2,2 });
	// randomly choose a grid as the initial point

	while (frontiers.size())
	{
		srand(time(0));
		int r = rand() % frontiers.size();
		int cur_y = frontiers[r].first;
		int cur_x = frontiers[r].second;
		
		// judge whether the surounding(up,down,left and right) of cur_ is connected by land
		int count = 0;
		for (int i = cur_y - 1; i < cur_y + 2; i++) {
			for (int j = cur_x - 1; j < cur_x + 2; j++) {
				if (abs(cur_y - i) + abs(cur_x - j) == 1 && maze[i][j] > 0) {
					++count;
				}
			}
		}
		
		if (count <= 1)
		{
			maze[cur_y][cur_x] = 1;
			// make it the land

			// add the frontiers of the new land to the vector frontiers
			for (int i = cur_y - 1; i < cur_y + 2; i++)
			{
				for (int j = cur_x - 1; j < cur_x + 2; j++)
				{
					if (abs(cur_y - i) + abs(cur_x - j) == 1 && maze[i][j] == 0) frontiers.push_back({ i,j });
				}
			}
		}
		
		frontiers.erase(frontiers.begin()+r);
			// since it is already marked as land, it should be removed from the frontiers vector
	}
	//set the exit and entry
	maze[2][1] = 1;
	for (int i = size - 3; i >= 0; i--) {
		if (maze[i][size - 3] == 1) 
		{
			maze[i][size - 2] = 1;
			break;
		}
	}
}

void maze_generation::maze_printer()
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			if (maze[i][j] == 1) printf(" ");
			else printf("M");
		}
		cout << endl;
	}
}