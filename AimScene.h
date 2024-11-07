#pragma once
#include "Scene.h"
#include <D:\Dima\Solutions\FirstEngine\Enemy.h>
#include <D:\Dima\Solutions\FirstEngine\Player.h>
#include "ManagerScene.h"
class AimScene : public Scene
{
public:
	AimScene(ManagerScene& managerScene);
	void draw(sf::RenderWindow& window) override;  // Метод для отрисовки элементов
	void update(sf::RenderWindow& window) override;
	void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
private:
	ManagerScene& managerScene;
	std::vector<Enemy*> enemies; 
	Player player;
	sf::Text text;
	sf::Font font;
};

