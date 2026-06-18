#pragma once
#include "TetrisPiece.h"
class Stick : public TetrisPiece
{
	fourBlocks State[2]; // stick has two states
public:
	Stick();
	void rotateAntiClock();
};

