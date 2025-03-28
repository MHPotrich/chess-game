#ifndef PLAYER_H
#define PLAYER_H

#define MAX_PLAYER_PIECES_QUANTITY 16

class Player
{
	private:
		int pieces_color;
		int total_pieces = MAX_PLAYER_PIECES_QUANTITY;
	public:
		Player(int pieces_color)
		{
			this->pieces_color = pieces_color;
		}

		void decrement_total_pieces(int quantity)
		{
			this->total_pieces -= quantity;
		}

		bool is_still_in_game()
		{
			return this->total_pieces > 0;
		}

		int get_total_pieces()
		{
			return this->total_pieces;
		}
};

#endif /* PLAYER_H */
