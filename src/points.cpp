#include "points.h"

#include <cmath>
#include <cstddef>
#include <vector>
#include <random>
#include <algorithm>

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
//		if (player.get_name() == name) { player.set_points(player.get_points() / 2); }
	}
}

void base_points(std::vector<Player> &players)
{
	for (size_t i{0}; i < players.size(); i++)
	{
		players.at(i).set_points(10);
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

std::vector<Player> bonus(std::vector<Player> players, int n_bonuses)
{
	std::vector<Player> players_bonus{};
	std::vector<Player> support;

	for (size_t i{0}; i < players.size(); i++)
	{
		for (int j{0}; j < players.at(i).get_points(); j++)
		{
			support.push_back(players.at(i));
		}
	}

	// random number generator
	std::random_device rd{};
	std::mt19937 gen{rd()};
	std::uniform_int_distribution<> rnd(0, support.size() - 1);

	// shuffle players
	std::shuffle(support.begin(), support.end(), gen);

	// select bonuses
	int index{};
	for (int i{0}; i < n_bonuses; i++)
	{
		index = std::round(rnd(gen));

		bool not_already_in{true};
		for (size_t j{0}; j < players_bonus.size(); j++)
		{
			if (players_bonus.at(j).get_name() == support.at(index).get_name()) { not_already_in = false; break; }
		}

		if (not_already_in) { players_bonus.push_back(support.at(index)); }
		else { i--; }
	}

	return players_bonus;
}
