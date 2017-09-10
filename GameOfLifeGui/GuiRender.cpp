#include "GuiRender.h"
#include <cstddef>
#include <iostream>



void GuiRender::render(int ms)
{

    time += ms;

    if (time > drawDelay)
    {
#ifdef _DEBUG
        std::cout << ms << std::endl;
#endif
        time = 0;
        game.playOne();

    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    camera.look();

    game.render();

    glFlush();
}

GuiRender::GuiRender(Camera &camera, GameRender & game, int delay)
    : game(game), time(0), camera(camera), drawDelay(delay)
{
    
}


GuiRender::~GuiRender()
{
    GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glDepthMask(GL_TRUE);
    glShadeModel(GL_SMOOTH);



}
