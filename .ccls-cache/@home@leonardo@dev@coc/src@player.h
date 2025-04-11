#pragma once

#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
	std::string name;
	int stars;
	int points;

public:
	// builders
	Player() {}
	Player(std::string, int);

	// get
	std::string get_name();
	int get_stars();
	int get_points();

	// set
	void set_points(int);

	void print();
};

std::vector<Player> player_list(const std::string, int);
std::vector<std::string> bonus_list(const std::string);
