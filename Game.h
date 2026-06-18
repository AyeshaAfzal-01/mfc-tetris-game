#pragma once
#include "TetrisPiece.h"
#include "Square.h"
#include "Stick.h"
#include "LShape.h"
#include "Stair.h"
#include "TShape.h"
#include "LeftLShape.h"
#include "RightLShape.h"
#include "LeftStair.h"
#include "RightStair.h"
class Game
{
private:
	int** board;
	int rows, cols;
	TetrisPiece* piecePtr;
	int currentRow;
	int currentCol;
public:
	Game();
	~Game();
	void selectNextPiece();
	void rotatePiece();
	void movePieceDown();
	void movePieceRight();
	void movePieceLeft();
	int getRows() const;
	int getCols() const;
	int getCurrentRows() const;
	int getCurrentCols() const;
	TetrisPiece* getCurrentPiece() const;
};

