#pragma once
#include <GL\glew.h>
#include "Camera.h"
#include "GameRender.h"

class GuiRender
{
    int time;
    int drawDelay;
    GameRender &game;
    Camera &camera;

public:
    void render(int ms);

    GuiRender(Camera &camera, GameRender &game, int delay);
    ~GuiRender();
};

