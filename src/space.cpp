#include <vector>
#include <iostream>
#include "space.h"
#include "piece.h"
#include "piece_movement.h"

bool is_piece_movement_valid(Space* origin, Space* destination, std::vector<Space*> movement_path)
{
	Piece* piece = origin->get_piece();
	int movement_front = origin->get_y() - destination->get_y();
	int movement_side = origin->get_x() - destination->get_x();
	PieceMovement* this_piece_movement = find_piece_movement(piece->get_allowed_movements(), movement_front, movement_side);

	if(this_piece_movement == nullptr) return false;

	std::cout << "front value: " << movement_front << "\nside value: " << movement_side << "\n\n";

	// validate piece path
	for(Space* path_space: movement_path)
	{
		bool is_origin_space = origin == path_space;
		bool is_destination_space = destination == path_space;

		std::cout << "y: " << path_space->get_y() << " x: " << path_space->get_x() << "\n";

		if(is_origin_space == false && is_destination_space == false)
		{
			if(path_space->check_is_empty() == false && this_piece_movement->get_allow_jump_piece()) return false;
		}
	}

	return true;
}
