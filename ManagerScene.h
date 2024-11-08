#pragma once
#include "Scene.h"
#include <D:\Dima\Solutions\FirstEngine\Enemy.h>
#include <D:\Dima\Solutions\FirstEngine\Player.h>
#include "TypeScene.h"

//class Scene;           // Предварительное объявление базового класса
//class AimScene;        // Предварительное объявление нужных сцен
//class MainMenuScene;
//class PauseScene;

class ManagerScene
{
private:
	Scene* currentScene;
	Scene* savedScene;
public:

	TypeScene currentSceneType;
	TypeScene savedSceneType;

	ManagerScene();
	~ManagerScene();
	void setScene(TypeScene typeScene);
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void handleEvent(sf::Event& event, sf::RenderWindow& window);
	
	void saveData(std::vector<Enemy*> enemy,const Player& player);
	void returnScene();
	int savedPoints = 0;
	int savedHp = 0;
	std::vector<Enemy*> savedEnemies;

	

};

