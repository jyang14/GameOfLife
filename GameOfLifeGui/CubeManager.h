#pragma once

#include "GL/glew.h"
#include "Cube.h"

class CubeManager
{
    static const float textures[12 * 3 * 2];
    static const float vertices[12 * 3 * 3];

    GLuint textureVBOID;
    GLuint normalsVBOID;

    int width;
    int height;
    int depth;

    Cube** cubes;

public:

    void calculateNormals(float * normals);

    void render(int row, int column, int layer);

    Cube * makeCube(int row, int column, int layer);

    CubeManager(int width, int height, int depth);
    ~CubeManager();
};

