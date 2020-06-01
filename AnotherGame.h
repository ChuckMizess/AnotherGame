
// AnotherGame.h : main header file for the AnotherGame application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CAnotherGameApp:
// See AnotherGame.cpp for the implementation of this class
//

class CAnotherGameApp : public CWinApp
{
public:
	CAnotherGameApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAnotherGameApp theApp;
