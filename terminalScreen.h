#include <array>
#include <iostream>
#include <string>
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
			if(this->piece_position_input.length() > 0){
				std::cout << "move to(example of input: 1b): ";
				std::cin >> destination_position_input;

				convert_input(destination_position_input);

				this->reset_input();
				return;
			}

			std::cout << "select piece(example of input: 1b): ";
			std::cin >> piece_position_input;

			convert_input(piece_position_input);

			std::cout << std::endl;
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

			std::cout << "  a  b  c  d  e  f  g  h" << std::endl;
			show_footer();
		}

		void show_end_screen()
		{

		}
};


#endif /* TERMINAL_SCREEN */
