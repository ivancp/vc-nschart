// NSChartDemo.h : main header file for the NSCHARTDEMO application
//

#if !defined(AFX_NSCHARTDEMO_H__26CDBEC5_DE1F_11D8_9FE8_000021F2B5E0__INCLUDED_)
#define AFX_NSCHARTDEMO_H__26CDBEC5_DE1F_11D8_9FE8_000021F2B5E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNSChartDemoApp:
// See NSChartDemo.cpp for the implementation of this class
//

class CNSChartDemoApp : public CWinApp
{
public:
	CNSChartDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNSChartDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNSChartDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NSCHARTDEMO_H__26CDBEC5_DE1F_11D8_9FE8_000021F2B5E0__INCLUDED_)
