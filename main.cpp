#include <array>
#include "player.h"
#include "table.h"
#include "terminalScreen.h"

int main()
{
	std::array<std::array<Space*, X_TABLE_SIZE>, Y_TABLE_SIZE> table = create_table(); 
		
	Screen* screen = new Screen(table);

	screen->show_in_game_screen();
	
	return 0;
}
