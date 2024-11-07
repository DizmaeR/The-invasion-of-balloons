#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(int hp, int point, float radius);

	int get_health();
	bool is_alive() const;
	void take_damage(int damage);
	int get_point();
	float get_radius();
	static Enemy* create_enemy(int hp = 1, int point = 5, float radius = 50.0);
	static Enemy* create_havy_enemy(int hp = 3, int point = 20, float radius = 100.0);
	sf::Vector2f get_pos();
	void draw(sf::RenderWindow& window);

	~Enemy();

private:
	sf::Vector2f position;
	int health;
	int point;
	sf::CircleShape shape;
	float radius;
};

