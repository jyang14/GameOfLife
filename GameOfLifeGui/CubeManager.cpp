#include "CubeManager.h"
#include <cstring>

const float CubeManager::textures[] = {
    1.0f, 1.0f, // Good
    1.0f, 0.0f,
    0.0f, 0.0f,

    0.0f, 0.0f, // Good
    1.0f, 1.0f,
    1.0f, 0.0f,

    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f, // Good
    0.0f, 1.0f,
    1.0f, 1.0f,

    1.0f, 1.0f, // Good
    0.0f, 0.0f,
    0.0f, 1.0f,

    1.0f, 0.0f,
    0.0f, 0.0f,
    0.0f, 1.0f,

    1.0f, 1.0f, // Good
    1.0f, 0.0f,
    0.0f, 0.0f,

    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 1.0f,
    1.0f, 0.0f,
    0.0f, 0.0f,

    0.0f, 0.0f, // Good
    0.0f, 1.0f,
    1.0f, 1.0f,

    0.0f, 0.0f, // Good 
    1.0f, 1.0f,
    1.0f, 0.0f,

    0.0f, 1.0f, // Good
    1.0f, 1.0f,
    0.0f, 0.0f
};

void CubeManager::render(int row, int column, int layer)
{
    if (!cubes[layer * height * width + row * width + column])
        cubes[layer * height * width + row * width + column] = makeCube(row, column, layer);
    cubes[layer * height * width + row * width + column]->render();
}

Cube * CubeManager::makeCube(int row, int column, int layer)
{
    return new Cube(column - width / 2, -row, layer - depth / 2, textureVBOID);
}

CubeManager::CubeManager(int width, int height, int depth)
    :width(width), height(height), depth(depth)
{

    textureVBOID = 0;
    glGenBuffers(1, &textureVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, textureVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12 * 3 * 2, textures, GL_STATIC_DRAW);

    cubes = new Cube*[height * width * depth];

    std::memset(cubes, 0, height * width * depth * sizeof(Cube*));

}

CubeManager::~CubeManager()
{
    for (int i = 0; i < depth * width * height; i++)
    {
        if (cubes[i])
            delete cubes[i];
    }
    delete[] cubes;

    glDeleteBuffers(1, &textureVBOID);

}
