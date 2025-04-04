#include "piece_movement.h"
#include <vector>

PieceMovement* find_piece_movement(std::vector<PieceMovement*> allowed_movements, int movement_front, int movement_side)
{
	int front_squares = movement_front > 0 ? movement_front : 0;
	int back_squares = movement_front < 0 ? movement_front * -1 : 0;
	int left_squares = movement_side < 0 ? movement_side * -1 : 0;
	int right_squares = movement_side > 0 ? movement_side : 0;

	for(PieceMovement* allowed_movement: allowed_movements)
	{
		if(allowed_movement->match_movement(left_squares, front_squares, right_squares, back_squares, true))
			return allowed_movement;
	}

	return nullptr;
}
