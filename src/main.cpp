#include <array>
#include <iostream>
#include <optional>
#include "player.h"
#include "space.h"
#include "table.h"
#include "console_user_interface.h"
#include "table_position.h"

void main_game()
{
	bool is_running = true;
	Player* player_one = new Player(WHITE);
	Player* player_two = new Player(BLACK);
	std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table = create_table(player_one, player_two);
	std::string* input_select_piece = new std::string();
	std::string* input_move_piece = new std::string();
	std::optional<TablePosition*> selected_piece_position;
	std::optional<TablePosition*> destination_piece_position;
	std::optional<Space*> selected_piece_space;
	std::optional<Space*> destination_piece_space;

	while(is_running)
	{
		show_player_info(player_one, "player 1");
		show_player_info(player_two, "player 2");
		std::cout << "\n";
		show_table(table, selected_piece_position);
		std::cout << "\n";

		if(input_select_piece->empty())
		{
			show_control_piece(input_select_piece, false);
			selected_piece_position = std::make_optional(convert_input(*input_select_piece));
			selected_piece_space = std::make_optional(table[selected_piece_position.value()->y][selected_piece_position.value()->x]);

			if(selected_piece_space.value()->check_is_empty())
			{
				input_select_piece->clear();
				selected_piece_position.reset();
				selected_piece_space.reset();
				show_not_piece_warning();
			}
		}
		else
		{
			show_control_piece(input_move_piece, true);
			destination_piece_position = std::make_optional(convert_input(*input_move_piece));
			destination_piece_space = std::make_optional(table[destination_piece_position.value()->y][destination_piece_position.value()->x]);

			Piece* selected_piece = selected_piece_space.value()->get_piece();
			std::vector<Space*> movement_path = generate_piece_movement_path(table, selected_piece_position.value(), destination_piece_position.value());

			if(is_piece_movement_valid(selected_piece_space.value(), destination_piece_space.value(), movement_path))
			{
				destination_piece_space.value()->change_piece(selected_piece);
				selected_piece_space.value()->remove_piece();
			}

			// after move piece, reset input values, position and piece
			input_select_piece->clear();
			input_move_piece->clear();
			selected_piece_position.reset();
			destination_piece_position.reset();
			selected_piece_space.reset();
			destination_piece_space.reset();
		}
	}
};

int main()
{
	while(true){
		main_game();
	}

	return 0;
};
