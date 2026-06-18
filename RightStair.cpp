#include "pch.h"
#include "RightStair.h"

RightStair::RightStair() : Stair(2) { 
    State[0] = fourBlocks(0, 1, 1, 1, 1, 0, 2, 0, 1); // Horizontal S-shape
    State[1] = fourBlocks(0, 0, 0, 1, 1, 1, 1, 2, 2); // Vertical S-shape
    fptr = &State[0];
}