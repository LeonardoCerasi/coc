#include "player.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

// builders
Player::Player(std::string m_name, int m_stars) : name{m_name}, stars{m_stars}, points{} {}

// get
std::string Player::get_name() { return name; }
int Player::get_stars() { return stars; }
int Player::get_points() { return points; }

// set
void Player::set_points(int m_points) { points = m_points; }

void Player::print()
{
	std::cout << "Player: " << name << std::endl;
	std::cout << "points: " << points << std::endl;
}

std::vector<Player> Player::player_list(const std::string path, int n_players)
{
	std::ifstream input(path);
	if (!input) { throw std::invalid_argument("Input file " + path + " not found."); }

	std::vector<Player> players(n_players);
	std::string p_name{}, p_stars{};

	std::string line{};
	for (int i = 0; i < n_players; i++)
	{
		std::getline(input, line);
		std::stringstream ss(line);

		std::getline(ss, p_name, ',');
		std::getline(ss, p_stars, ',');

		players.push_back(Player(p_name, std::stoi(p_stars)));
	}

	input.close();
	return players;
}
