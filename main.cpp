#include <vector>
#include <string>
#include <optional>

class Piece 
{
	private:
		std::string color;
		bool is_upgradable;

	public:
		Piece(std::string color, bool is_upgradable)
		{
			this->color = color;
			this->is_upgradable = is_upgradable;
		}

		std::string get_color()
		{
			return this->color;
		}

		bool get_is_upgradable()
		{
			return this->is_upgradable;
		}

		void change_is_upgradable(bool new_value)
		{
			this->is_upgradable = new_value;
		}
};

class Space
{
	private:
		std::optional<Piece> piece;
		bool is_avaliable = true;

	public:
		bool check_is_avaliable()
		{
			return is_avaliable;
		}

		void change_piece(Piece new_piece)
		{
			this->piece = new_piece;
			this->is_avaliable = false;
		}

		void remove_piece()
		{
			this->piece.reset();
			this->is_avaliable = true;
		}
};

int main()
{
	Space table[7][7];

	

	return 0;
}
