#include "Cube.h"
#include <cstring>

int Cube::getTriangleCount()
{
    return triangles;
}

void Cube::render()
{

    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBOID);
    glVertexPointer(3, GL_FLOAT, 0, NULL);

    glEnableClientState(GL_NORMAL_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBOID);
    glNormalPointer(GL_FLOAT, 0, NULL);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, textureVBOID);
    glTexCoordPointer(2, GL_FLOAT, 0, NULL);

    // Actually draw the triangle, giving the number of vertices provided
    glDrawArrays(GL_TRIANGLES, 0, triangles * 3);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}

Cube::Cube(int x, int y, int z, GLuint normalsVBOID, GLuint textureVBOID)
    :
    triangles(12), normalsVBOID(normalsVBOID), textureVBOID(textureVBOID)
{
    float vertices[12 * 3 * 3] = {
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

    for (unsigned int i = 0; i < triangles * 3; i++)
    {
        vertices[i * 3] += x;
        vertices[i * 3 + 1] += y;
        vertices[i * 3 + 2] += z;

    }

    vertexVBOID = 0;
    glGenBuffers(1, &vertexVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, vertices, GL_STATIC_DRAW);

}

Cube::~Cube()
{
    glDeleteBuffers(1, &vertexVBOID);
}
