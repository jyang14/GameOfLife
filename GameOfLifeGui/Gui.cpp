#include <GL/glew.h>
#include "Gui.h"
#include "EventHandler.h"
#include "GuiRender.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Gui::Gui(int width, int height, int depth, 
    const char * state, int mod, 
    int liveMin, int liveMax, 
    int birthMin, int birthMax,
    int drawDelay, const char * title, const char * texturePath) 
    : window(sf::RenderWindow(sf::VideoMode().getDesktopMode(), title,
        sf::Style::Fullscreen, 
        sf::ContextSettings(24, 8, 2, 3, 3)))
{
    window.setVerticalSyncEnabled(true);
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

        window.setActive(true);

        GameRender game(width, height, depth, mod, liveMin, liveMax, birthMin, birthMax);
        int error = game.setState(state);
        if (error)
        {
            std::cout << "Error " << error << std::endl;
            game.randomState();
        }
        Camera camera;

        EventHandler eventHandler(window, camera, game);

        GuiRender render(camera, game, drawDelay);

        // Bind the texture
        glEnable(GL_TEXTURE_2D);
        sf::Texture::bind(&texture);

        sf::Clock clock;
        clock.restart();
        int ms;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event));

            ms = clock.getElapsedTime().asMilliseconds();
            clock.restart();
            eventHandler.tick(ms);
            render.render(ms);

            window.display();
            sf::sleep(sf::milliseconds(5));
        }
    }
    else
    {
        std::cout << err << std::endl;
    }
}

Gui::~Gui()
{
}

Gui::Builder::Builder()
{
    width = 3;
    height = 3;
    depth = 3;

    state = "r";
    title = "Conway's Game of Life";
    texturePath = "C:/Users/jinch/Desktop/Untitled.png";

    liveMin = 2;
    liveMax = 3;

    birthMin = 3;
    birthMax = 3;

    drawDelay = 100;

    mod = 0;

}

void Gui::Builder::initGui()
{
    Gui gui(width, height, depth, state, mod, liveMin, liveMax, birthMin, birthMax, drawDelay, title, texturePath);
}

void Gui::Builder::setDimensions(int newWidth, int newHeight, int newDepth)
{
    width = newWidth;
    height = newHeight;
    depth = newDepth;
}

void Gui::Builder::setInitalState(const char * newState)
{
    state = newState;
}

void Gui::Builder::setTitle(const char * newTitle)
{
    title = newTitle;
}

void Gui::Builder::setLiveRule(int newLiveMin, int newLiveMax)
{
    liveMin = newLiveMin;
    liveMax = newLiveMax;
}

void Gui::Builder::setBirthRule(int newBirthMin, int newBirthMax)
{
    birthMin = newBirthMin;
    birthMax = newBirthMax;
}

void Gui::Builder::setDrawDelay(int newDrawDelay)
{
    drawDelay = newDrawDelay;
}

void Gui::Builder::setModularBoard(int newMod)
{
    mod = newMod;
}

void Gui::Builder::setTexture(const char * newTexturePath)
{
    texturePath = newTexturePath;
}
