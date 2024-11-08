#include "AimScene.h"
#include "PauseScene.h"
#include "MainMenuScene.h"
#include <vector>
#include <cmath>                                        //Ограничивать количество уменьшающихся хп 
                                                        //Проверить на мыши
                                                        //Разобраться с паузой
//#include <iostream>
#include <string>

AimScene::AimScene(ManagerScene& managerScene): managerScene(managerScene)
{
    if (managerScene.savedEnemies.empty())
    {
        for (int i = 0; i < 6; i++)                                             //Загрузка и сохранение врагов
            enemies.push_back(Enemy::create_enemy());
    }
    else
    {
        for (Enemy* n : managerScene.savedEnemies)
            enemies.push_back(n);
        player.take_points(managerScene.savedPoints);
        player.take_health(managerScene.savedHp);
    }
    
    font.loadFromFile("D:/Dima/PixelFont.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    // text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    health.setFont(font);
    health.setCharacterSize(20);
    health.setPosition(300, 10);
    health.setString("HEALTH:");

    /*hpPoint1.setRadius(10.0);
    hpPoint1.setOrigin(10.0, 10.0);
    hpPoint2.setRadius(10.0);
    hpPoint2.setOrigin(10.0, 10.0);
    hpPoint3.setRadius(10.0);
    hpPoint3.setOrigin(10.0, 10.0);*/
    for (int i = 0; i < player.get_health(); i++)
    {
        hpPoint.setRadius(10.0);
        hpPoint.setOrigin(10.0, 10.0);
        hpPoint.setPosition(health.getPosition().x + 150.0 + 20.0 * i, health.getPosition().y + 10.0);
        hpPoints.push_back(hpPoint);
    }
}

void AimScene::draw(sf::RenderWindow& window)
{
    window.draw(text);
    for (auto n : enemies)                              //Отрисовка сердец
        n->draw(window);
    window.draw(health);
    for (int i = 0; i < player.get_health(); i++)
        window.draw(hpPoints[i]);
}
void AimScene::update(sf::RenderWindow& window)
{
    if (player.get_health() == 0)
        managerScene.setScene(TypeScene::GameOverScene);
}

void AimScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    
    // Обработка события нажатия мыши
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if(!oneKlick)
        { 
            gameStarted = true;
            sf::Vector2i mouseWorldPos = sf::Mouse::getPosition(window);
            sf::Vector2f mousePos = window.mapPixelToCoords(mouseWorldPos);
            Hit = false;
            for (int i = 0; i < enemies.size(); i++)
            {
                float dx = mousePos.x - enemies[i]->get_pos().x;
                float dy = mousePos.y - enemies[i]->get_pos().y;
                float distance = std::sqrt(dx * dx + dy * dy);

                if (distance <= enemies[i]->get_radius())
                {
                    Hit = true;
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
                    break;
                }
            }
            if (!Hit && gameStarted)
            {
                player.missed_click();
            }
            oneKlick = true;
        }
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        oneKlick = false;
    }

    text.setString("YOUR POINTS:\n" + std::to_string(player.get_points()));
    
    if(event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Q)
        {
            for (Enemy* enemy : enemies)
                delete enemy;

            enemies.clear();
            managerScene.setScene(TypeScene::MainMenuScene);
        }
        if (event.key.code == sf::Keyboard::P)
        {
           // isPaused == true;
            managerScene.saveData(enemies, player);                //Переход на паузу
            managerScene.setScene(TypeScene::PauseScene);
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