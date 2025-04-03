#ifndef PIECE_MOVEMENT_H
#define PIECE_MOVEMENT_H

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
		bool only_not_empty = false;

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

		void set_only_not_empty(bool new_value)
		{
			this->only_not_empty = new_value;
		}
};

#endif /* PIECE_MOVEMENT_H */
