#pragma once
#include "Game.h"
#include "Cube.h"
#include "CubeManager.h"

class GameRender : public Game
{
    CubeManager manager;

    void drawBoundingBox();

public:
    void render();

    GameRender(int width, int height, int depth, int mod, int liveMin, int liveMax, int birthMin, int birthMax);
    ~GameRender();
};

