
// AnotherGameView.cpp : implementation of the CAnotherGameView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AnotherGame.h"
#endif

#include "AnotherGameDoc.h"
#include "AnotherGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnotherGameView

IMPLEMENT_DYNCREATE(CAnotherGameView, CView)

BEGIN_MESSAGE_MAP(CAnotherGameView, CView)
END_MESSAGE_MAP()

// CAnotherGameView construction/destruction

CAnotherGameView::CAnotherGameView() noexcept
{
	// TODO: add construction code here

}

CAnotherGameView::~CAnotherGameView()
{
}

BOOL CAnotherGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}



// CAnotherGameView drawing

// CAnotherGameView drawing

void CAnotherGameView::OnDraw(CDC* pDC) // MFC will comment out the argument name by default; uncomment it
{
	//  First get a pointer to the document
	CAnotherGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//  Save the current state of the device context
	int nDCSave = pDC->SaveDC();
	//  Get the client rectangle
	CRect rcClient;
	GetClientRect(&rcClient);
	//  Get the background color of the board
	COLORREF clr = pDoc->GetBoardSpace(-1, -1);
	//	Draw the background first
	pDC->FillSolidRect(&rcClient, clr);
	//  Create the brush for drawing
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);
	//	Draw the squares
	for (int row = 0; row < pDoc->GetRows(); row++)
	{
		for (int col = 0; col < pDoc->GetColumns(); col++)
		{
			//  Get the color for this board space
			clr = pDoc->GetBoardSpace(row, col);
			//  Calculate the size and position of this space
			CRect rcBlock;
			rcBlock.top = row * pDoc->GetHeight();
			rcBlock.left = col * pDoc->GetWidth();
			rcBlock.right = rcBlock.left + pDoc->GetWidth();
			rcBlock.bottom = rcBlock.top + pDoc->GetHeight();
			//  Fill in the block with the correct color
			pDC->FillSolidRect(&rcBlock, clr);
			//  Draw the block outline
			pDC->Rectangle(&rcBlock);
		}
	}
	//  Restore the device context settings
	pDC->RestoreDC(nDCSave);
	br.DeleteObject();
}


// CAnotherGameView diagnostics

#ifdef _DEBUG
void CAnotherGameView::AssertValid() const
{
	CView::AssertValid();
}

void CAnotherGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnotherGameDoc* CAnotherGameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnotherGameDoc)));
	return (CAnotherGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CAnotherGameView message handlers


void CAnotherGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	//  Resize the window
	ResizeWindow();
	// TODO: Add your specialized code here and/or call the base class
}

void CAnotherGameView::ResizeWindow()
{
	//  First get a pointer to the document
	CAnotherGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//  Get the size of the client area and the window
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size based on the size of the game board
	rcWindow.right = rcWindow.left +
		pDoc->GetWidth() * pDoc->GetColumns() + nWidthDiff;
	rcWindow.bottom = rcWindow.top +
		pDoc->GetHeight() * pDoc->GetRows() + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}
