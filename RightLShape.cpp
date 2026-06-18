#include "pch.h"
#include "RightLShape.h"
RightLShape::RightLShape() : LShape(4) {
    State[0] = fourBlocks(0, 0, 1, 0, 2, 0, 0, 1, 1); 
    State[1] = fourBlocks(0, -1, 0, 0, 0, 1, 1, 1, 1); 
    State[2] = fourBlocks(2, 0, 0, 1, 1, 1, 2, 1, 1); 
    State[3] = fourBlocks(0, -1, 1, -1, 1, 0, 1, 1, 1); 
    fptr = &State[0];
}
