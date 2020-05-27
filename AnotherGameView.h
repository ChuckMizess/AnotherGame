
// AnotherGameView.h: интерфейс класса CAnotherGameView
//

#pragma once


class CAnotherGameView : public CView
{
protected: // создать только из сериализации
	CAnotherGameView() noexcept;
	DECLARE_DYNCREATE(CAnotherGameView)

// Атрибуты
public:
	CAnotherGameDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CAnotherGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в AnotherGameView.cpp
inline CAnotherGameDoc* CAnotherGameView::GetDocument() const
   { return reinterpret_cast<CAnotherGameDoc*>(m_pDocument); }
#endif

