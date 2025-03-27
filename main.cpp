#include <vector>
#include <string>
#include <optional>
#include <iostream>
#include <array>

#define X_TABLE_SIZE 8
#define Y_TABLE_SIZE 8
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
};

class Piece 
{
	private:
		int color;
		bool is_upgradable;
		std::string name;
		Player* owner;

	public:
		Piece(int color, bool is_upgradable, std::string name, Player* player)
		{
			this->color = color;
			this->is_upgradable = is_upgradable;
			this->name = name;
			this->owner = player;
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

class Screen
{
	private:
		std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table;

	public:
		Screen(std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table)
		{
			this->table = table;
		}

		void show_start_screen()
		{
		
		}

		void show_in_game_screen()
		{
			// show table
			for(int y = 0; y < Y_TABLE_SIZE; y++)
			{
				std::cout << y + 1;

				for(int x = 0; x < X_TABLE_SIZE; x++)
				{
					if(!this->table[y][x]->check_is_empty())
					{
						std::cout << "[" << this->table[y][x]->get_piece()->get_name()[0] << "]";
					}
					else
					{
						printf("[ ]");
					}
				}

				printf("\n");
			}

		}

		void show_end_screen()
		{

		}
};

int main()
{
	enum piece_color: int {
		WHITE,
		BLACK
	};

	std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table;

	for(int line_i = 0; line_i < Y_TABLE_SIZE; line_i++)
	{
		for(int row_i = 0; row_i < X_TABLE_SIZE; row_i++)
		{
			table[line_i][row_i] = new Space(row_i, line_i);
		}
	}

	Player* player_one = new Player(WHITE);
	Player* player_two = new Player(BLACK);

	// white pieces - player 1
	Piece* white_king = new Piece(WHITE, false, "king", player_one); // 1
	Piece* white_queen = new Piece(WHITE, false, "queen", player_one); // 1
	Piece* white_pawn = new Piece(WHITE, true, "pawn", player_one); // 8
	Piece* white_bishop = new Piece(WHITE, false, "bishop", player_one); // 2
	Piece* white_knight = new Piece(WHITE, false, "knight", player_one); // 2
	Piece* white_rook = new Piece(WHITE, false, "rook", player_one); // 2

	// black pieces - player 2
	Piece* black_king = new Piece(BLACK, false, "king", player_two); // 1
	Piece* black_queen = new Piece(BLACK, false, "queen", player_two); // 1
	Piece* black_pawn = new Piece(BLACK, true, "pawn", player_two); // 8
	Piece* black_bishop = new Piece(BLACK, false, "bishop", player_two); // 2
	Piece* black_knight = new Piece(BLACK, false, "knight", player_two); // 2
	Piece* black_rook = new Piece(BLACK, false, "rook", player_two); // 2
	
	// positionate pawns
	for(int i = 0; i < X_TABLE_SIZE; i++)
	{
		table[1][i]->change_piece(white_pawn);
		table[6][i]->change_piece(black_pawn);
	}
	
	// positionate rooks
	table[0][0]->change_piece(white_rook);
	table[0][7]->change_piece(white_rook);
	table[7][0]->change_piece(black_rook);
	table[7][7]->change_piece(black_rook);

	// positionate knights
	table[0][1]->change_piece(white_knight);
	table[0][6]->change_piece(white_knight);
	table[7][1]->change_piece(black_knight);
	table[7][6]->change_piece(black_knight);

	// positionate bishop
	table[0][2]->change_piece(white_bishop);
       	table[0][5]->change_piece(white_bishop);
	table[7][2]->change_piece(black_bishop);
	table[7][5]->change_piece(black_bishop);

	// positionate queen
	table[0][3]->change_piece(white_queen);
	table[7][3]->change_piece(black_queen);

	// positionate king
	table[0][4]->change_piece(white_king);
	table[7][4]->change_piece(black_king);	
	
	Screen* screen = new Screen(table);

	screen->show_in_game_screen();
	
	return 0;
}
