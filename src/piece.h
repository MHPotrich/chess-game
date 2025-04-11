#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "player.h"
#include "piece_movement.h"

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
				
				to_front->set_allow_jump_piece(true);
				to_front->set_is_fixed_squares(true);
				to_front_left->set_is_fixed_squares(true);
				to_front_right->set_is_fixed_squares(true);
				
				this->allowed_movements.push_back(to_front);
				this->allowed_movements.push_back(to_front_right);
				this->allowed_movements.push_back(to_front_left);
			}

			if(name == "king")
			{
				PieceMovement* to_front = new PieceMovement(0, 1, 0, 0);
				PieceMovement* to_left = new PieceMovement(1, 0, 0, 0);
				PieceMovement* to_right = new PieceMovement(0, 0, 1, 0);
				PieceMovement* to_back = new PieceMovement(0, 0, 0, 1);
				PieceMovement* to_front_left = new PieceMovement(0, 0, 1, 0, 0, 0, 0, 0);
				PieceMovement* to_front_right = new PieceMovement(0, 0, 0, 0, 1, 0, 0, 0);
				PieceMovement* to_back_left = new PieceMovement(1, 0, 0, 0, 0, 0, 0, 0);
				PieceMovement* to_back_right = new PieceMovement(0, 0, 0, 0, 0, 0, 1, 0);

				this->allowed_movements.push_back(to_front);
				this->allowed_movements.push_back(to_left);
				this->allowed_movements.push_back(to_right);
				this->allowed_movements.push_back(to_back);
				this->allowed_movements.push_back(to_front_left);
				this->allowed_movements.push_back(to_front_right);
				this->allowed_movements.push_back(to_back_left);
				this->allowed_movements.push_back(to_back_right);
			}

			if(name == "rook")
			{
				PieceMovement* to_front = new PieceMovement(0, 8, 0, 0);
				PieceMovement* to_left = new PieceMovement(8, 0, 0, 0);
				PieceMovement* to_right = new PieceMovement(0, 0, 8, 0);
				PieceMovement* to_back = new PieceMovement(0, 0, 0, 8);

				this->allowed_movements.push_back(to_front);
				this->allowed_movements.push_back(to_left);
				this->allowed_movements.push_back(to_right);
				this->allowed_movements.push_back(to_back);
			}

			if(name == "bishop")
			{
				PieceMovement* to_front_left = new PieceMovement(0, 0, 8, 0, 0, 0, 0, 0);
				PieceMovement* to_front_right = new PieceMovement(0, 0, 0, 0, 8, 0, 0, 0);
				PieceMovement* to_back_left = new PieceMovement(8, 0, 0, 0, 0, 0, 0, 0);
				PieceMovement* to_back_right = new PieceMovement(0, 0, 0, 0, 0, 0, 8, 0);

				this->allowed_movements.push_back(to_front_left);
				this->allowed_movements.push_back(to_front_right);
				this->allowed_movements.push_back(to_back_left);
				this->allowed_movements.push_back(to_back_right);
			}

			if(name == "knight")
			{

			}

			if(name == "queen")
			{

			}
		}

		~Piece()
		{
			delete this->owner;
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


#endif /* PIECE_H */
