#ifndef TABLE_H
#define TABLE_H

#include <array>
#include <string>
#include <vector>
#include "player.h"
#include "space.h"
#include "table_position.h"

#define X_TABLE_SIZE 8
#define Y_TABLE_SIZE 8

enum piece_color: int {
	WHITE,
	BLACK	
};

std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> create_table(Player* player_one, Player* player_two);

int convert_to_number(char number);

TablePosition* convert_input(std::string raw_input);

std::vector<Space*> generate_piece_movement_path(std::array<std::array<Space*, 8>, 8> table, TablePosition* origin, TablePosition* destination);

void delete_table_space(std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table);

#endif /* TABLE_H */
