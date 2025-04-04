#include <vector>
#include <iostream>
#include "space.h"

bool is_piece_movement_valid(Space* origin, Space* destination, std::vector<Space*> movement_path)
{
	// validate piece path
	for(Space* path_space: movement_path)
	{
		std::cout << "y: " << path_space->get_y() << " x: " << path_space->get_x() << "\n";
	}

	return true;
}
