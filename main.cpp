#include <vector>
#include <string>
#include <optional>
#include <iostream>

class Piece 
{
	private:
		int color;
		bool is_upgradable;
		std::string name;

	public:
		Piece(int color, bool is_upgradable, std::string name)
		{
			this->color = color;
			this->is_upgradable = is_upgradable;
			this->name = name;
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
};

class Space
{
	private:
		std::optional<Piece*> piece;
		bool is_avaliable = true;
		int x_position;
		int y_position;

	public:
		Space(int x, int y)
		{
			this->x_position = x;
			this->y_position = y;
		}

		bool check_is_avaliable()
		{
			return is_avaliable;
		}

		void change_piece(Piece* new_piece)
		{
			this->piece = new_piece;
			this->is_avaliable = false;
		}

		void remove_piece()
		{
			this->piece.reset();
			this->is_avaliable = true;
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

int main()
{
	enum piece_color: int {
		WHITE,
		BLACK
	};

	Space* table[7][7];

	for(int line_i = 0; line_i <= 7; line_i++)
	{
		for(int row_i = 0; row_i <= 7; row_i++)
		{
			table[line_i][row_i] = new Space(row_i, line_i);
		}
	}

	// white pieces - player 1
	Piece* white_king = new Piece(WHITE, false, "king"); // 1
	Piece* white_queen = new Piece(WHITE, false, "queen"); // 1
	Piece* white_pawn = new Piece(WHITE, true, "pawn"); // 8
	Piece* white_bishop = new Piece(WHITE, false, "bishop"); // 2
	Piece* white_knight = new Piece(WHITE, false, "knight"); // 2
	Piece* white_rook = new Piece(WHITE, false, "rook"); // 2

	// black pieces - player 2
	Piece* black_king = new Piece(BLACK, false, "king"); // 1
	Piece* black_queen = new Piece(BLACK, false, "queen"); // 1
	Piece* black_pawn = new Piece(BLACK, true, "pawn"); // 8
	Piece* black_bishop = new Piece(BLACK, false, "bishop"); // 2
	Piece* black_knight = new Piece(BLACK, false, "knight"); // 2
	Piece* black_rook = new Piece(BLACK, false, "rook"); // 2
	
	// positionate pawns
	for(int i = 0; i <= 7; i++)
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

	// show table
	for(int y = 0; y <= 7; y++)
	{
		std::cout << y + 1;

		for(int x = 0; x <= 7; x++)
		{
			if(!table[y][x]->check_is_avaliable())
			{
				std::cout << "[" << table[y][x]->get_piece()->get_name()[0] << "]";
			}
			else
			{
				printf("[ ]");
			}
		}

		printf("\n");
	}

	return 0;
}
