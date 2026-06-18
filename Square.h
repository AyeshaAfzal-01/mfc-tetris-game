#pragma once
#include "TetrisPiece.h"
class Square : public TetrisPiece
{
	fourBlocks State[1];  // square will have only one state
public:
	Square();
	void rotateAntiClock();   // will remain like this because square don't have any rotation
};

