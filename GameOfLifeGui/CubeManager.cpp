#include "CubeManager.h"
#include <cmath>
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

const float CubeManager::vertices[] = {
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    0.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f
};

void CubeManager::calculateNormals()
{
    float sum;
    float v[6];

    for (unsigned int i = 0; i < 12; i++)
    {

        for (int x = 0; x < 6; x++)
        {
            v[x] = vertices[i * 9 + 3 + x] - vertices[i * 9 + x % 3];
        }

        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            normals[i * 9 + j] = v[(j + 1) % 3] * v[3 + (j + 2) % 3] - v[(j + 2) % 3] * v[3 + (j + 1) % 3];
            sum += normals[i * 9 + j] * normals[i * 9 + j];
        }
        sum = 1 / sqrt(sum);
        for (int j = 0; j < 3; j++)
        {
            normals[i * 9 + j] *= sum;
            normals[i * 9 + j + 3] = normals[i * 9 + j];
            normals[i * 9 + j + 6] = normals[i * 9 + j];
        }
    }
}

void CubeManager::render(int row, int column, int layer)
{
    if (!cubes[layer * height * width + row * width + column])
        cubes[layer * height * width + row * width + column] = makeCube(row, column, layer);
    cubes[layer * height * width + row * width + column]->render();
}

Cube * CubeManager::makeCube(int row, int column, int layer)
{
    return new Cube(column - width / 2, -row, layer - depth / 2, normalsVBOID, textureVBOID);
}

CubeManager::CubeManager(int width, int height, int depth)
    :width(width), height(height), depth(depth)
{

    calculateNormals();

    normalsVBOID = 0;
    glGenBuffers(1, &normalsVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 12 * 3 * 3, normals, GL_STATIC_DRAW);

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
    glDeleteBuffers(1, &normalsVBOID);

}
