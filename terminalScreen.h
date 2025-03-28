#include <array>
#include <iostream>
#include "table.h"

#ifndef TERMINAL_SCREEN
#define TERMINAL_SCREEN

#define X_TABLE_SIZE 8
#define Y_TABLE_SIZE 8

class Screen
{
	private:
		std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table;
		
		void show_header()
		{
			std::cout << "remaning pieces player 1: " << 0 << std::endl;
			std::cout << "remaning pieces player 1: " << 0 << std::endl;
			printf("\n");
		}

		void show_footer()
		{
			printf("\n");
			printf("select piece(example of input: 1b): ");
			printf("\n");
		}

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
