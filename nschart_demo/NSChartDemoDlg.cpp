// NSChartDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NSChartDemo.h"
#include "NSChartDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNSChartDemoDlg dialog

CNSChartDemoDlg::CNSChartDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNSChartDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNSChartDemoDlg)
	m_dValue = 0.0;
	m_sLabel = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_iItem = -1;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNSChartDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNSChartDemoDlg)
	DDX_Text(pDX, IDC_VALUE, m_dValue);
	DDX_Text(pDX, IDC_LABEL, m_sLabel);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNSChartDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CNSChartDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, OnRadioButtons)
	ON_BN_CLICKED(IDC_RADIO3, OnRadioColors)
	ON_BN_CLICKED(IDC_CUSTOM1, OnAdd)
	ON_NOTIFY(NSCS_SELECTEDITEM, IDC_CUSTOM1, OnChartSelectedItem)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_RADIO2, OnRadioButtons)
	ON_BN_CLICKED(IDC_RADIO4, OnRadioColors)
	ON_BN_CLICKED(IDC_RADIO5, OnRadioColors)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
	ON_UPDATE_COMMAND_UI(IDC_MODIFY,OnUpdateModify)
	ON_UPDATE_COMMAND_UI(IDC_DEL,OnUpdateModify)
	ON_UPDATE_COMMAND_UI(IDC_ADD,OnUpdateAdd)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNSChartDemoDlg message handlers

BOOL CNSChartDemoDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

	//Subclassing

	m_chart.SubclassDlgItem(IDC_CUSTOM1,this);


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_chart.PrepareColors(CNSChartCtrl::SimpleColors);
	m_chart.AddValue(10,"One");
	m_chart.AddValue(20,"Two");
	m_chart.AddValue(40,"Three");
	m_chart.AddValue(30,"Four");
	

	CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	CheckRadioButton(IDC_RADIO3,IDC_RADIO5,IDC_RADIO4);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNSChartDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNSChartDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNSChartDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNSChartDemoDlg::OnRadioButtons() 
{
	int state = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2);
	
	if(state == IDC_RADIO1)
	{
		m_chart.SetChartStyle(NSCS_PIE);
	}
	else
	{
		m_chart.SetChartStyle(NSCS_BAR);
	}		
}

void CNSChartDemoDlg::OnRadioColors() 
{
	int state = GetCheckedRadioButton(IDC_RADIO3,IDC_RADIO5);
	
	switch(state){
		case IDC_RADIO3:
			m_chart.PrepareColors(CNSChartCtrl::GrayScale);
			break;
		case IDC_RADIO4:
			m_chart.PrepareColors(CNSChartCtrl::SimpleColors);
			break;
		case IDC_RADIO5:
			m_chart.ResetColors();
			m_chart.AddBrush(new CBrush(HS_BDIAGONAL,0x0));
			m_chart.AddBrush(new CBrush(HS_HORIZONTAL,0x0));
			m_chart.AddBrush(new CBrush(HS_VERTICAL,0x0));
			m_chart.AddBrush(new CBrush(HS_CROSS,0x0));
			m_chart.AddBrush(new CBrush(HS_DIAGCROSS,0x0));
			m_chart.AddBrush(new CBrush(HS_FDIAGONAL,0x0));
			break;
	}
	m_chart.Invalidate(FALSE);
}



void CNSChartDemoDlg::OnAdd() 
{
	if(m_iItem < 0)
	{
		UpdateData();
		if(m_dValue > 0.0 && !m_sLabel.IsEmpty())
		{
			m_chart.AddValue(m_dValue,m_sLabel,TRUE);
			m_iItem = -1;
			m_dValue = 0.0;
			m_sLabel = "";
			UpdateData(FALSE);
		}
	}
	UpdateDialogControls(this,FALSE);
}

void CNSChartDemoDlg::OnChartSelectedItem(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCHARTCTRL nmchart = (LPNMCHARTCTRL)pNMHDR;
	
	m_iItem = nmchart->iItem;

	if(m_iItem >= 0)
	{
		m_dValue = nmchart->dValue;
		m_sLabel = nmchart->sLabel;
	}else
	{
		m_dValue = 0;
		m_sLabel = "";
	}
	UpdateData(FALSE);
	UpdateDialogControls(this,FALSE);
	*pResult = FALSE;
}


void CNSChartDemoDlg::OnDel() 
{
	if(m_chart.DeleteItem(m_iItem))
	{
		m_dValue = 0;
		m_sLabel = "";
		m_iItem  = -1;
		UpdateData(FALSE);
		UpdateDialogControls(this,FALSE);
	}
}

void CNSChartDemoDlg::OnModify() 
{
	UpdateData();
	if(m_dValue > 0.0 && !m_sLabel.IsEmpty())
	{
		m_chart.ModifyItem(m_iItem,m_dValue,m_sLabel);
	}
}
void CNSChartDemoDlg::OnUpdateModify(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_iItem>=0);
}


void CNSChartDemoDlg::OnUpdateAdd(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_iItem < 0);
}
