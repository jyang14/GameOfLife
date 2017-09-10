#pragma once 
#include "Camera.h"
#include "GameRender.h"
#include <SFML/Graphics.hpp>

class EventHandler
{
private:
    sf::RenderWindow &window;
    Camera &camera;
    int lastX, lastY;

    sf::Vector2i position;
    int printDelay;
    int randDelay;

    GameRender &game;

public:
    EventHandler(sf::RenderWindow &w, Camera &camera, GameRender &game);
    virtual ~EventHandler();
    void tick(int ms);
};
