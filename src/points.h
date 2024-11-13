#pragma once

#include <string>
#include <vector>

#include "player.h"

int star_multiplier(int, int);

void compare(Player &, std::vector<std::string>);

void base_points(std::vector<Player> &);

void star_points(std::vector<Player> &);

void bonus_points(std::vector<Player> &, std::vector<std::string>, std::vector<std::string>);
