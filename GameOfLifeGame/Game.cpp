#include "Game.h"
#include <cstring>
#include <random>

void Game::playOne()
{

    boards[(gen + 1) % 2].clearBoard();

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            for (int layer = 0; layer < depth; layer++)
            {
                int neighborCount = boards[gen % 2].getNeighborCount(row, column, layer);

                // if occupied
                if (boards[gen % 2].isOccupied(row, column, layer))
                {
                    // if alive set cell in next generation to occupied
                    if (neighborCount >= liveMin && neighborCount <= liveMax)
                        boards[(gen + 1) % 2].toggleCellAt(row, column, layer);
                }
                // if new cell is born set cell in next generation as occupied
                else if (neighborCount >= birthMin && neighborCount <= birthMax)
                {
                    boards[(gen + 1) % 2].toggleCellAt(row, column, layer);
                }
            }
        }
    }
    gen++;


}

int Game::setState(const char * state)
{
    gen = 0;

    int fileWidth = 1;
    int fileHeight = 1;
    int fileDepth = 1;

    int row = 0;
    int column = 0;
    int layer = 0;

    boards[0].clearBoard();

    int index = 0;
    // TODO: excessive blank spaces after sequence of characters
    while (state[index] != '\0')
    {
        if (state[index] == ' ' || state[index] == 'o' || state[index] == 'x')
        {
            if (fileWidth == column)
                fileWidth++;

            // if file width is great than
            // user specified width of board
            // exit function with error code 2
            if (fileWidth > width)
                return 2;

            // Note: incremented here to allow for leeway
            // for a '\n' at the end of the file
            while (fileHeight <= row)
                fileHeight++;

            // if file height is greater than
            // user specified height of board
            // exit function with error code 3
            if (fileHeight > height)
                return 3;

            while (fileDepth <= layer)
                fileDepth++;

            // if file depth is greater than
            // user specified depth of board
            // exit function with error code 4
            if (fileDepth > depth)
                return 4;

            if (state[index] == 'x')
                boards[0].toggleCellAt(row, column, layer);
            column++;
        }
        else if (state[index] == '\t')
        {
            column = 0;
            row++;
        }
        else if (state[index] == '\n')
        {
            column = 0;
            row = 0;
            layer++;
        }
        // if not one of those chars
        // invalid file/input
        else
        {
            return 1;
        }
        index++;

    }

    boards[0].align(fileWidth, fileHeight, fileDepth);
    return 0;
}

void Game::randomState()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    //std::uniform_int_distribution<> dis(0, 1);

    std::bernoulli_distribution dis(.4);

    for (int row = 0; row < height; row++)
        for (int column = 0; column < width; column++)
            for (int layer = 0; layer < depth; layer++)
                if (dis(mt))
                    boards[0].toggleCellAt(row, column, layer);
    gen = 0;



}

int Game::compareCurrentState(const char * state)
{
    for (int i = 0; i < width * height * depth; i++)
    {
        if (state[i] != boards[gen % 2].getBoard()[i])
            return 0;
    }


    return 1;
}


Game::Game(int width, int height, int depth,int mod, int liveMin, int liveMax, int birthMin, int birthMax)
    : boards{ Board(width, height, depth, mod), Board(width, height, depth, mod) }, 
    width(width), height(height), depth(depth),
    liveMin(liveMin),  liveMax(liveMax),
    birthMin(birthMin), birthMax(birthMax)
{
    gen = 0;
}

Game::~Game()
{
}
