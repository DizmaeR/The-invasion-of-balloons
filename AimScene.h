#pragma once
#include "Scene.h"
#include <D:\Dima\Solutions\FirstEngine\Enemy.h>
#include <D:\Dima\Solutions\FirstEngine\Player.h>
#include "ManagerScene.h"
class AimScene : public Scene
{
public:
	AimScene(ManagerScene& managerScene);
	void draw(sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
	void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
	
private:
	bool Hit = false;
	bool gameStarted = false;
	bool oneKlick = false;
	std::vector<sf::Vector2f> positionHp;
	std::vector<sf::CircleShape> hpPoints;
	ManagerScene& managerScene;
	std::vector<Enemy*> enemies; 
	Player player;
	sf::Text text;
	sf::Font font;
	sf::Text health;
	sf::CircleShape hpPoint;
	//sf::CircleShape hpPoint2;
	//sf::CircleShape hpPoint3;
	//bool isPaused;
};

