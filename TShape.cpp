#include "pch.h"
#include "TShape.h"
 // PERFECT
TShape::TShape() : TetrisPiece(4) {
	State[0] = fourBlocks(0, 0, 1, 0, 2, 0, 1, 1, 1);
	State[1] = fourBlocks(1, -1, 1, 0, 1, 1, 2, 0, 1);
	State[2] = fourBlocks(1, -1, 0, 0, 1, 0, 2, 0, 0);
	State[3] = fourBlocks(1, -1, 1, 0, 1, 1, 0, 0, 1);
	fptr = &State[0];
}

void TShape::rotateAntiClock() {
	currentState = (currentState + 1) % rotations; // circular
	fptr = &State[currentState];
}


