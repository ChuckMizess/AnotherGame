
// AnotherGameView.h : interface of the CAnotherGameView class
//

#pragma once


class CAnotherGameView : public CView
{
protected: // create from serialization only
	CAnotherGameView() noexcept;
	DECLARE_DYNCREATE(CAnotherGameView)

// Attributes
public:
	CAnotherGameDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	void ResizeWindow();

	virtual ~CAnotherGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in AnotherGameView.cpp
inline CAnotherGameDoc* CAnotherGameView::GetDocument() const
   { return reinterpret_cast<CAnotherGameDoc*>(m_pDocument); }
#endif

