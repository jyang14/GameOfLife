#include "event_hander3.h"

event_hander3::event_hander3(sf::RenderWindow &w, camera3 &camera) :
    window_(w), camera_(camera), print_delay_(0), random_delay_(0)
{
    position_ = sf::Mouse::getPosition(window_);
}

void event_hander3::tick(const int ms, const bool has_focus)
{
    print_delay_ += ms;
    random_delay_ += ms;

    if (has_focus)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            camera_.forward(ms);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            camera_.left(ms);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            camera_.backwards(ms);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            camera_.right(ms);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            camera_.down(ms);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            camera_.up(ms);
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            position_ = sf::Mouse::getPosition(window_) - position_;
            camera_.angle(position_.x, position_.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && print_delay_ > 300)
        {
            camera_.print_data();
            print_delay_ = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window_.close();
    }


    position_ = sf::Mouse::getPosition();
}