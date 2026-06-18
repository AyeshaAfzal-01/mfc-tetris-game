#include "pch.h"
#include "Stair.h"
Stair::Stair(int rotations) : TetrisPiece(rotations) {}
void Stair::rotateAntiClock() {
        currentState = (currentState + 1) % rotations;
        fptr = &State[currentState];
 }