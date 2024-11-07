#pragma once
#include "Scene.h"
#include "ManagerScene.h"
class MainMenuScene : public Scene
{
public:
    MainMenuScene(ManagerScene& managerScene);
    void draw(sf::RenderWindow& window) override;  // Метод для отрисовки элементов
    void update(sf::RenderWindow& window) override;
    void handleEvent( sf::Event& event, sf::RenderWindow& window) override;

private:
    sf::CircleShape shapeName;
    ManagerScene& managerScene;
    sf::Font font;
    sf::Text name;
    sf::Text playButton;
    sf::Text exitButton;
    bool playSelection = false;
    bool exitSelection = false;
};

