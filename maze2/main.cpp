#include "maze_generator.h"
#include <iostream>
int main()
{
	cout << "Enter a size for the maze" << endl;
	int size;
	cin >> size;
	maze_generation our_maze(size);
	our_maze.maze_generator();
	our_maze.maze_printer();
}