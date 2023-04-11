#ifndef PRIM_H
#define PRIM_H
#include "general_maze_generator.h"
#include <vector>
using namespace std;
namespace maze
{
	class prim : public maze_generator
	{
	public:
		using maze_generator::set_all_wall;
		void explore(int y, int x); // in prim algorithm, a random direction is selected to be explored 
		
	private:
		static constexpr int frontier = 2;
		
		struct frontier_candidates 
		{
			int y;
			int x;
		};
		vector <frontier_candidates> frontiers;
		//creat a object vector 
		//each element of the vector has x and y value which is constructed in the struct

		void find_frontier(int y, int x);
		// this function is to find the surroundinig grid of the current grid
	};
}


#endif // !PRIM_H

