#include "General_generator.h"
#include <iostream>
using namespace std;
maze::maze_generator::maze_generator(uint32_t height, uint32_t width)
{
	if ((height % 2u == 0) || (height % 2u == 0))
	{
		cout << "Please enter odd numbers for height and width" 
	}
	else
	{
		area.resize(height);
		for (uint32_t y = 0u; y < height; y++)
		{
			area.resize(width);
			for (uint32_t x = 0u; x < width; x++)
			{
				area[y][x] = wall;
        //fill up the maze with wall(0)
			}

		}
	}
}
