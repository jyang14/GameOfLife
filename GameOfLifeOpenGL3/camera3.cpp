#include "camera3.h"

#include <cmath>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>


const float camera3::pi = 3.1415925358979323846264338f;

camera3::camera3() :
    position_(0, 0, 60), theta1_(pi), theta2_(0), speed_(20)
{
}

glm::vec3 camera3::get_position() const
{
    return position_;
}

glm::mat4 camera3::get_view_matrix()
{
    return glm::lookAt(position_, 
        glm::vec3(position_[0] + cos(theta2_) * sin(theta1_),
        position_[1] + sin(theta2_),
        position_[2] + cos(theta2_) * cos(theta1_)),
        glm::vec3(0, 1, 0));
}

glm::mat4 camera3::get_perspective_matrix()
{
    return glm::perspective(50.0f, 16.0f / 9.0f, 1.0f, 200.0f);
}

void camera3::forward(const int ms)
{
    position_[0] += speed_ * ms / 1000.0f * sin(theta1_);
    position_[2] += speed_ * ms / 1000.0f * cos(theta1_);
}

void camera3::backwards(const int ms)
{
    position_[0] -= speed_ * ms / 1000.0f * sin(theta1_);
    position_[2] -= speed_ * ms / 1000.0f * cos(theta1_);
}

void camera3::left(const int ms)
{
    position_[0] += speed_ * ms / 1000.0f * sin(theta1_ - pi / 2);
    position_[2] += speed_ * ms / 1000.0f * cos(theta1_ - pi / 2);
}

void camera3::right(const int ms)
{
    position_[0] += speed_ * ms / 1000.0f * sin(theta1_ + pi / 2);
    position_[2] += speed_ * ms / 1000.0f * cos(theta1_ + pi / 2);
}

void camera3::up(const int ms)
{
    position_[1] -= speed_ * ms / 1000.0f;
}

void camera3::down(const int ms)
{
    position_[1] += speed_ * ms / 1000.0f;
}

void camera3::angle(const int delta_x, const int delta_y)
{
    theta1_ += delta_x / 500.0f;
    theta2_ += delta_y / 500.0f;
}

void camera3::print_data()
{
    std::cout << "Theta1: " << theta1_ << std::endl;
    std::cout << "Theta2: " << theta2_ << std::endl;
    std::cout << "Position-x: " << position_[0] << std::endl;
    std::cout << "Position-y: " << position_[1] << std::endl;
    std::cout << "Position-z: " << position_[2] << std::endl;

}