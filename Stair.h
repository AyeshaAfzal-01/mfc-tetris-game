#pragma once
#include "TetrisPiece.h"
class Stair : public TetrisPiece
{
protected:
    fourBlocks State[2];
public:
    Stair(int rotations);
    void rotateAntiClock();
};

