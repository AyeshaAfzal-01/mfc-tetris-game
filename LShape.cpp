#include "pch.h"
#include "LShape.h"

LShape::LShape(int rotations) : TetrisPiece(4) {}
void LShape::rotateAntiClock()
{
    currentState = (currentState + 1) % rotations;  // cyclic rotation
    fptr = &State[currentState];
}