// NSChartDemoDlg.h : header file
//

#if !defined(AFX_NSCHARTDEMODLG_H__26CDBEC7_DE1F_11D8_9FE8_000021F2B5E0__INCLUDED_)
#define AFX_NSCHARTDEMODLG_H__26CDBEC7_DE1F_11D8_9FE8_000021F2B5E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NSChartCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CNSChartDemoDlg dialog

class CNSChartDemoDlg : public CDialog
{
// Construction
public:
	CNSChartDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNSChartDemoDlg)
	enum { IDD = IDD_NSCHARTDEMO_DIALOG };
	double	m_dValue;
	CString	m_sLabel;
	//}}AFX_DATA

	CNSChartCtrl m_chart;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNSChartDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	INT m_iItem;
	HICON m_hIcon;
	void OnUpdateModify(CCmdUI* pCmdUI);
	void OnUpdateAdd(CCmdUI* pCmdUI);
	// Generated message map functions
	//{{AFX_MSG(CNSChartDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadioButtons();
	afx_msg void OnRadioColors();
	afx_msg void OnAdd();
	afx_msg void OnChartSelectedItem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDel();
	afx_msg void OnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NSCHARTDEMODLG_H__26CDBEC7_DE1F_11D8_9FE8_000021F2B5E0__INCLUDED_)
