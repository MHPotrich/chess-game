#include <array>
#include <vector>
#include <cctype>
#include "table.h"
#include "table_position.h"

std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> create_table(Player* player_one, Player* player_two)
{
	std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table;

	for(int line_i = 0; line_i < Y_TABLE_SIZE; line_i++)
	{
		for(int row_i = 0; row_i < X_TABLE_SIZE; row_i++)
		{
			table[line_i][row_i] = new Space(row_i, line_i);
		}
	}

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

	return table;	
}

int convert_to_number(char number)
{
	if(std::isupper(number)) number = std::tolower(number);	
	
	switch(number)
	{
		case 'a': return 0;
		case 'b': return 1;
		case 'c': return 2;
		case 'd': return 3;
		case 'e': return 4;
		case 'f': return 5;
		case 'g': return 6;
		case 'h': return 7; 
	};

	return 0;
}


TablePosition* convert_input(std::string raw_input)
{
	int y = raw_input.data()[0] - '0';
	int x = convert_to_number(raw_input.data()[1]); 
	
	y -= 1;

	return new TablePosition(x, y);
}

std::vector<Space*> generate_piece_movement_path(std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table, TablePosition* origin, TablePosition* destination)
{
	std::vector<Space*> movement_path;
	
	bool is_selected_y_higher_destination_y = origin->y < destination->y;
	bool is_selected_x_higher_destination_x = origin->x < destination->x;

	for(int y = origin->y; is_selected_y_higher_destination_y ? y <= destination->y : y >= destination->y ; is_selected_y_higher_destination_y ? y++ : y--)
	{
		for(int x = origin->x;is_selected_x_higher_destination_x ? x <= destination->x : x >= destination->x; is_selected_x_higher_destination_x ? x++ : x--)
		{
			movement_path.push_back(table[y][x]);
		}
	}

	return movement_path;
}

void delete_table_space(std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table)
{
	for(auto row: table)
	{
		for(auto *space: row)
		{
			delete space;
		}
	}
}
