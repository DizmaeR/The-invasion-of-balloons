#include "Enemy.h"
#include <random>

Enemy::Enemy(int hp, int point, float radius) : health(hp), point(point), radius(radius)
{	

	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	if (radius == 50.0)	
		shape.setFillColor(sf::Color::Red);

	if (radius == 100.0)
	{
		shape.setFillColor(sf::Color::Green);
	}
	//std::mt19937 generator(static_cast<unsigned>(std::time(nullptr)));
	std::random_device rd;
	std::default_random_engine rng(rd());
	std::uniform_real_distribution<float> randx(radius + 50.0, 1000.0 - radius);
	std::uniform_real_distribution<float> randy(radius + 50.0, 700.0 - radius);
	position.x = randx(rng);
	position.y = randy(rng);
	shape.setPosition(position);
}

Enemy::~Enemy() {}

Enemy* Enemy::create_enemy(int hp, int point, float radius)
{
	return new Enemy(hp, point, radius);
}

Enemy* Enemy::create_havy_enemy(int hp, int point, float radius)
{
	return new Enemy(3, 20, 100.0);
}

sf::Vector2f Enemy::get_pos()
{
	return position;
}
void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

int Enemy::get_health()
{
	return health;
}

void Enemy::take_damage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}
float Enemy::get_radius()
{
	return radius;
}
bool Enemy::is_alive() const
{
	return health > 0;
}
int Enemy::get_point()
{
	return point;
}
