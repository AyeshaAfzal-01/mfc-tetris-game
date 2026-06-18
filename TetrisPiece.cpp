#include "pch.h"
#include "TetrisPiece.h"

TetrisPiece::TetrisPiece(int totalRotations) : rotations(totalRotations), currentState(0) {
	srand((unsigned)time(0));
	colorIndex = 1 + rand() % 4;
	color = colorArray[colorIndex];
	fptr = nullptr;
}

TetrisPiece::~TetrisPiece() { }
// getter setter functions
COLORREF TetrisPiece::getColor() const {   // for CDC
	return color;
}
void TetrisPiece::setfptr(fourBlocks* state) {
	fptr = &state[currentState];  // fptr pointing to current state
	// set to this e.g stateArray[0] if current state is 0
}
fourBlocks TetrisPiece::getBlocks() const {
	if (fptr) {  // Ensure fptr is not null
		return *fptr; // return current shape position
	}
	return fourBlocks(); // Return an empty struct if fptr is null
}