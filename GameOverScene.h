#pragma once
#include "Scene.h"
#include "ManagerScene.h"
#include "MainMenuScene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(ManagerScene& managerScene);
	void draw(sf::RenderWindow& window) override;  // Метод для отрисовки элементов
	//void update(sf::RenderWindow& window) override;
	void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
private:
	ManagerScene& managerScene;
	sf::Font font;
	sf::Text gameOver;
	sf::Text resumeButton;
	sf::Text saveButton;
	sf::Text menuButton;
	/*std::vector<bool> selects{saveSelect, resumeSelect, menuSelect};
	std::vector<sf::Text> buttons{saveButton, resumeButton, menuButton};
	int count = 0;*/
	bool resumeSelect = false;
	bool saveSelect = true;
	bool menuSelect = false;
};

