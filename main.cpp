#include <array>
#include "player.h"
#include "table.h"
#include "terminalScreen.h"

int main()
{
	bool is_running = true;
	Player* player_one = new Player(WHITE);
	Player* player_two = new Player(BLACK);
	std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table = create_table(player_one, player_two); 
	Screen* screen = new Screen(table, player_one, player_two);
	
	while(is_running)
	{
		screen->show_in_game_screen();
	}

	return 0;
}
