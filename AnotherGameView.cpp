
// AnotherGameView.cpp: реализация класса CAnotherGameView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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

// Создание или уничтожение CAnotherGameView

CAnotherGameView::CAnotherGameView() noexcept
{
	// TODO: добавьте код создания

}

CAnotherGameView::~CAnotherGameView()
{
}

BOOL CAnotherGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CAnotherGameView

void CAnotherGameView::OnDraw(CDC* /*pDC*/)
{
	CAnotherGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Диагностика CAnotherGameView

#ifdef _DEBUG
void CAnotherGameView::AssertValid() const
{
	CView::AssertValid();
}

void CAnotherGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnotherGameDoc* CAnotherGameView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnotherGameDoc)));
	return (CAnotherGameDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CAnotherGameView
