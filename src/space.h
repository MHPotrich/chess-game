#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <optional>
#include "piece.h"

class Space
{
	private:
		std::optional<Piece*> piece;
		bool is_empty = true;
		int x_position;
		int y_position;

	public:
		Space(int x, int y)
		{
			this->x_position = x;
			this->y_position = y;
		}

		~Space()
		{
			delete this->piece.value();
		}

		bool check_is_empty()
		{
			return is_empty;
		}

		void change_piece(Piece* new_piece)
		{
			if(this->is_empty == false){
				if(new_piece->get_color() == this->piece.value()->get_color()) return;

				this->piece.value()->get_owner()->decrement_total_pieces(1);
			}
			
			this->piece = new_piece;
			this->is_empty = false;
		}

		void remove_piece()
		{
			this->piece.reset();
			this->is_empty = true;
		}

		Piece* get_piece()
		{
			return this->piece.value();
		}

		int get_x()
		{
			return this->x_position;
		}

		int get_y()
		{
			return this->y_position;
		}
};

bool is_piece_movement_valid(Space* origin, Space* destination, std::vector<Space*> movement_path);

#endif /* SPACE_H */
