#include "pch.h"
#include "LeftStair.h"

LeftStair::LeftStair() : Stair(2) { 
    State[0] = fourBlocks(0, 0, 1, 0, 1, 1, 2, 1, 1); // Horizontal Z-shape
    State[1] = fourBlocks(0, 1, 0, 0, 1, 0, 1, -1, 1); // Vertical Z-shape
    fptr = &State[0];
}