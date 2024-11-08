#pragma once
#include <SFML/Graphics.hpp>
class Scene
{
public:
	virtual ~Scene() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(sf::RenderWindow& window) = 0;
	virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
};

