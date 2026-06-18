
// TetrisView.cpp : implementation of the CTetrisView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tetris.h"
#endif

#include "TetrisDoc.h"
#include "TetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTetrisView

IMPLEMENT_DYNCREATE(CTetrisView, CView)

BEGIN_MESSAGE_MAP(CTetrisView, CView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CTetrisView construction/destruction

CTetrisView::CTetrisView() noexcept
{
	// TODO: add construction code here

}

CTetrisView::~CTetrisView()
{
}

BOOL CTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

// CTetrisView drawing

void CTetrisView::OnDraw(CDC* pDC)
{
	CTetrisDoc* pDoc = GetDocument();    // GET DOCUMNENT FUNCTION CALL ***
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	// ACCESING MY GAME OBJ
	// TO DISPLAY THE DATA -> use CDC pointer
	// getDC() -> get device context -> a function that return CDC type pointer
	// drawing Board
	for (int row = 0; row < pDoc->game.getRows(); ++row) {
		for (int col = 0; col < pDoc->game.getCols(); ++col) {
			CRect block(col * BLOCK_WIDTH, row * BLOCK_HEIGHT, (col + 1) * BLOCK_WIDTH, (row + 1) * BLOCK_HEIGHT);
			pDC->Rectangle(block);
		}
	}
	DrawPiece(pDC);      // to draw tetrisPiece
}

void CTetrisView::DrawPiece(CDC* pDC) {
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	TetrisPiece* piece = pDoc->game.getCurrentPiece();
	if (!piece) return;

	fourBlocks blocks = piece->getBlocks();
	for (int i = 0; i < 4; ++i) {
		int x = blocks.blockPts[i].x;
		int y = blocks.blockPts[i].y;
		// Calculate display coordinates
		int displayX = (pDoc->game.getCurrentCols() + x) * BLOCK_WIDTH;
		int displayY = (pDoc->game.getCurrentRows() + y) * BLOCK_HEIGHT;

		CRect block(displayX, displayY, displayX + BLOCK_WIDTH, displayY + BLOCK_HEIGHT);
		pDC->FillSolidRect(block, piece->getColor()); // Draw colored block
	}
}


// CTetrisView diagnostics

#ifdef _DEBUG
void CTetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CTetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTetrisDoc* CTetrisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisDoc)));
	return (CTetrisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisView message handlers 

void CTetrisView::ResizeWindow()
{
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size based on the size of the game board
	rcWindow.right = rcWindow.left + (450) + nWidthDiff;
	rcWindow.bottom = rcWindow.top + (600) + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}

void CTetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	CTetrisDoc* pDoc = GetDocument();
	if (nChar == VK_LEFT) {
		pDoc->game.movePieceLeft();
	}
	else if (nChar == VK_RIGHT) {
		pDoc->game.movePieceRight();
	}
	else if (nChar == VK_DOWN) {
		pDoc->game.movePieceDown();
	}
	else if (nChar == VK_RETURN) {
		pDoc->game.rotatePiece();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CTetrisView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(1, 300, nullptr); // 200ms time to redraw screen
	ResizeWindow();
}


void CTetrisView::OnTimer(UINT_PTR nIDEvent)
{
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (nIDEvent == 1) {
		pDoc->game.movePieceDown();
		Invalidate(); // Redraw the screen
	}

	CView::OnTimer(nIDEvent);
}