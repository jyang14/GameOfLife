#pragma once
#include <cstdint>
#include <GL/glew.h>

class Cube
{
    float vertices[12 * 3 * 3];
    float normals[12 * 3 * 3];
    static const float textures[12 * 3 * 2];

    uint32_t triangles;

    void calculateNormals();

    GLuint vertexVBOID;
    GLuint normalsVBOID;
    GLuint textureVBOID;

public:
    float* getVertices();
    float* getNormals();
    int getTriangleCount();

    void render();

    Cube(int x, int y, int z);
    Cube(Cube &other);

    Cube & operator=(Cube &other);

    ~Cube();
};

