#pragma once
class Board
{
    int width;
    int height;
    int depth;

    int mod;

    int * board;

    int * get(int row, int column, int layer);

public:
    void clearBoard();

    int isOccupied(int row, int column, int layer);

    int getNeighborCount(int row, int column, int layer);

    void toggleCellAt(int row, int column, int layer);

    void align(int oldWidth, int oldHeight, int oldDepth);

    int* getBoard();

    Board(int width, int height, int depth, int mod);

    Board(Board &oldBoard);

    Board& operator=(Board &oldBoard);

    ~Board();
};

