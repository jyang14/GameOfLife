#include "Board.h"
#include <cstring>


char * Board::get(int row, int column, int layer)
{
    return &board[layer * width * height + row * width + column];
}

void Board::clearBoard()
{
    std::memset(board, 0, width * height * depth * sizeof(char));
}

int Board::isOccupied(int row, int column, int layer)
{
    // if out of bounds return 0
    if (row < 0 || row >= height ||
        column < 0 || column >= width ||
        layer < 0 || layer >= depth)
    {
        if (!mod)
            return 0;
        return *get((row + height) % height, (column + width) % width, (layer + depth) % depth);
    }


    // Note: occupied cells have a value of 1
    // Unoccupied cells have a value of 0
    return *get(row, column, layer);
}


int Board::getNeighborCount(int row, int column, int layer)
{
    int neighborCount = 0;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            for (int k = -1; k <= 1; k++)
                if (i != 0 || j != 0 || k != 0)
                    neighborCount += isOccupied(row + i, column + j, layer + k);
    return neighborCount;
}

void Board::toggleCellAt(int row, int column, int layer)
{
    if (row < 0 || row >= height ||
        column < 0 || column >= width)
        return;

    *get(row, column, layer) =
        !*get(row, column, layer);
}

void Board::align(int oldWidth, int oldHeight, int oldDepth)
{
    // if fileWidth is less than boardWidth enough
    // that recentering need to happen
    if (oldWidth < width - 1)
    {
        int columnOffset = (int) (width * .5 - oldWidth * .5);
        for (int layer = 0; layer < oldDepth; layer++)
            for (int row = 0; row < oldHeight; row++)
            {
                memmove(get(row, columnOffset, layer),
                    get(row, 0, layer), oldWidth);
                memset(get(row, 0, layer),
                    0, columnOffset * sizeof(char));
            }
    }

    // if fileHeight is less than boardHeight enough
    // that recentering need to happen
    if (oldHeight < height - 1)
    {
        for (int layer = 0; layer < oldDepth; layer++)
        {
            int rowOffset = (int) (height * .5 - oldHeight * .5);
            memmove(get(rowOffset, 0, layer),
                get(0, 0, layer), oldHeight * width);
            memset(get(0, 0, layer),
                0, rowOffset * width * sizeof(char));
        }
    }
    if (oldDepth < depth - 1)
    {
        int layerOffset = (int) (depth * .5 - oldDepth * .5);

        memmove(get(0, 0, layerOffset),
            get(0, 0, 0), layerOffset * height * width);
        memset(get(0, 0, 0),
            0, layerOffset * width * height * sizeof(char));

    }
}

char * Board::getBoard()
{
    return board;
}

Board::Board(int width, int height, int depth, int mod)
    :width(width), height(height), depth(depth), mod(mod)
{
    board = new char[width * height * depth];
    clearBoard();
}

Board::Board(Board & oldBoard)
    :width(oldBoard.width), height(oldBoard.height), depth(oldBoard.depth)
{
    board = new char[width * height * depth];
    std::memcpy(board, oldBoard.board, width * height * depth);
}

Board & Board::operator=(Board & oldBoard)
{

    if (&oldBoard == this)
        return *this;

    width = oldBoard.width;
    height = oldBoard.height;
    depth = oldBoard.depth;
    if (board != nullptr)
        delete[] board;
    board = new char[width * height * depth];
    std::memcpy(board, getBoard(), width * height * depth);

    return *this;
}



Board::~Board()
{
    delete[] board;
}
