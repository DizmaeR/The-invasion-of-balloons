#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
public:
	Player();
	int get_damage();
	int get_points();
	void take_points( int enemy_points);
	//int get_count_enemy();
private:
	int damage = 1;
	int points = 0;
	//int count_enemy = 0;
};

