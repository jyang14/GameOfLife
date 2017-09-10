#pragma once
#include <vector>

#include "Game.h"
#include "Cube.h"

class GameRender : public Game
{
    Cube** blocks;

    Cube * makeCube(int row, int column, int layer);

    void drawBoundingBox();

public:
    void render();

    GameRender(int width, int height, int depth, int mod, int liveMin, int liveMax, int birthMin, int birthMax);
    ~GameRender();
};

