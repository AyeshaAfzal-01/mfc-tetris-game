#include "pch.h"
#include "Stick.h"

Stick::Stick() : TetrisPiece(2) {
	State[0] = fourBlocks(0, 0, 0, 1, 0, 2, 0, 3, 3);  // maxima -> y = 3
	State[1] = fourBlocks(0, 0, 1, 0, 2, 0, 3, 0, 0); // maxima -> y = 2 for state 1
	fptr = &State[0]; // fptr pointing to first state
}
void Stick::rotateAntiClock() {
	currentState = (currentState + 1) % rotations; // circular
	fptr = &State[currentState];
}
