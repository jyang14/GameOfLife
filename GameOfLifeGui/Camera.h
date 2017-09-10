#pragma once
class Camera
{
private:
    static const float PI;
    float position[4];
    float theta1;
    float theta2;
    float speed;
public:
    void look();
    void forward(int ms);
    void backwards(int ms);
    void left(int ms);
    void right(int ms);
    void up(int ms);
    void down(int ms);

    void angle(int deltaX, int deltaY);

    void printData();

    Camera();
    ~Camera();
};

