#pragma once
#include "Board.h"
#include <vector>

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
    void playOne();
    int setState(const char * state);
    void randomState();

    int compareCurrentState(const char * state);

    Game(int width, int height, int depth, int mod, int liveMin, int liveMax, int birthMin, int birthMax);
    ~Game();
};

