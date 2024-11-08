#include "PauseScene.h"
PauseScene::PauseScene(ManagerScene& managerScene) : managerScene(managerScene)
{
	font.loadFromFile("D:/Dima/PixelFont.ttf");

	pause.setFont(font);
	pause.setCharacterSize(40);
	pause.setPosition(120, 140);
	pause.setString("PAUSE");

	resumeButton.setFont(font);
	resumeButton.setCharacterSize(25);
	resumeButton.setPosition(450, 400);
	resumeButton.setString("RESUME");

	menuButton.setFont(font);
	menuButton.setCharacterSize(25);
	menuButton.setPosition(450, 470);
	menuButton.setString("MENU");
}
void PauseScene::draw(sf::RenderWindow& window)
{
	window.draw(pause);
	window.draw(resumeButton);
	window.draw(menuButton);
}
#include <iostream>

void PauseScene::update(sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mouseWindowPos = window.mapPixelToCoords(mousePos);

    if (resumeButton.getGlobalBounds().contains(mouseWindowPos))
    {
        resumeButton.setFillColor(sf::Color::Red);
        resumeSelect = true;
        menuButton.setFillColor(sf::Color::White);
        menuSelect = false;
    }
    else if (menuButton.getGlobalBounds().contains(mouseWindowPos))
    {
        menuButton.setFillColor(sf::Color::Red);
        menuSelect = true;
        resumeButton.setFillColor(sf::Color::White);
        resumeSelect = false;
    }
}

void PauseScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::P)
        {
            managerScene.returnScene();
        }

        if (event.key.code == sf::Keyboard::M)
        {
            managerScene.setScene(TypeScene::MainMenuScene);
        }

		if (event.key.code == sf::Keyboard::Up)
		{
			std::cout << "Up" << std::endl;
			resumeSelect = true;
			menuSelect = false;
			resumeButton.setFillColor(sf::Color::Red);
			menuButton.setFillColor(sf::Color::White);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			std::cout << "Down" << std::endl;
			resumeSelect = false;
			menuSelect = true;
			menuButton.setFillColor(sf::Color::Red);
			resumeButton.setFillColor(sf::Color::White);
		}
	}
	else if (event.key.code == sf::Keyboard::Enter)
	{
		if (resumeSelect)
		{
			managerScene.setScene(TypeScene::AimScene);
		}
		else if (menuSelect)
			managerScene.setScene(TypeScene::MainMenuScene);
	}
    

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {

        if (resumeSelect)
        {
            managerScene.returnScene();
            return;
        }
        if (menuSelect)
        {
            managerScene.setScene(TypeScene::MainMenuScene);
        }
    }

}
