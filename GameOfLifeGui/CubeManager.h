#pragma once

#include "GL/glew.h"
#include "Cube.h"

class CubeManager
{
    static const float textures[12 * 3 * 2];

    GLuint textureVBOID;

    int width;
    int height;
    int depth;

    Cube** cubes;

public:

    void render(int row, int column, int layer);

    Cube * makeCube(int row, int column, int layer);

    CubeManager(int width, int height, int depth);
    ~CubeManager();
};

