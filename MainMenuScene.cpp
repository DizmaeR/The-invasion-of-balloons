#include "MainMenuScene.h"
#include "AimScene.h"

MainMenuScene::MainMenuScene(ManagerScene& managerScene): managerScene(managerScene)
{
	font.loadFromFile("D:/Dima/PixelFont.ttf");
		
	name.setFont(font);
	name.setCharacterSize(40);
	name.setPosition(120, 140);
	name.setString("The Invisition of ballons");
		
	playButton.setFont(font);
	playButton.setCharacterSize(25);
	playButton.setPosition(450, 520);
	playButton.setString("PLAY");

	exitButton.setFont(font);
	exitButton.setCharacterSize(25);
	exitButton.setPosition(450, 600);
	exitButton.setString("EXIT");

	shapeName.setRadius(150);
	shapeName.setPosition(350, 30);
	shapeName.setFillColor(sf::Color::Red);

	managerScene.savedEnemies.clear();
}
void MainMenuScene::draw(sf::RenderWindow& window) // Отрисовка главного меню
{
	window.draw(shapeName);
	window.draw(name);
	window.draw(playButton);
	window.draw(exitButton);
}
void MainMenuScene::update(sf::RenderWindow& window) // Логика главного меню
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mouseWindowPos = window.mapPixelToCoords(mousePos);
	if (playButton.getGlobalBounds().contains(mouseWindowPos))
	{
		playButton.setFillColor(sf::Color::Red);
		playSelection = true;
		exitButton.setFillColor(sf::Color::White);
		exitSelection = false;
	}
	else if (exitButton.getGlobalBounds().contains(mouseWindowPos))
	{
		exitButton.setFillColor(sf::Color::Red);
		exitSelection = true;
		playButton.setFillColor(sf::Color::White);
		playSelection = false;
	}
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (playSelection)
		{
			managerScene.setScene(TypeScene::AimScene);
		}
		else if (exitSelection)
			window.close();
	}
}
void MainMenuScene::handleEvent( sf::Event& event, sf::RenderWindow& window) // Обработка событий для главного меню
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			std::cout << "Up" << std::endl;
			playSelection = true;
			exitSelection = false;
			playButton.setFillColor(sf::Color::Red);
			exitButton.setFillColor(sf::Color::White);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			std::cout << "Down" << std::endl;
			playSelection = false;
			exitSelection = true;
			exitButton.setFillColor(sf::Color::Red);
			playButton.setFillColor(sf::Color::White);
		}
	}
	else if (event.key.code == sf::Keyboard::Enter)
	{
		if (playSelection)
		{
			managerScene.setScene(TypeScene::AimScene);
		}
		else if (exitSelection)
			window.close();
	}
}