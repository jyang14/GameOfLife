#include "Cube.h"
#include <cmath>
#include <cstring>


void Cube::calculateNormals()
{
    float sum;
    float v[6];

    for (unsigned int i = 0; i < triangles; i++)
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

float * Cube::getVertices()
{
    return vertices;
}

float * Cube::getNormals()
{
    return normals;
}

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

Cube::Cube(int x, int y, int z, GLuint textureVBOID)
    : vertices{
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
},
triangles(12), textureVBOID(textureVBOID)
{

    for (unsigned int i = 0; i < triangles * 3; i++)
    {
        vertices[i * 3] += x;
        vertices[i * 3 + 1] += y;
        vertices[i * 3 + 2] += z;

    }

    calculateNormals();

    vertexVBOID = 0;
    glGenBuffers(1, &vertexVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, vertices, GL_STATIC_DRAW);

    normalsVBOID = 0;
    glGenBuffers(1, &normalsVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, normals, GL_STATIC_DRAW);


}

Cube::Cube(Cube & other)
    :triangles(12), textureVBOID(other.textureVBOID)
{
    std::memcpy(vertices, other.vertices, sizeof(float)* triangles * 9);

    calculateNormals();

    vertexVBOID = 0;
    glGenBuffers(1, &vertexVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, vertices, GL_STATIC_DRAW);

    normalsVBOID = 0;
    glGenBuffers(1, &normalsVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, normals, GL_STATIC_DRAW);

}

Cube & Cube::operator=(Cube & other)
{
    if (this == &other)
        return *this;


    std::memcpy(vertices, other.vertices, sizeof(float)* triangles * 9);

    calculateNormals();

    if (normalsVBOID)
        glDeleteBuffers(1, &normalsVBOID);
    if (vertexVBOID)
        glDeleteBuffers(1, &vertexVBOID);

    vertexVBOID = 0;
    glGenBuffers(1, &vertexVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, vertices, GL_STATIC_DRAW);

    normalsVBOID = 0;
    glGenBuffers(1, &normalsVBOID);
    glBindBuffer(GL_ARRAY_BUFFER, normalsVBOID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* triangles * 9, normals, GL_STATIC_DRAW);

    return *this;
}


Cube::~Cube()
{
    glDeleteBuffers(1, &normalsVBOID);
    glDeleteBuffers(1, &vertexVBOID);
}
