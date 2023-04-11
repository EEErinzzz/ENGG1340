#include "prim.h"
#include <cstdlib>
#include<time.h>

void maze::prim::find_frontier(int y, int x)
{
	map[y][x] = land;
		//mark the current position as land
	if ((y > 2) && (wall == map[y - 2][x]))
	{
		map[y - 2][x] = frontier;
		frontiers.push_back({ y - 2,x });
	}
	if ((y + 2 <= map.size() - 2) && (wall == map[y + 2][x]))
	{
		map[y+2][x] = frontier;
		frontiers.push_back({ y + 2,x });
	}
	if ((x >= 3) && wall == map[y][x - 2])
	{
		map[y][x - 2] = frontier;
		frontiers.push_back({ y,x - 2 });
	}
	if ((x + 2 <= map[0].size() - 2) && (wall == map[y][x + 2]))
	{
		map[y][x + 2] = frontier;
		frontiers.push_back({ y,x + 2 });
	}
}

void maze::prim::explore()
{
	//*******************intialization:generate random start point*****************
	srand((unsigned)time(NULL));
	int rand_start_y = (rand() % (map.size() - 1)) + 1;
		// generate a random int in range[1,height of the map]
	int rand_start_x = (rand() % (map[0].size() - 1)) + 1;
		// generate a random int in range[1,width of the map]
	find_frontier(rand_start_y, rand_start_x);
	//find the intial frontier

	while (!frontiers.empty())
	{
		bool occupied = false;

		srand((unsigned)time(NULL));
		int rand_frontier = rand() % (frontiers.size() - 1);
			//randomly generate a number as the index of the frontier
		int y = frontiers[rand_frontier].x;
		int x = frontiers[rand_frontier].y;
			//a randomly selected frontier is used as the new start
		frontiers.erase(frontiers.begin() + rand_frontier);
			// since it is used as the new start, it should be popped out
		find_frontier(x, y);
			//find the frontier of the new start

		while (!occupied)//loop until find a valid movement
		{
			srand((unsigned)time(NULL));
			int rand_dir = rand() % 4;
				// generate a random int in range[1,3]
	     		// each int in [1,3] symbolizes a direction

			if (rand_dir == north)
				//move to the north(0)
			{
				if ((y > 2) && (land == map[y - 2][x]))
					//boundary judgment
				{
					occupied = true;
					map[y - 1][x] = land;
				}
				else if (rand_dir == south)
				{
					if ((y + 2 < map.size() - 1) && (land == map[y + 2][x]))
					{
						map[y + 1][x] = land;
						occupied = true;
					}
				}
				else if (rand_dir == west)
				{
					if (x > 2 && land == map[y][x - 2])
					{
						map[y][x - 1] = land;
						occupied = true;
					}
				}
				else if (rand_dir == east)
				{
					if (x + 2 < map[0].size() - 1 && land == map[y][x + 2])
					{
						map[y][x + 1] = land;
						occupied = true;
					}
				}
			}
		}
	}
}
