#pragma once
#include "Board.h"
#include <glm/detail/type_vec3.hpp>
#include <functional>

class Game
{
protected:
    Board boards[2];
    int height;
    int width;
    int depth;
    int gen;

    int liveMin; 
    int liveMax; 

    int birthMin;
    int birthMax;
    
public:

    int get_height() const;
    int get_width() const;
    int get_depth() const;

    void playOne();
    int setState(const char * state);
    void randomState();

    int compareCurrentState(const char * state);

    void for_each_alive(const std::function<void (int, int, int)>& f);

    Game(int width, int height, int depth, int mod, int liveMin, int liveMax, int birthMin, int birthMax);
};

