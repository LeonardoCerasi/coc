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
void Player::set_points(int m_points)
{
	if (m_points > 1) { points = m_points; }
	else { points = 1; }
}

void Player::print()
{
	std::cout << "Player: " << name << std::endl;
	std::cout << " - points: " << points << std::endl;
}

std::vector<Player> player_list(const std::string path, int n_players)
{
	std::ifstream input(path);
	if (!input) { throw std::invalid_argument("Input file " + path + " not found."); }

	std::vector<Player> players{};
	std::string p_name{}, p_stars{};

	std::string line{};
	for (int i = 0; i < n_players; i++)
	{
		std::getline(input, line);
		std::stringstream ss(line);

		ss >> p_name;
		ss >> p_stars;

		players.push_back(Player(p_name, std::stoi(p_stars)));
	}

	input.close();
	return players;
}

std::vector<std::string> bonus_list(const std::string path)
{
	std::ifstream input(path);
	if (!input) { throw std::invalid_argument("Input file " + path + " not found."); }

	std::vector<std::string> bonuses{};
	std::string b_name{};

	while(input >> b_name) { bonuses.push_back(b_name); }

	input.close();
	return bonuses;
}
