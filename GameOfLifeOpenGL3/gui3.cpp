#include "gui3.h"

#include "camera3.h"

#include <GL/glew.h>
#include <SFML/Graphics.hpp>

#include "event_hander3.h"
#include "game_render3.h"


int gui3::show(Game &game) const
{

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), title_,
        sf::Style::Fullscreen,
        sf::ContextSettings(24, 8, 2, 3, 3));

    window.setVerticalSyncEnabled(true);
    const auto err = glewInit();
    if (GLEW_OK == err)
    {
        if (!window.setActive(true))
            return -1;

        camera3 camera;

        event_hander3 event_handler(window, camera);

        game_render3 game_renderer(game, camera, draw_delay_);
        game_renderer.init(texture_path_, "cube_shader.vert", "cube_shader.frag");

        sf::Clock clock;
        clock.restart();

        auto focus = true;
        while (window.isOpen())
        {
            sf::Event event {};
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::GainedFocus:
                    focus = true;
                    break;
                case sf::Event::LostFocus:
                    focus = false;
                    break;
                default:;
                }
            }

            const auto ms = clock.getElapsedTime().asMilliseconds();
            clock.restart();
            event_handler.tick(ms, focus);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_DEPTH_TEST);

            game_renderer.render(ms);


            window.display();
            sf::sleep(sf::milliseconds(5));
        }

    }
    else
        return err;

    return 0;
}

gui3::gui3()
{
    width_ = 3;
    height_ = 3;
    depth_ = 3;

    state_ = "r";
    title_ = "Conway's Game of Life";
    texture_path_ = "mams.png";

    live_min_ = 2;
    live_max_ = 3;

    birth_min_ = 3;
    birth_max_ = 3;

    draw_delay_ = 100;

    modular_board_ = 0;

}

int gui3::show_gui() const
{
    Game game(width_, height_, depth_, modular_board_, live_min_, live_max_, birth_min_, birth_max_);

    const auto error = game.setState(state_);

    if(error)
        game.randomState();

    return show(game);

}
void gui3::set_modular_board(const int new_mod)
{
    modular_board_ = new_mod;
}

void gui3::set_texture(const char* new_texture_path)
{
    texture_path_ = new_texture_path;
}

void gui3::set_dimensions(const int new_width, const int new_height, const int new_depth)
{
    width_ = new_width;
    height_ = new_height;
    depth_ = new_depth;
}

void gui3::set_inital_state(const char * new_state)
{
    state_ = new_state;
}

void gui3::set_title(const char * new_title)
{
    title_ = new_title;
}

void gui3::set_live_rule(const int new_live_min, const int new_live_max)
{
    live_min_ = new_live_min;
    live_max_ = new_live_max;
}

void gui3::set_birth_rule(const int new_birth_min, const int new_birth_max)
{
    birth_min_ = new_birth_min;
    birth_max_ = new_birth_max;
}

void gui3::set_draw_delay(const int new_draw_delay)
{
    draw_delay_ = new_draw_delay;
}