#include "pch.h"
#include "Game.h"

Game::Game() {
    rows = 20;
    cols = 15;
    board = new int* [rows];  // board initialization with all cells color white
    for (int i = 0; i < rows; ++i) {
        board[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            board[i][j] = colorArray[0];
        }
    }
    srand((unsigned)time(0));  
    int randomPiece = rand() % 7;
    switch (randomPiece) {
    case 0: piecePtr = new TShape(); break;
    case 1: piecePtr = new LeftStair(); break;
    case 2: piecePtr = new RightStair(); break;
    case 3: piecePtr = new Stick(); break;
    case 4: piecePtr = new RightLShape(); break;
    case 5: piecePtr = new LeftLShape(); break;
    case 6: piecePtr = new Square(); break; 
    }
    currentRow = 0;
    currentCol = cols / 2; // starting in the middle of board
}

Game::~Game() {
    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;

    delete piecePtr;
}

void Game::selectNextPiece() {
    delete piecePtr;        // Delete the current piece

    int randomPiece = rand() % 7;  // now selecting a new random piece
    switch (randomPiece) {
    case 0: piecePtr = new TShape(); break;
    case 1: piecePtr = new LeftStair(); break;
    case 2: piecePtr = new RightStair(); break;
    case 3: piecePtr = new Stick(); break;
    case 4: piecePtr = new RightLShape(); break;
    case 5: piecePtr = new LeftLShape(); break;
    case 6: piecePtr = new Square(); break;
    }
    currentRow = 0;                // reset postion
    currentCol = cols / 2;
}

void Game::rotatePiece() {
    if (!piecePtr) return;
    piecePtr->rotateAntiClock();
}

void Game::movePieceDown() {
    if (currentRow == 18) {
        selectNextPiece();
    }
    currentRow++;
}
void Game::movePieceLeft() {
    if (currentCol == 0) return;
    currentCol--;
}

void Game::movePieceRight() {
    if (currentCol == 13) return;
    currentCol++;
}

int Game::getRows() const {
    return rows;
}
int Game::getCols() const {
    return cols;
}

int Game::getCurrentRows() const {
    return currentRow;
}
int Game::getCurrentCols() const {
    return currentCol;
}

TetrisPiece* Game::getCurrentPiece() const {
    return piecePtr; // Return the pointer to the current Tetris piece
}