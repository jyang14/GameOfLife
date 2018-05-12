#pragma once
#include <glm/matrix.hpp>


class camera3
{
    static const float pi;
    glm::vec3 position_;
    float theta1_;
    float theta2_;
    float speed_;
public:
    glm::mat4 get_view_matrix();
    static glm::mat4 get_perspective_matrix();
    glm::vec3 get_position() const;

    void forward(int ms);
    void backwards(int ms);
    void left(int ms);
    void right(int ms);
    void up(int ms);
    void down(int ms);

    void angle(int delta_x, int delta_y);

    void print_data();

    camera3();
};
