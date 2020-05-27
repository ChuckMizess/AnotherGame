#include "pch.h"
#include "CAnotherGameBoard.h"


CAnotherGameBoard::CAnotherGameBoard(void)
	: m_arrBoard(NULL),
	m_nColumns(15), m_nRows(15),
	m_nHeight(35), m_nWidth(35)
{
	m_arrColors[0] = RGB(0, 0, 0);
	m_arrColors[1] = RGB(255, 0, 0);
	m_arrColors[2] = RGB(255, 255, 64);
	m_arrColors[3] = RGB(0, 0, 255);
}

CAnotherGameBoard::~CAnotherGameBoard(void)
{
	// Просто удаляем нашу доску
	DeleteBoard();
}

void CAnotherGameBoard::SetupBoard(void)
{
	// При необходимости создаём доску
	if (m_arrBoard == NULL)
		CreateBoard();

	// Устанавливаем каждому блоку случайный цвет 
	for (int row = 0; row < m_nRows; row++)
		for (int col = 0; col < m_nColumns; col++)
			m_arrBoard[row][col] = (rand() % 3) + 1;
}

COLORREF CAnotherGameBoard::GetBoardSpace(int row, int col)
{
	// Проверяем границы массива
	if (row < 0 || row >= m_nRows || col < 0 || col >= m_nColumns)
		return m_arrColors[0];
	return m_arrColors[m_arrBoard[row][col]];
}

void CAnotherGameBoard::DeleteBoard(void)
{
	if (m_arrBoard != NULL)
	{
		for (int row = 0; row < m_nRows; row++)
		{
			if (m_arrBoard[row] != NULL)
			{
				// Сначала удаляем каждую отдельную строку
				delete[] m_arrBoard[row];
				m_arrBoard[row] = NULL;
			}
		}
		// В конце удаляем массив, содержащий строки
		delete[] m_arrBoard;
		m_arrBoard = NULL;
	}
}

void CAnotherGameBoard::CreateBoard(void)
{
	// Если у нас осталась доска с предыдущего раза, то удаляем её  
	if (m_arrBoard != NULL)
		DeleteBoard();

	// Создаём массив для хранения строк
	m_arrBoard = new int* [m_nRows];

	// Создаём отдельно каждую строку
	for (int row = 0; row < m_nRows; row++)
	{
		m_arrBoard[row] = new int[m_nColumns];

		// Устанавливаем для каждого блока значение цвета равное цвету фона
		for (int col = 0; col < m_nColumns; col++)
			m_arrBoard[row][col] = 0;
	}
}