#include <array>
#include <iostream>
#include <string>
#include <cctype>
#include <optional>
#include "table.h"
#include "player.h"

#ifndef TERMINAL_SCREEN
#define TERMINAL_SCREEN

#define X_TABLE_SIZE 8
#define Y_TABLE_SIZE 8

class Screen
{
	private:
		std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table;
		Player* player_one;
		Player* player_two;
		std::string piece_position_input = "";
		std::string destination_position_input = "";

		void show_header()
		{
			std::cout << "remaning pieces player 1: " << this->player_one->get_total_pieces() << std::endl;
			std::cout << "remaning pieces player 2: " << this->player_two->get_total_pieces() << std::endl;
			printf("\n");
		}

		void reset_input()
		{
			this->piece_position_input = "";
			this->destination_position_input = "";
		}

		void show_footer()
		{
			if(this->piece_position_input.length() > 0)
			{
				TablePosition* selected_piece_position = convert_input(piece_position_input);

				std::cout << "move to(example of input: 1b): ";
				std::cin >> destination_position_input;
				
				TablePosition* destination_piece_position = convert_input(destination_position_input);
				Space* selected_piece_space = this->table[selected_piece_position->x][selected_piece_position->y];
				Space* destination_piece_space = this->table[destination_piece_position->x][destination_piece_position->y];
				Piece* selected_piece = selected_piece_space->get_piece();
				
				selected_piece_space->remove_piece();
				destination_piece_space->change_piece(selected_piece);
				
				this->reset_input();
				return;
			}

			std::cout << "select piece(example of input: 1b): ";
			std::cin >> piece_position_input;
			std::cout << std::endl;
		}

		void show_table()
		{
			std::optional<TablePosition*> selected_piece_position;

			if(this->piece_position_input.length() > 0) selected_piece_position = convert_input(piece_position_input);

			for(int y = 0; y < Y_TABLE_SIZE; y++)
			{
				std::cout << y + 1;

				for(int x = 0; x < X_TABLE_SIZE; x++)
				{
					if(!this->table[y][x]->check_is_empty())
					{
						if(selected_piece_position.has_value() && selected_piece_position.value()->x == x && selected_piece_position.value()->y == y)
						{
							char selected_piece_letter = std::toupper(this->table[y][x]->get_piece()->get_name().c_str()[0]);

							std::cout << "[" << selected_piece_letter << "]";
						}
						else
						{
							std::cout << "[" << this->table[y][x]->get_piece()->get_name()[0] << "]";
						}
					}
					else
					{
						printf("[ ]");
					}
				}

				printf("\n");
			}

			std::cout << "  a  b  c  d  e  f  g  h" << std::endl;
		}

	public:
		Screen(std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table, Player* player_one, Player* player_two)
		{
			this->table = table;
			this->player_one = player_one;
			this->player_two = player_two;
		}

		void show_start_screen()
		{
		
		}

		void show_in_game_screen()
		{
			show_header();	
			show_table();
			show_footer();
		}

		void show_end_screen()
		{

		}
};


#endif /* TERMINAL_SCREEN */
