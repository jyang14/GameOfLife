#include <GL/glew.h>
#include "gui.h"
#include "EventHandler.h"
#include "GuiRender.h"
#include <SFML/Graphics.hpp>
#include <iostream>


gui::gui(int width, int height, int depth, 
    const char * state, int mod, 
    int liveMin, int liveMax, 
    int birthMin, int birthMax,
    int drawDelay, const char * title, const char * texturePath) 
    : window_(sf::RenderWindow(sf::VideoMode().getDesktopMode(), title,
        sf::Style::Fullscreen, 
        sf::ContextSettings(24, 8, 2, 3, 3)))
{
    window_.setVerticalSyncEnabled(true);
    GLenum err = glewInit();
    if (GLEW_OK == err)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(texturePath))
            return;

        // Attempt to generate a mipmap for our cube texture
        // We don't check the return value here since
        // mipmapping is purely optional in this example
        texture.generateMipmap();

        window_.setActive(true);

        GameRender game(width, height, depth, mod, liveMin, liveMax, birthMin, birthMax);
        int error = game.setState(state);
        if (error)
        {
            std::cout << "Error " << error << std::endl;
            game.randomState();
        }
        Camera camera;

        EventHandler eventHandler(window_, camera, game);

        GuiRender render(camera, game, drawDelay);

        // Bind the texture
        glEnable(GL_TEXTURE_2D);
        sf::Texture::bind(&texture);

        sf::Clock clock;
        clock.restart();
        int ms;
        while (window_.isOpen())
        {
            sf::Event event;
            while (window_.pollEvent(event));

            ms = clock.getElapsedTime().asMilliseconds();
            clock.restart();
            eventHandler.tick(ms);
            render.render(ms);

            window_.display();
            sf::sleep(sf::milliseconds(5));
        }
    }
    else
    {
        std::cout << err << std::endl;
    }
}

gui::~gui()
{
}

gui::builder::builder()
{
    width_ = 3;
    height_ = 3;
    depth_ = 3;

    state_ = "r";
    title_ = "Conway's Game of Life";
    texture_path_ = "C:/Users/jinch/Desktop/Untitled.png";

    live_min_ = 2;
    live_max_ = 3;

    birth_min_ = 3;
    birth_max_ = 3;

    draw_delay_ = 100;

    modular_board_ = 0;

}

void gui::builder::init_gui()
{
    gui gui(width_, height_, depth_, state_, modular_board_, live_min_, live_max_, birth_min_, birth_max_, draw_delay_, title_, texture_path_);
}

void gui::builder::set_dimensions(int newWidth, int newHeight, int newDepth)
{
    width_ = newWidth;
    height_ = newHeight;
    depth_ = newDepth;
}

void gui::builder::set_inital_state(const char * newState)
{
    state_ = newState;
}

void gui::builder::set_title(const char * newTitle)
{
    title_ = newTitle;
}

void gui::builder::set_live_rule(int newLiveMin, int newLiveMax)
{
    live_min_ = newLiveMin;
    live_max_ = newLiveMax;
}

void gui::builder::set_birth_rule(int newBirthMin, int newBirthMax)
{
    birth_min_ = newBirthMin;
    birth_max_ = newBirthMax;
}

void gui::builder::set_draw_delay(int newDrawDelay)
{
    draw_delay_ = newDrawDelay;
}

void gui::builder::set_modular_board(int newMod)
{
    modular_board_ = newMod;
}

void gui::builder::set_texture(const char * newTexturePath)
{
    texture_path_ = newTexturePath;
}
