#pragma once
#include <cstdint>
#include <GL/glew.h>

class Cube
{
    float vertices[12 * 3 * 3];
    float normals[12 * 3 * 3];

    uint32_t triangles;

    GLuint vertexVBOID;
    const GLuint normalsVBOID;
    const GLuint textureVBOID;

public:
    float* getVertices();
    float* getNormals();
    int getTriangleCount();

    void render();

    Cube(int x, int y, int z, GLuint normalsVBOID, GLuint texturesVBOID);
    Cube(Cube &other);

    Cube & operator=(Cube &other);

    ~Cube();
};

