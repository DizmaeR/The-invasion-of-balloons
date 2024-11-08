#include "GameOverScene.h"
GameOverScene::GameOverScene(ManagerScene& managerScene) : managerScene(managerScene)
{
	font.loadFromFile("D:/Dima/PixelFont.ttf");

	gameOver.setFont(font);
	gameOver.setCharacterSize(40);
	gameOver.setPosition(120, 140);
	gameOver.setString("Game Over");

	resumeButton.setFont(font);
	resumeButton.setCharacterSize(25);
	resumeButton.setPosition(450, 200);
	resumeButton.setString("RESUME");

	saveButton.setFont(font);
	saveButton.setCharacterSize(25);
	saveButton.setPosition(450, 300);
	saveButton.setString("Save");

	menuButton.setFont(font);
	menuButton.setCharacterSize(25);
	menuButton.setPosition(450, 400);
	menuButton.setString("MENU");
}
void GameOverScene::draw(sf::RenderWindow& window)
{
	window.draw(gameOver);
	window.draw(resumeButton);
	window.draw(menuButton);
	window.draw(saveButton);
}
#include <iostream>

void GameOverScene::update(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mouseWindowPos = window.mapPixelToCoords(mousePos);

	if (resumeButton.getGlobalBounds().contains(mouseWindowPos))
	{
		resumeButton.setFillColor(sf::Color::Red);
		resumeSelect = true;
		menuButton.setFillColor(sf::Color::White);
		menuSelect = false;
		saveButton.setFillColor(sf::Color::White);
		saveSelect = false;
	}
	else if (menuButton.getGlobalBounds().contains(mouseWindowPos))
	{
		menuButton.setFillColor(sf::Color::Red);
		menuSelect = true;
		resumeButton.setFillColor(sf::Color::White);
		resumeSelect = false;
		saveButton.setFillColor(sf::Color::White);
		saveSelect = false;
	}
	else if (saveButton.getGlobalBounds().contains(mouseWindowPos))
	{
		menuButton.setFillColor(sf::Color::White);
		menuSelect = false;
		resumeButton.setFillColor(sf::Color::White);
		resumeSelect = false;
		saveButton.setFillColor(sf::Color::Red);
		saveSelect = true;
	}
}

void GameOverScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
	/*if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			buttons[select] = false;
			--select;
			buttons[select] = true;
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			buttons[select] = false;
			++select;
			buttons[select] = true;
		}
		resumeSelect = false;
		menuSelect = true;
		menuButton.setFillColor(sf::Color::Red);
		resumeButton.setFillColor(sf::Color::White);
	}*/
	if (event.key.code == sf::Keyboard::Enter)
	{
		if (resumeSelect)
		{
			managerScene.setScene(TypeScene::AimScene);
		}
		else if (menuSelect)
			managerScene.setScene(TypeScene::MainMenuScene);
		else if (saveSelect)
			managerScene.setScene(TypeScene::MainMenuScene);
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{

		if (resumeSelect)
		{
			managerScene.setScene(TypeScene::AimScene);
		}
		if (menuSelect)
		{
			managerScene.setScene(TypeScene::MainMenuScene);
		}
		else if (saveSelect)
			managerScene.setScene(TypeScene::MainMenuScene);
	}

}