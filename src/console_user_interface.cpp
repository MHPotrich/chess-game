#include <array>
#include <string>
#include <iostream>
#include <optional>
#include "console_user_interface.h"
#include "space.h"
#include "player.h"
#include "table_position.h"

void show_table(std::array<std::array<Space*, 8>, 8> table, std::optional<TablePosition*> selected_piece_position)
{
	for(int y = 0; y < 8; y++)
	{
		std::cout << y + 1;

		for(int x = 0; x < 8; x++)
		{
			if(!table[y][x]->check_is_empty())
			{
				if(selected_piece_position.has_value() && selected_piece_position.value()->x == x && selected_piece_position.value()->y == y)
				{
					char selected_piece_letter = std::toupper(table[y][x]->get_piece()->get_name().c_str()[0]);

					std::cout << "[" << selected_piece_letter << "]";
				}
				else
				{
					std::cout << "[" << table[y][x]->get_piece()->get_name()[0] << "]";
				}
			}
			else
			{
				printf("[ ]");
			}
		}

		printf("\n");
	}

	std::cout << "  a  b  c  d  e  f  g  h" << std::endl << std::endl;
}

void show_player_info(Player* player, std::string player_name)
{
	std::cout << "remaning pieces " << player_name << ": " << player->get_total_pieces() << "\n";
}

void show_control_piece(std::string* input_value, bool is_piece_selected)
{
	if(is_piece_selected)
	{
		std::cout << "move to(example of input: 1b): ";
		std::cin >> *input_value;

		return;
	}

	std::cout << "select piece(example of input: 1b): ";
	std::cin >> *input_value;
	std::cout << std::endl;
}

void clear_console()
{

}

void show_not_piece_warning()
{
	std::cout << "There's not piece in this square!" << "\n";
	std::cout << "\n";
}
