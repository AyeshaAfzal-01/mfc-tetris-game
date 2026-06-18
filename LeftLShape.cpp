#include "pch.h"
#include "LeftLShape.h"

LeftLShape::LeftLShape() : LShape(4) {
    State[0] = fourBlocks(0, 0, 0 ,1, 1, 1, 2, 1, 1); 
    State[1] = fourBlocks(1, 0, 1, 1, 1, 2, 0, 2, 2); 
    State[2] = fourBlocks(0, 0, 1, 0, 2, 0, 2, 1, 1); 
    State[3] = fourBlocks(1, 0, 0, 0, 0, 1, 0, 2, 2); 
    fptr = &State[0];
}
