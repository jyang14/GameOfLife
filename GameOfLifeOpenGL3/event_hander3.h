#pragma once 
#include "camera3.h"
#include <SFML/Graphics.hpp>

class event_hander3
{
private:
    sf::RenderWindow &window_;
    camera3 &camera_;

    sf::Vector2i position_;
    int print_delay_;
    int random_delay_;

public:
    event_hander3(sf::RenderWindow &w, camera3 &camera);
    void tick(int ms, bool has_focus);
};
