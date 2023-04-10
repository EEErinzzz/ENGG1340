#ifndef MAZE_GENERATOR_H_
#define MAZE_GENERATOR_H_

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

namespace maze
{
  class maze_generator
  {
    public:
      explicit maze_generator(uint32_t height, uint32_t width);
    //generate the maze

      static constexpr uint32_t wall     = 0u;
      static constexpr uint32_t hole     = 1u;
      static constexpr uint32_t solution = 2u;

      void set_cell(uint32_t y, uint32_t x, uint32_t value);
    //set the value of the cell(wall is 1, land is 0)
      uint32_t get_cell(uint32_t y, uint32_t x);
    //return the value of the cell(0 or 1)

      std::vector<std::vector<uint32_t>> get_maze(void);
    // return the maze which is a 2-D vector
      void set_maze(std::vector<std::vector<uint32_t>> vect);
    //reset the maze manually

      void reshape(uint32_t new_height, uint32_t new_width);
    //change the height and width of the maze

      uint32_t get_height(void);
    // return the height of the maze
      uint32_t get_width(void);
    // return the width of the maze

    protected:
      std::random_device random_device;

      static constexpr uint32_t vertical    = 0u;
      static constexpr uint32_t horizontal  = 1u;

      static constexpr uint8_t north  = 0u;
      static constexpr uint8_t south  = 1u;
      static constexpr uint8_t west   = 2u;
      static constexpr uint8_t east   = 3u;

      std::vector<std::vector<uint32_t>> area;

      
  };
}

#endif /* MAZE_GENERATOR_H_ */
