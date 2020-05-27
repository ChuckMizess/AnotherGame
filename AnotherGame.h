
// AnotherGame.h: основной файл заголовка для приложения AnotherGame
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CAnotherGameApp:
// Сведения о реализации этого класса: AnotherGame.cpp
//

class CAnotherGameApp : public CWinApp
{
public:
	CAnotherGameApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAnotherGameApp theApp;
