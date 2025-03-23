#include <vector>
#include <string>
#include <optional>

class Piece 
{
	private:
		int color;
		bool is_upgradable;

	public:
		Piece(int color, bool is_upgradable)
		{
			this->color = color;
			this->is_upgradable = is_upgradable;
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
};

class Space
{
	private:
		std::optional<Piece*> piece;
		bool is_avaliable = true;

	public:
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
			table[line_i][row_i] = new Space();
		}
	}

	// white pieces - player 1
	Piece* white_king = new Piece(WHITE, false); // 1
	Piece* white_queen = new Piece(WHITE, false); // 1
	Piece* white_pawn = new Piece(WHITE, true); // 8
	Piece* white_bishop = new Piece(WHITE, false); // 2
	Piece* white_knight = new Piece(WHITE, false); // 2
	Piece* white_rook = new Piece(WHITE, false); // 2

	// black pieces - player 2
	Piece* black_king = new Piece(BLACK, false); // 1
	Piece* black_queen = new Piece(BLACK, false); // 1
	Piece* black_pawn = new Piece(BLACK, true); // 8
	Piece* black_bishop = new Piece(BLACK, false); // 2
	Piece* black_knight = new Piece(BLACK, false); // 2
	Piece* black_rook = new Piece(BLACK, false); // 2
	
	for(int i = 0; i <= 7; i++)
	{
		table[1][i]->change_piece(white_pawn);
		table[6][i]->change_piece(black_pawn);
	}

	// show table
	for(int y = 0; y <= 7; y++)
	{
		for(int x = 0; x <= 7; x++)
		{
			printf(table[y][x]->check_is_avaliable() ? "[ ]" : "[x]");
		}

		printf("\n");
	}

	return 0;
}
