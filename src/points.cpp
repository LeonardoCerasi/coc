#include "points.h"

#include <cstddef>

#include "player.h"

#define ADD_STAR 2
#define MULT_STAR 2

int star_multiplier(int points, int stars)
{
	int mult{points};

	for (; stars > 0; stars--) { mult = mult * MULT_STAR + ADD_STAR; }

	return mult;
}

void compare(Player &player, std::vector<std::string> past_bonus)
{
	for (std::string name : past_bonus)
	{
		if (player.get_name() == name) { player.set_points(player.get_points() / 2); }
	}
}

void base_points(std::vector<Player> &players)
{
	for (size_t i{0}; i < players.size(); i++)
	{
		players.at(i).set_points(1);
	}
}

void star_points(std::vector<Player> &players)
{
	for (size_t i{0}; i < players.size(); i++)
	{
		players.at(i).set_points(star_multiplier(players.at(i).get_points(), players.at(i).get_stars()));
	}
}

void bonus_points(std::vector<Player> &players, std::vector<std::string> past_bonus_1, std::vector<std::string> past_bonus_2)
{
	for (size_t i{0}; i < players.size(); i++)
	{
		compare(players.at(i), past_bonus_1);
		compare(players.at(i), past_bonus_2);
	}
}
