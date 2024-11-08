#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
public:
	Player();
	int get_damage() const;
	int get_points() const;
	void take_points(int enemy_points);
	void take_health(int savedHp);
	int get_health() const;
	void missed_click();
private:
	
	int damage = 1;
	int points = 0;
	int health = 4;
};

