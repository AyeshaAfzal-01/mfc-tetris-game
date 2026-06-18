#pragma once
#include "TetrisPiece.h"
class LShape : public TetrisPiece
{
protected:
fourBlocks State[4]; // Each block has 4 rotation states
public:
LShape(int rotations); 
void rotateAntiClock(); // To rotate the shapes anticlockwise
};

