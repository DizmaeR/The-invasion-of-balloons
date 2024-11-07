#pragma once
#include "Scene.h"
class ManagerScene
{
private:
	Scene* currentScene;

public:
	ManagerScene();
	~ManagerScene();
	void setScene(Scene* newScene);
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void handleEvent(sf::Event& event, sf::RenderWindow& window);
};

