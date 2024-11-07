#include <SFML/Graphics.hpp>
//#include <D:\Dima\Solutions\FirstEngine\Enemy.h>
//#include <D:\Dima\Solutions\FirstEngine\Player.h>
#include <D:\Dima\Solutions\FirstEngine\ManagerScene.h>
#include <D:\Dima\Solutions\FirstEngine\MainMenuScene.h>
#include <D:\Dima\Solutions\FirstEngine\AimScene.h>
#include <Windows.h>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1000, 750), "The invasion of balloons");
    ManagerScene managerScene;
    managerScene.setScene(new MainMenuScene(managerScene));


    while (window.isOpen())
    {
        sf::Event event;
        sf::Event myevent;
        while (window.pollEvent(event))
        {
            managerScene.handleEvent(event, window);
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
        managerScene.update(window);
        window.clear();
        managerScene.draw(window);
        window.display();
    };
}
