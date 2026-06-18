#include "pch.h"
#include "Square.h"

Square::Square() : TetrisPiece(1) {
	State[0] = fourBlocks(0, 0, 1, 0, 0, 1, 1, 1, 1); // last maxima = 0
	fptr = &State[0];
}
void Square::rotateAntiClock() {}