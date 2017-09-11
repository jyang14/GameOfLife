#pragma once
#include <cstdint>
#include <GL/glew.h>

class Cube
{
    uint32_t triangles;

    GLuint vertexVBOID;
    const GLuint normalsVBOID;
    const GLuint textureVBOID;

public:
    int getTriangleCount();

    void render();

    Cube(int x, int y, int z, GLuint normalsVBOID, GLuint texturesVBOID);
    Cube(Cube &other) = delete;

    Cube & operator=(Cube &other) = delete;

    ~Cube();
};

