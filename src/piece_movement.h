#ifndef PIECE_MOVEMENT_H
#define PIECE_MOVEMENT_H

#include <vector>

class PieceMovement
{
	private:
		int front_squares = 0;
		int left_squares = 0;
		int right_squares = 0;
		int front_left_squares = 0;
		int front_right_squares = 0;
		int back_squares = 0;
		int back_left_squares = 0;
		int back_right_squares = 0;
		bool is_fixed_squares = false;
		bool allow_jump_piece = false;

	public:
		PieceMovement(int left, int front, int right, int back)
		{
			this->front_squares = front;
			this->left_squares = left;
			this->right_squares = right;
			this->back_squares = back;
		}

		PieceMovement(int back_left, int left, int front_left, int front, int front_right, int right, int back_right, int back)
		{
			this->front_squares = front;
			this->left_squares = left;
			this->right_squares = right;
			this->back_squares = back;
			this->back_left_squares = back_left;
			this->front_left_squares = front_left;
			this->front_right_squares = front_right;
			this->back_right_squares = back_right;
		}

		void set_is_fixed_squares(bool new_value)
		{
			this->is_fixed_squares = new_value;
		}

		void set_allow_jump_piece(bool new_value)
		{
			this->allow_jump_piece = new_value;
		}

		bool match_movement(int left, int front, int right, int back, bool is_fixed_squares)
		{
			return (this->left_squares == left && this->front_squares == front && this->right_squares == right && this->back_squares == back && this->is_fixed_squares == is_fixed_squares);
		}

		bool match_movement(int back_left, int left, int front_left, int front, int front_right, int right, int back_right, int back, bool is_fixed_squares)
		{
			return false;
		}

		bool get_allow_jump_piece()
		{
			return this->allow_jump_piece;
		}

};

PieceMovement* find_piece_movement(std::vector<PieceMovement*> allowed_movements, int movement_front, int movement_side);

#endif /* PIECE_MOVEMENT_H */
