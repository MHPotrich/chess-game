#include <string>
#include <array>
#include <vector>
#include <optional>
#include "player.h"

#ifndef TABLE_H
#define TABLE_H

#define X_TABLE_SIZE 8
#define Y_TABLE_SIZE 8

enum piece_color: int {
	WHITE,
	BLACK	
};

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

struct TablePosition
{
	int x;
	int y;

	TablePosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}	
};

class Piece 
{
	private:
		int color;
		bool is_upgradable;
		std::string name;
		Player* owner;
		std::vector<PieceMovement*> allowed_movements;

	public:
		Piece(int color, bool is_upgradable, std::string name, Player* player)
		{
			this->color = color;
			this->is_upgradable = is_upgradable;
			this->name = name;
			this->owner = player;
			
			if(name == "pawn")
			{
				PieceMovement* to_front = new PieceMovement(0, 1, 0, 0);
				PieceMovement* to_front_left = new PieceMovement(0, 0, 1, 0, 0, 0, 0, 0);
				PieceMovement* to_front_right = new PieceMovement(0, 0, 0, 0, 1, 0, 0, 0);
				
				to_front->set_only_not_empty(true);
				to_front->set_is_fixed_squares(true);
				to_front_left->set_is_fixed_squares(true);
				to_front_right->set_is_fixed_squares(true);
				
				this->allowed_movements.push_back(to_front);
				this->allowed_movements.push_back(to_front_right);
				this->allowed_movements.push_back(to_front_left);
			}
		}

		int get_color()
		{
			return this->color;
		}

		bool get_is_upgradable()
		{
			return this->is_upgradable;
		}

		void change_is_upgradable(bool new_value)
		{
			this->is_upgradable = new_value;
		}

		std::string get_name()
		{
			return this->name;
		}

		Player* get_owner()
		{
			return this->owner;
		}

		std::vector<PieceMovement*> get_allowed_movements()
		{
			return this->allowed_movements;
		}
};

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

std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> create_table(Player* player_one, Player* player_two);

int convert_to_number(char number);

TablePosition* convert_input(std::string raw_input);

#endif /* TABLE_H */
