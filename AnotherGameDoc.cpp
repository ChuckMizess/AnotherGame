

// Команды CAnotherGameDoc
#include "pch.h"
//#include "framework.h"
#include "AnotherGame.h"
//#include <propkey.h>
#include "AnotherGameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAnotherGameBoard
IMPLEMENT_DYNCREATE(CAnotherGameBoard, CDocument)
BEGIN_MESSAGE_MAP(CAnotherGameBoard, CDocument)
END_MESSAGE_MAP()

// Создание CAnotherGameBoard
CAnotherGameBoard::CAnotherGameBoard()
{
}

// Уничтожение CAnotherGameBoard
CAnotherGameBoard::~CAnotherGameBoard()
{
}

BOOL CAnotherGameBoard::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// Установка (или сброс) параметров доски
	m_board.SetupBoard();

	return TRUE;
}