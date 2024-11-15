#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "points.h"

#define N_TOP 10

int main()
{
	// retrieve data

	// select date
	int year{}, month{};
	std::cout << "Year (0-99): 20";
	std::cin >> year;
	std::cout << "\nMonth (1-12): ";
	std::cin >> month;
	std::cout << std::endl;

	// present league
	std::vector<Player> players{};
	try { players = player_list("leagues/" + std::to_string(year) +  "-" + std::to_string(month) + "/top.in", N_TOP); }
	catch (const std::exception &e)
	{
		std::cerr << "Error while parsing league data: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// past bonuses
	std::vector<std::string> past_bonus_1{};
	std::vector<std::string> past_bonus_2{};
	
	int month_1{1 + ((month - 1) -1 + 12) % 12};
	int year_1{year};
	if (month_1 > month) { year_1--; }
	int month_2{1 + ((month - 1) -2 + 12) % 12};
	int year_2{year};
	if (month_2 > month) { year_2--; }

	try
	{
		past_bonus_1 = bonus_list("leagues/" + std::to_string(year_1) +  "-" + std::to_string(month_1) + "/bonus.out");
		past_bonus_2 = bonus_list("leagues/" + std::to_string(year_2) +  "-" + std::to_string(month_2) + "/bonus.out");
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error while parsing past bonuses: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// calculate points
	
	base_points(players);
	star_points(players);
	bonus_points(players, past_bonus_1, past_bonus_2);

	// log out

	std::cout << "============================================================" << std::endl;

	// log bonuses from past two months
	std::cout << "\nIn the last two months, the following players received the war league bonus:\n" << std::endl;
	for (std::string p : past_bonus_1) { std::cout << p << std::endl; }
	std::cout << std::endl;
	for (std::string p : past_bonus_2) { std::cout << p << std::endl; }

	std::cout << "============================================================" << std::endl;

	// log current players
	std::cout << "\nTop " << N_TOP << " players of this month:\n" << std::endl;
	for (Player p : players)
	{
		p.print();
		std::cout << std::endl;
	}

	// distribute bonuses
	std::vector<Player> player_bonus{bonus(players, 6)};
	
	// log players with bonuses
	std::cout << "============================================================" << std::endl;

	std::cout << "\nBonuses of this month:\n" << std::endl;
	for (Player p : player_bonus) { std::cout << p.get_name() << std::endl; }

	return EXIT_SUCCESS;
}
