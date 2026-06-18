#pragma once
#include <cstdlib>
#include <ctime>
#include "TetrisPiece.h"
class TShape : public TetrisPiece
{
	fourBlocks State[4];  // 4 states of T shape
public:
	TShape();
	void rotateAntiClock();
};

