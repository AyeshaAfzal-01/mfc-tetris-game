#pragma once
#include <iostream>
using namespace std;

struct point {
	int x; int y;
	void setter(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

struct fourBlocks {
	point blockPts[4];
	int maxima_y;
	fourBlocks() {   // default CTOR
		for (int i = 0; i < 4;i++) {
			blockPts[i].setter(0, 0);
			maxima_y = 0;
		}
	}
	fourBlocks(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int maxima) {  // para
		// CTOR
		blockPts[0].setter(x0, y0);
		blockPts[1].setter(x1, y1);
		blockPts[2].setter(x2, y2);
		blockPts[3].setter(x3, y3);
		maxima_y = maxima;
	}
};
const int BLOCK_HEIGHT = 30;
const int BLOCK_WIDTH = 30;
const COLORREF colorArray[5] = { (RGB(255, 255, 255)), (RGB(255,32, 78)), (RGB(0, 0, 255)),
 (RGB(255, 150, 0)), (RGB(255, 0, 0)) };

class TetrisPiece
{
protected:
	COLORREF color; //color of the TetrisPiece
	int colorIndex; //index to select value for ‘color’ from global const colorArray[5]
	fourBlocks* fptr; //fptr is a pointer that will be inherited in derived classes of
	//TetrisPiece and will be made to point a fourBlocks structure
	//as will be discussed later.
	const int rotations; //total distinct rotations possible for a peice
	int currentState; //current state of the TetrisPiece. It will be used in setting fptr
public:
	TetrisPiece(int totalRotations);
	virtual ~TetrisPiece();
	COLORREF getColor() const;
	virtual void TetrisPiece::rotateAntiClock() = 0; // pure virtual -> abstract
	void setfptr(fourBlocks* stateArray);
	fourBlocks getBlocks() const;
};

