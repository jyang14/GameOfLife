#include "EventHandler.h"
#include <iostream>

EventHandler::EventHandler(sf::RenderWindow &w, Camera &camera, GameRender &game) :
    lastX(-1), lastY(-1), window(w), camera(camera), printDelay(0),randDelay(0), game(game)
{
    position = sf::Mouse::getPosition(window);
}

EventHandler::~EventHandler()
{
}

void EventHandler::tick(int ms)
{
    printDelay += ms;
    randDelay += ms;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        camera.forward(ms);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        camera.left(ms);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        camera.backwards(ms);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        camera.right(ms);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        camera.down(ms);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        camera.up(ms);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        position = sf::Mouse::getPosition(window) - position;
        camera.angle(position.x, position.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && printDelay > 300
        )
    {
        camera.printData();
        printDelay = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && randDelay > 300
        )
    {
        game.randomState();
        randDelay = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();



    position = sf::Mouse::getPosition();
}