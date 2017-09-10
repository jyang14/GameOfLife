#include "Camera.h"
#include <GL/glew.h>
#include <cmath>
#include <iostream>


const float Camera::PI = 3.1415925358979323846264338f;

Camera::Camera() :
    position{ 0, 60, 0, 1 }, theta1(PI), theta2(0), speed(20)
{

    // Set the camera lens to have a 60 degree (vertical) field of view, an
    // aspect ratio of 4/3, and have everything closer than 1 unit to the
    // camera and greater than 40 units distant clipped away.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 4.0 / 3.0, 1, 200);

    look();
}

void Camera::look()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(position[0], position[1], position[2],
        position[0] + cos(theta2) * sin(theta1),
        position[1] + cos(theta2) * cos(theta1),
        position[2] + sin(theta2),
        0, 0, 1);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

}

void Camera::forward(int ms)
{
    position[0] += speed * ms / 1000.0f * sin(theta1);
    position[1] += speed * ms / 1000.0f * cos(theta1);
}

void Camera::backwards(int ms)
{
    position[0] -= speed * ms / 1000.0f * sin(theta1);
    position[1] -= speed * ms / 1000.0f * cos(theta1);
}

void Camera::left(int ms)
{
    position[0] += speed * ms / 1000.0f * sin(theta1 - PI / 2);
    position[1] += speed * ms / 1000.0f * cos(theta1 - PI / 2);
}

void Camera::right(int ms)
{
    position[0] += speed * ms / 1000.0f * sin(theta1 + PI / 2);
    position[1] += speed * ms / 1000.0f * cos(theta1 + PI / 2);
}

void Camera::up(int ms)
{
    position[2] += speed * ms / 1000.0f;
}

void Camera::down(int ms)
{
    position[2] -= speed * ms / 1000.0f;
}

void Camera::angle(int deltaX, int deltaY)
{
    theta1 += deltaX / 500.0f;
    theta2 -= deltaY / 500.0f;
}

void Camera::printData()
{
    std::cout << "Theta1: " << theta1 << std::endl;
    std::cout << "Theta2: " << theta2 << std::endl;
    std::cout << "Position-x: " << position[0] << std::endl;
    std::cout << "Position-y: " << position[1] << std::endl;
    std::cout << "Position-z: " << position[2] << std::endl;

}

Camera::~Camera()
{
}
