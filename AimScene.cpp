#include "AimScene.h"
#include "MainMenuScene.h"
#include <vector>
#include <cmath>
//#include <iostream>
#include <string>

AimScene::AimScene(ManagerScene& managerScene): managerScene(managerScene)
{
    for (int i = 0; i < 6; i++)
        enemies.push_back(Enemy::create_enemy());
    font.loadFromFile("D:/Dima/PixelFont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    // text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
}

void AimScene::draw(sf::RenderWindow& window)
{
    window.draw(text);
    for (auto n : enemies)
        n->draw(window);
}
void AimScene::update(sf::RenderWindow& window)
{
  
}



void AimScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    
    // Обработка события нажатия мыши
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mouseWorldPos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos = window.mapPixelToCoords(mouseWorldPos);
        for (int i = 0; i < enemies.size(); i++)
        {
            float dx = mousePos.x - enemies[i]->get_pos().x;
            float dy = mousePos.y - enemies[i]->get_pos().y;
            float distance = std::sqrt(dx * dx + dy * dy);

            if (distance <= enemies[i]->get_radius())
            {
                enemies[i]->take_damage(player.get_damage());

                if (!enemies[i]->is_alive())
                {
                    player.take_points(enemies[i]->get_point());
                    delete enemies[i];
                    enemies.erase(enemies.begin() + i);

                    if (player.get_points() % 50 == 0 && player.get_points() != 0)
                        enemies.push_back(Enemy::create_havy_enemy());
                    else
                        enemies.push_back(Enemy::create_enemy());
                }
            }
        }
    }
    text.setString("YOUR POINTS:\n" + std::to_string(player.get_points()));

    if(event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Q)
        {
            for (Enemy* enemy : enemies)
                delete enemy;

            enemies.clear();
            managerScene.setScene(new MainMenuScene(managerScene));
        }
    }
    if (event.type == sf::Event::Closed)
    {
        window.close();
        for (Enemy* enemy : enemies)
            delete enemy;
        enemies.clear();
    }
}