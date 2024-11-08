#include "ManagerScene.h"
#include "AimScene.h"
#include "MainMenuScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"

ManagerScene::ManagerScene() : currentScene(nullptr), savedScene(nullptr)
{

}

void ManagerScene::saveData(std::vector <Enemy*> enemy, const Player& player)
{
	for (Enemy* n : enemy)
		savedEnemies.push_back(n);
	savedPoints = player.get_points();
	savedHp = player.get_health();
	savedScene = currentScene;
	savedSceneType = currentSceneType;
	currentScene = nullptr;
}
void ManagerScene::returnScene()
{
	if (savedScene)
	{
		delete currentScene;
		currentScene = savedScene;
		currentSceneType = savedSceneType;
		savedScene = nullptr;
	}
}
void ManagerScene::setScene(TypeScene typeScene) //Scene* newScene
{
	if (currentScene)
	{
		//savedSceneType = currentSceneType;
		delete currentScene;
		savedScene = nullptr;
	}
	currentSceneType = typeScene;

	switch (typeScene) {
	case TypeScene::MainMenuScene:
			currentScene = new MainMenuScene(*this);
		break;
	case TypeScene::AimScene:
			currentScene = new AimScene(*this);
		break;
	case TypeScene::PauseScene:
			currentScene = new PauseScene(*this);
		break;
	case TypeScene::GameOverScene:
		currentScene = new GameOverScene(*this);
		break;

	}
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
	//delete savedScene;
}