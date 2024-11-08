#pragma once
#include "Scene.h"
#include "ManagerScene.h"
#include "MainMenuScene.h"

class PauseScene : public Scene
{
public:
	PauseScene(ManagerScene& managerScene);
	void draw(sf::RenderWindow& window) override;  // Метод для отрисовки элементов
	//void update(sf::RenderWindow& window) override;
	void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
private:	
	ManagerScene& managerScene;
	sf::Font font;
	sf::Text pause;
	sf::Text resumeButton;
	sf::Text menuButton;
	bool resumeSelect = false;
	bool menuSelect = false;
};

