
// cal_graphyDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "cal_graphy.h"
#include "cal_graphyDlg.h"
#include "afxdialogex.h"
#include"experiment_2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalgraphyDlg 对话框



CcalgraphyDlg::CcalgraphyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CAL_GRAPHY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalgraphyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combox1);
	DDX_Control(pDX, IDC_EDIT4, x3);
	DDX_Control(pDX, IDC_EDIT2, x1);
	DDX_Control(pDX, IDC_EDIT6, y1);
	DDX_Control(pDX, IDC_EDIT3, x2);
	DDX_Control(pDX, IDC_EDIT7, y2);
	DDX_Control(pDX, IDC_EDIT8, y3);
	DDX_Control(pDX, IDC_EDIT5, x4);
	DDX_Control(pDX, IDC_EDIT9, y4);
	DDX_Control(pDX, IDC_EDIT1, show_result);
	DDX_Control(pDX, IDC_COMBO3, combox3);
}

BEGIN_MESSAGE_MAP(CcalgraphyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CcalgraphyDlg::OnCbnSelchangeCombo1)
	ON_LBN_SELCHANGE(IDC_LIST4, &CcalgraphyDlg::OnLbnSelchangeList4)
	ON_EN_CHANGE(IDC_EDIT2, &CcalgraphyDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT8, &CcalgraphyDlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, &CcalgraphyDlg::OnEnChangeEdit9)

	ON_BN_CLICKED(IDC_BUTTON3, &CcalgraphyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalgraphyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalgraphyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalgraphyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalgraphyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalgraphyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalgraphyDlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CcalgraphyDlg::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// CcalgraphyDlg 消息处理程序

BOOL CcalgraphyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	combox1.InsertString(0,_T("线段"));
	combox1.InsertString(1,_T("平行四边形"));
	combox1.InsertString(2,_T("圆"));
	combox1.InsertString(3,_T("圆弧"));
	combox3.InsertString(0, _T("厘米"));
	combox3.InsertString(1, _T("毫米"));
	combox3.InsertString(2, _T("米"));
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalgraphyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalgraphyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalgraphyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalgraphyDlg::OnCbnSelchangeCombo1()
{
	int n1;
	n1 = combox1.GetCurSel();
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_P1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_P2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_P3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_P4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON8)->ShowWindow(SW_HIDE);
	x1.SetWindowTextW(_T(""));
	x2.SetWindowTextW(_T(""));
	x3.SetWindowTextW(_T(""));
	x4.SetWindowTextW(_T(""));
	y1.SetWindowTextW(_T(""));
	y2.SetWindowTextW(_T(""));
	y3.SetWindowTextW(_T(""));
	y4.SetWindowTextW(_T(""));
	if (n1 == 0)
	{
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_P1, _T("第一个点："));
		SetDlgItemText(IDC_P2, _T("第二个点："));
		SetDlgItemText(IDC_BUTTON1, _T("长度"));
	}
	else if (n1 == 1)
	{
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_P1, _T("第一个点："));
		SetDlgItemText(IDC_P2, _T("第二个点："));
		SetDlgItemText(IDC_P3, _T("第三个点："));
		SetDlgItemText(IDC_P4, _T("第四个点："));
		SetDlgItemText(IDC_BUTTON1, _T("面积"));
		SetDlgItemText(IDC_BUTTON8, _T("周长"));
	}
	else if (n1 == 2)
	{
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_P1, _T("第一个点："));
		SetDlgItemText(IDC_P2, _T("半径："));
		SetDlgItemText(IDC_BUTTON1, _T("面积"));
		SetDlgItemText(IDC_BUTTON8, _T("周长"));

	}
	else if (n1 == 3)
	{
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_P3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON8)->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_P1, _T("第一个点："));
		SetDlgItemText(IDC_P2, _T("半径："));
		SetDlgItemText(IDC_P3, _T("角度："));
		SetDlgItemText(IDC_BUTTON1, _T("面积"));
		SetDlgItemText(IDC_BUTTON8, _T("周长"));


	}
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnLbnSelchangeList4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CcalgraphyDlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void CcalgraphyDlg::OnBnClickedButton3()
{
	
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}




void CcalgraphyDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnBnClickedButton7()
{
	if (MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_DEFBUTTON2) == IDYES)
	{
		exit(0);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
}
