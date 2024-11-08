#include <SFML/Graphics.hpp>
//#include <D:\Dima\Solutions\FirstEngine\Enemy.h>
//#include <D:\Dima\Solutions\FirstEngine\Player.h>
#include <D:\Dima\Solutions\FirstEngine\ManagerScene.h>
#include <D:\Dima\Solutions\FirstEngine\MainMenuScene.h>
//#include <D:\Dima\Solutions\FirstEngine\AimScene.h>
#include <Windows.h>



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    sf::RenderWindow window(sf::VideoMode(1120, 630), "The invasion of balloons");
    ManagerScene managerScene;
    managerScene.setScene(TypeScene::MainMenuScene);


    while (window.isOpen())
    {
        sf::Event event;
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
