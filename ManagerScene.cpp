#include "ManagerScene.h"

ManagerScene::ManagerScene() : currentScene(nullptr)
{

}

void ManagerScene::setScene(Scene* newScene)
{
	if (currentScene)
		delete currentScene;
	currentScene = newScene;
}
void ManagerScene::draw(sf::RenderWindow& window)
{
	if (currentScene)
		currentScene->draw(window);
}
void ManagerScene::update(sf::RenderWindow& window)
{
	if (currentScene)
		currentScene->update(window);
}
void ManagerScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	if (currentScene)
		currentScene->handleEvent(event,window);
}
ManagerScene::~ManagerScene()
{
	delete currentScene;
}