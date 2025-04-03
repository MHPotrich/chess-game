#ifndef CONSOLE_USER_INTERFACE_H
#define CONSOLE_USER_INTERFACE_H

#include <array>
#include <optional>
#include "table_position.h"
#include "space.h"

void show_table(std::array<std::array<Space*, 8>, 8> table, std::optional<TablePosition*> selected_piece_position);

void show_player_info(Player* player, std::string player_name);

void show_control_piece(std::string* input_value, bool is_piece_selected);

void clear_console();

void show_not_piece_warning();

#endif /* CONSOLE_USER_INTERFACE_H */
