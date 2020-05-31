
// cal_graphyDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "cal_graphy.h"
#include "cal_graphyDlg.h"
#include "afxdialogex.h"
#include"experiment_2.h"
#include"inputbox.h"
#include<fstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
double x11=0;
double x22=0;
double x33=0;
double x44=0;
double y11=0;
double y22=0;
double y33=0;
double y44=0;
double height = 0;
double x55 = 0;
double y55 = 0;
double x66 = 0;
double y66 = 0;
double x77 = 0;
double y77 = 0;
double x88 = 0;
double y88 = 0;
double r1 = 0;
double arc = 0;
CString X1=_T("");
CString Y1=_T("");
CString X2=_T("");
CString Y2=_T("");
CString X3 = _T("");
CString Y3 = _T("");
CString X4 = _T("");
CString Y4 = _T("");
CString X5 = _T("");
CString Y5 = _T("");
CString X6 = _T("");
CString Y6 = _T("");
CString X7 = _T("");
CString Y7 = _T("");
CString X8 = _T("");
CString Y8 = _T("");
CString X9 = _T("");
CString unit1=_T("");
int n1;
int n2;
int n3;
inputbox box1;
CString filename = _T("");
CString result = _T("");
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
	DDX_Control(pDX, IDC_EDIT4, x_3);
	DDX_Control(pDX, IDC_EDIT2, x_1);
	DDX_Control(pDX, IDC_EDIT6, y_1);
	DDX_Control(pDX, IDC_EDIT3, x_2);
	DDX_Control(pDX, IDC_EDIT7, y_2);
	DDX_Control(pDX, IDC_EDIT8, y_3);
	DDX_Control(pDX, IDC_EDIT5, x_4);
	DDX_Control(pDX, IDC_EDIT9, y_4);
	DDX_Control(pDX, IDC_EDIT1, show_result);
	DDX_Control(pDX, IDC_COMBO3, combox3);
	DDX_Control(pDX, IDC_COMBO2, combox2);
	DDX_Control(pDX, IDC_EDIT10, x_5);
	DDX_Control(pDX, IDC_EDIT11, y_5);
	DDX_Control(pDX, IDC_EDIT12, x_6);
	DDX_Control(pDX, IDC_EDIT13, y_6);
	DDX_Control(pDX, IDC_EDIT14, x_7);
	DDX_Control(pDX, IDC_EDIT15, y_7);
	DDX_Control(pDX, IDC_EDIT16, x_8);
	DDX_Control(pDX, IDC_EDIT17, y_8);
	DDX_Control(pDX, IDC_EDIT18, x_9);
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

	
	ON_BN_CLICKED(IDC_BUTTON1, &CcalgraphyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalgraphyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalgraphyDlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CcalgraphyDlg::OnCbnSelchangeCombo3)
	ON_EN_CHANGE(IDC_EDIT1, &CcalgraphyDlg::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_P1, &CcalgraphyDlg::OnStnClickedP1)
	ON_STN_CLICKED(IDC_P5, &CcalgraphyDlg::OnStnClickedP5)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
	ON_STN_CLICKED(IDC_P3, &CcalgraphyDlg::OnStnClickedP3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CcalgraphyDlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT14, &CcalgraphyDlg::OnEnChangeEdit14)
	ON_EN_CHANGE(IDC_EDIT16, &CcalgraphyDlg::OnEnChangeEdit16)
	ON_EN_CHANGE(IDC_EDIT7, &CcalgraphyDlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalgraphyDlg::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CcalgraphyDlg::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()


// CcalgraphyDlg 消息处理程序

BOOL CcalgraphyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX< 0xF000);

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
	
	combox3.InsertString(0, _T("厘米"));
	combox3.InsertString(1, _T("毫米"));
	combox3.InsertString(2, _T("米"));
	combox2.InsertString(0, _T("二维"));
	combox2.InsertString(1, _T("三维"));

	//
	CString strBmpPath = _T(".\\res\\back.png");

	CImage img;

	img.Load(strBmpPath);

	MoveWindow(0, 0, img.GetWidth(), img.GetHeight());

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_bkBrush.CreatePatternBrush(&bmpTmp);
	//
	CRgn rgnTmp;
	RECT rc;
	GetClientRect(&rc);
	rgnTmp.CreateRoundRectRgn(rc.left + 3, rc.top + 3, rc.right - rc.left - 3, rc.bottom - rc.top - 3, 6, 6);
	SetWindowRgn(rgnTmp, TRUE);


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
	n1=combox1.GetCurSel();
	n3 = combox2.GetCurSel();
	if (n3 == 0)
	{
		ShowHide(0, 0, 0, 0, 0, 0, 0, 0);
		ShowHide1(0, 0, 0, 0, 0);
		x_1.SetWindowTextW(_T(""));
		x_2.SetWindowTextW(_T(""));
		x_3.SetWindowTextW(_T(""));
		x_4.SetWindowTextW(_T(""));
		y_1.SetWindowTextW(_T(""));
		y_2.SetWindowTextW(_T(""));
		y_3.SetWindowTextW(_T(""));
		y_4.SetWindowTextW(_T(""));
		SetDlgItemText(IDC_EDIT1, _T(""));
		SetDlgItemText(IDC_P5, _T("注意事项：\n要输入两位小数的数字"));
		switch (n1)
		{
		case 0:
			ShowHide(5, 5, 0, 0, 0, 0, 5, 0);
			SetDlgItemText(IDC_P1, _T("第一个点："));
			SetDlgItemText(IDC_P2, _T("第二个点："));
			SetDlgItemText(IDC_BUTTON1, _T("长度"));
			break;
		case 1:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			SetDlgItemText(IDC_P1, _T("第一个点："));
			SetDlgItemText(IDC_P2, _T("第二个点："));
			SetDlgItemText(IDC_P3, _T("第三个点："));
			SetDlgItemText(IDC_P4, _T("第四个点："));
			SetDlgItemText(IDC_BUTTON1, _T("面积"));
			SetDlgItemText(IDC_BUTTON8, _T("周长"));
			SetDlgItemText(IDC_P5, _T("注意事项:\n1.请输入两位小数的数字\n2.请按顺时针输入平行四边形坐标"));
			break;
		case 2:
			ShowHide(5, 0, 0, 0, 0, 0, 5, 5);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
			SetDlgItemText(IDC_P1, _T("圆心："));
			SetDlgItemText(IDC_P2, _T("半径："));
			SetDlgItemText(IDC_BUTTON1, _T("面积"));
			SetDlgItemText(IDC_BUTTON8, _T("周长"));
			break;
		case 3:
			ShowHide(5, 0, 0, 0, 0, 0, 5, 5);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P3)->ShowWindow(SW_SHOW);
			SetDlgItemText(IDC_P1, _T("圆心："));
			SetDlgItemText(IDC_P2, _T("半径："));
			SetDlgItemText(IDC_P3, _T("角度："));
			SetDlgItemText(IDC_BUTTON1, _T("面积"));
			SetDlgItemText(IDC_BUTTON8, _T("周长"));
			SetDlgItemText(IDC_P5, _T("注意事项：\n1.要输入两位小数的数字\n2.角度的单位为角度制"));
			break;
		}
	}
	else if (n3 == 1)
	{
		ShowHide(0, 0, 0, 0, 0, 0, 0, 0);
		ShowHide1(0, 0, 0, 0, 0);
		x_1.SetWindowTextW(_T(""));
		x_2.SetWindowTextW(_T(""));
		x_3.SetWindowTextW(_T(""));
		x_4.SetWindowTextW(_T(""));
		y_1.SetWindowTextW(_T(""));
		y_2.SetWindowTextW(_T(""));
		y_3.SetWindowTextW(_T(""));
		y_4.SetWindowTextW(_T(""));
		x_5.SetWindowTextW(_T(""));
		x_6.SetWindowTextW(_T(""));
		x_7.SetWindowTextW(_T(""));
		x_8.SetWindowTextW(_T(""));
		x_9.SetWindowTextW(_T(""));
		y_5.SetWindowTextW(_T(""));
		y_6.SetWindowTextW(_T(""));
		y_7.SetWindowTextW(_T(""));
		y_8.SetWindowTextW(_T(""));
		SetDlgItemText(IDC_EDIT1, _T(""));
		SetDlgItemText(IDC_P5, _T("注意事项：\n要输入两位小数的数字"));
		switch (n1)
		{
		case 0:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			ShowHide1(0, 0, 0, 0, 0);
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_P1, _T("第一个点"));
			SetDlgItemText(IDC_P2, _T("第二个点"));
			SetDlgItemText(IDC_P3, _T("第三个点"));
			SetDlgItemText(IDC_P4, _T("高"));
			GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
			break;
		case 1:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			ShowHide1(5, 0, 0, 0, 0);
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_P1, _T("第一个点"));
			SetDlgItemText(IDC_P2, _T("第二个点"));
			SetDlgItemText(IDC_P3, _T("第三个点"));
			SetDlgItemText(IDC_P4, _T("顶点"));
			SetDlgItemText(IDC_P6, _T("高"));
			GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
			break;
		case 2:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			ShowHide1(5, 0, 0, 0, 0);
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_P1, _T("第一个点"));
			SetDlgItemText(IDC_P2, _T("第二个点"));
			SetDlgItemText(IDC_P3, _T("第三个点"));
			SetDlgItemText(IDC_P4, _T("第四个点"));
			SetDlgItemText(IDC_P6, _T("高"));
			GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
			SetDlgItemText(IDC_P5, _T("注意事项:\n1.请输入两位小数的数字\n2.请按顺时针输入四边形坐标"));
			break;
		case 3:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			ShowHide1(5, 5, 0, 0, 0);
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_P1, _T("第一个点"));
			SetDlgItemText(IDC_P2, _T("第二个点"));
			SetDlgItemText(IDC_P3, _T("第三个点"));
			SetDlgItemText(IDC_P4, _T("第四个点"));
			SetDlgItemText(IDC_P6, _T("顶点"));
			SetDlgItemText(IDC_P7, _T("高"));
			GetDlgItem(IDC_EDIT13)->ShowWindow(SW_HIDE);
			SetDlgItemText(IDC_P5, _T("注意事项:\n1.请输入两位小数的数字\n2.请按顺时针输入四边形坐标"));
			break;
		case 4:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			ShowHide1(5, 5, 5, 0, 0);
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_P1, _T("底面第一个点"));
			SetDlgItemText(IDC_P2, _T("底面第二个点"));
			SetDlgItemText(IDC_P3, _T("底面第三个点"));
			SetDlgItemText(IDC_P4, _T("顶面第一个点"));
			SetDlgItemText(IDC_P6, _T("顶面第二个点"));
			SetDlgItemText(IDC_P7, _T("顶面第三个点"));
			SetDlgItemText(IDC_P8, _T("高"));
			GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
			SetDlgItemText(IDC_P5, _T("注意事项:\n1.请输入两位小数的数字\n2.请对应输入顶面与地面的坐标"));
			break;
		case 5:
			ShowHide(5, 5, 5, 5, 5, 5, 5, 5);
			ShowHide1(5, 5, 5, 5, 5);
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_P1, _T("底面第一个点"));
			SetDlgItemText(IDC_P2, _T("底面第二个点"));
			SetDlgItemText(IDC_P3, _T("底面第三个点"));
			SetDlgItemText(IDC_P4, _T("底面第四个点"));
			SetDlgItemText(IDC_P6, _T("顶面第一个点"));
			SetDlgItemText(IDC_P7, _T("顶面第二个点"));
			SetDlgItemText(IDC_P8, _T("顶面第三个点"));
			SetDlgItemText(IDC_P9, _T("顶面第四个点"));
			SetDlgItemText(IDC_P10, _T("高"));
			SetDlgItemText(IDC_P5, _T("注意事项:\n1.请输入两位小数的数字\n2.请按顺时针输入四边形坐标\n3.请对应输入顶面与底面坐标"));
			break;
		case 6:
			ShowHide(5, 0, 0, 0, 0, 0, 5, 5);
			ShowHide1(0, 0, 0, 0, 0);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
			SetDlgItemText(IDC_P1, _T("圆心"));
			SetDlgItemText(IDC_P2, _T("半径"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_P5, _T("注意事项：\n1.要输入两位小数的数字\n2.角度的单位为角度制"));
			break;
		case 7:
			ShowHide(5, 0, 0, 0, 0, 0, 5, 5);
			ShowHide1(0, 0, 0, 0, 0);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
			SetDlgItemText(IDC_P3, _T("高"));
			SetDlgItemText(IDC_P1, _T("圆心"));
			SetDlgItemText(IDC_P2, _T("半径"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_P5, _T("注意事项：\n1.要输入两位小数的数字\n2.角度的单位为角度制"));
			break;
		case 8:
			ShowHide(5,0,0,0,0,0,5,5);
			ShowHide1(0, 0, 0, 0, 0);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
			SetDlgItemText(IDC_P3, _T("高"));
			SetDlgItemText(IDC_P1, _T("圆心"));
			SetDlgItemText(IDC_P2, _T("半径"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_P5, _T("注意事项：\n1.要输入两位小数的数字\n2.角度的单位为角度制"));
			break;
		case 9:
			ShowHide(5, 5, 0, 0, 0, 0, 5, 5);
			ShowHide1(0, 0, 0, 0, 0);
			GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P4)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P3)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_P6)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
			SetDlgItemText(IDC_P3, _T("底圆半径"));
			SetDlgItemText(IDC_P1, _T("底圆圆心"));
			SetDlgItemText(IDC_P2, _T("顶圆圆心"));
			SetDlgItemText(IDC_P4, _T("顶圆半径"));
			SetDlgItemText(IDC_P6, _T("高"));
			SetDlgItemText(IDC_BUTTON1, _T("体积"));
			SetDlgItemText(IDC_BUTTON8, _T("面积"));
			SetDlgItemText(IDC_P5, _T("注意事项：\n1.要输入两位小数的数字\n2.角度的单位为角度制"));
			break;

		}

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

void CcalgraphyDlg::OnBnClickedButton1()
{
	CString result = _T("");
	if (n3 == 0)
	{
		switch (n1)
		{
		case 0:
			x_1.GetWindowTextW(X1);
			x_2.GetWindowTextW(X2);
			y_1.GetWindowTextW(Y1);
			y_2.GetWindowTextW(Y2);
			if (X1 == _T("") || Y1 == _T("") || X2 == _T("") || Y2 == _T(""))
			{
				MessageBox(_T("请完整输入坐标内容"), _T("警告"), MB_OK);
				show_result.SetWindowTextW(_T(""));
			}
			else if (judgenum(X1) && judgenum(X2) && judgenum(Y1) && judgenum(Y2))
			{
				x11 = _ttof(X1);
				x22 = _ttof(X2);
				y11 = _ttof(Y1);
				y22 = _ttof(Y2);
				line lin1(x11, y11, x22, y22);
				switch (n2)
				{
				case 0:
					unit1 = "厘米";
					break;
				case 1:
					unit1 = "毫米";
					break;
				case 2:
					unit1 = "米";
					break;

				}
				result.Format(_T("线段长度为%f%s"), lin1.length(), unit1);
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;
		case 1:
			x_1.GetWindowTextW(X1);
			x_2.GetWindowTextW(X2);
			y_1.GetWindowTextW(Y1);
			y_2.GetWindowTextW(Y2);
			x_3.GetWindowTextW(X3);
			y_3.GetWindowTextW(Y3);
			x_4.GetWindowTextW(X4);
			y_4.GetWindowTextW(Y4);
			if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T(""))
			{
				MessageBox(_T("请完整输入坐标内容"), _T("警告"), MB_OK);
			}
			else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4))
			{
				x11 = _ttof(X1);
				x22 = _ttof(X2);
				y11 = _ttof(Y1);
				y22 = _ttof(Y2);
				x33 = _ttof(X3);
				y33 = _ttof(Y3);
				x44 = _ttof(X4);
				y44 = _ttof(Y4);
				parallelogram pall(x11, y11, x22, y22, x33, y33, x44, y44);
				if (pall.judge4())
				{
					switch (n2)
					{
					case 0:
						unit1 = "平方厘米";
						break;
					case 1:
						unit1 = "平方毫米";
						break;
					case 2:
						unit1 = "平方米";
						break;
					}
					result.Format(_T("平行四边形面积为%f%s"), pall.area(), unit1);
					SetDlgItemText(IDC_EDIT1, result);
				}
				else
				{
					MessageBox(_T("你输入的坐标构不成平行四边形"), _T("警告"), MB_OK);
				}
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;
		case 2:
			x_1.GetWindowTextW(X1);
			y_1.GetWindowTextW(Y1);
			x_2.GetWindowTextW(X2);
			if (X1 == _T("") || X2 == _T("") || Y1 == _T(""))
			{
				MessageBox(_T("请完整输入该输入的内容"), _T("警告"), MB_OK);
			}
			else if (judgenum(X1) && judgenum(Y1) && judgenum(X2))
			{
				x11 = _ttof(X1);
				y11 = _ttof(Y1);
				r1 = _ttof(X2);
				Circle cir1(x11, y11, r1);
				switch (n2)
				{
				case 0:
					unit1 = "平方厘米";
					break;
				case 1:
					unit1 = "平方毫米";
					break;
				case 2:
					unit1 = "平方米";
					break;
				}
				result.Format(_T("圆的面积为%f%s"), cir1.area(), unit1);
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;
		case 3:
			x_1.GetWindowTextW(X1);
			y_1.GetWindowTextW(Y1);
			x_2.GetWindowTextW(X2);
			x_3.GetWindowTextW(X3);
			if (X1 == _T("") || X2 == _T("") || X3 == _T("") || Y1 == _T(""))
			{
				MessageBox(_T("请完整输入该输入的内容"), MB_OK);
			}
			else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(Y1))
			{
				x11 = _ttof(X1);
				y11 = _ttof(Y1);
				r1 = _ttof(X2);
				arc = _ttof(X3);
				Angle A1(x11, y11, r1, arc);
				switch (n2)
				{
				case 0:
					unit1 = "平方厘米";
					break;
				case 1:
					unit1 = "平方毫米";
					break;
				case 2:
					unit1 = "平方米";
					break;
				}
				result.Format(_T("圆弧面积为%f%s"), A1.area(), unit1);
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;
		}
	}
	else if (n3 == 1)

	{
	switch (n1)
	{
	case 0:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			height = _ttof(X4);
			triangular_prism tri_prism(x11, y11, x22, y22, x33, y33, height);
			if (tri_prism.judge1())
			{
				result.Format(_T("三棱柱的体积为%f%s"), tri_prism.volume(),volume_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你输入的坐标构不成三角形"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 1:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			x44 = _ttof(X4);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			y44 = _ttof(Y4);
			height = _ttof(X5);
			triangular_pyramid tri_pyramid(x11, y11, x22, y22, x33, y33, height, x44, y44);
			if (tri_pyramid.judge1())
			{
				result.Format(_T("三棱锥的体积为%f%s"), tri_pyramid.volume(),volume_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你输入的坐标构不成三角形"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 2:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			x44 = _ttof(X4);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			y44 = _ttof(Y4);
			height = _ttof(X5);
			quadrangular quad(x11, y11, x22, y22, x33, y33, x44, y44, height);
			result.Format(_T("四棱柱的体积为%f%s"), quad.volume(),volume_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 3:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		y_5.GetWindowTextW(Y5);
		x_6.GetWindowTextW(X6);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T("") || Y5 == _T("") || X6 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4) && judgenum(Y5) && judgenum(X6))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			x22 = _ttof(X2);
			y22 = _ttof(Y2);
			x33 = _ttof(X3);
			y33 = _ttof(Y3);
			x44 = _ttof(X4);
			y44 = _ttof(Y4);
			x55 = _ttof(X5);
			y55 = _ttof(Y5);
			height = _ttof(X6);
			rectangular_pyramid rec_pyramid(x11, y11, x22, y22, x33, y33, x44, y44, height, x55, y55);
			result.Format(_T("四棱锥的体积为%f%s"), rec_pyramid.volume(), volume_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 4:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		y_5.GetWindowTextW(Y5);
		x_6.GetWindowTextW(X6);
		y_6.GetWindowTextW(Y6);
		x_7.GetWindowTextW(X7);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T("") || X6 == _T("") || Y6 == _T("") || X7 == _T("") || Y5 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4) && judgenum(Y5) && judgenum(X6) && judgenum(Y6) && judgenum(X7))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			x44 = _ttof(X4);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			y44 = _ttof(Y4);
			x55 = _ttof(X5);
			y55 = _ttof(Y5);
			x66 = _ttof(X6);
			y66 = _ttof(Y6);
			height = _ttof(X7);
			Three_prism thr_prism(x11, y11, x22, y22, x33, y33, height, x44, y44, x55, y55, x66, y66);
			if (thr_prism.judge2())
			{
				result.Format(_T("三棱台的体积为%f%s"), thr_prism.volume(),volume_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你输入的信息构不成三棱台"), _T("警告"), MB_OK);
			}
		}
		break;
	case 5:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		y_5.GetWindowTextW(Y5);
		x_6.GetWindowTextW(X6);
		y_6.GetWindowTextW(Y6);
		x_7.GetWindowTextW(X7);
		y_7.GetWindowTextW(Y7);
		x_8.GetWindowTextW(X8);
		y_8.GetWindowTextW(Y8);
		x_9.GetWindowTextW(X9);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T("") || X6 == _T("") || Y6 == _T("") || X7 == _T("") || Y5 == _T("") || Y8 == _T("") || Y7 == _T("") || X8 == _T("") || X9 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(X6) && judgenum(X7) && judgenum(X8) && judgenum(X9) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4) && judgenum(Y5) && judgenum(Y6) && judgenum(Y7) && judgenum(Y8))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			x22 = _ttof(X2);
			y22 = _ttof(Y2);
			x33 = _ttof(X3);
			y33 = _ttof(Y3);
			x44 = _ttof(X4);
			y44 = _ttof(Y4);
			x55 = _ttof(X5);
			y55 = _ttof(Y5);
			x66 = _ttof(X6);
			y66 = _ttof(Y6);
			x77 = _ttof(X7);
			y77 = _ttof(Y7);
			x88 = _ttof(X8);
			y88 = _ttof(Y8);
			height = _ttof(X9);
			quadrangular_frustum_pyramid quad_frust_pyramid(x11, y11, x22, y22, x33, y33, x44, y44, x55, y55, x66, y66, x77, y77, x88, y88, height);
			if (quad_frust_pyramid.judge3())
			{
				result.Format(_T("四棱台体积为%f%s"), quad_frust_pyramid.volume(), volume_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你所输入的数据构不成四棱台"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 6:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		if (X1 == _T("") || Y1 == _T("") || X2 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			ball Ball1(x11, y11, r1);
			result.Format(_T("球的体积为%f%s"), Ball1.volume(), volume_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 7:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		x_3.GetWindowTextW(X3);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || Y1 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			height = _ttof(X3);
			cylinder cylin1(x11, y11, r1, height);
			result.Format(_T("圆柱的体积为%f%s"), cylin1.volume(), volume_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 8:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		x_3.GetWindowTextW(X3);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || Y1 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			height = _ttof(X3);
			cone con1(x11, y11, r1, height);
			result.Format(_T("圆柱的面积为%f%s"), con1.volume(), volume_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 9:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		x_4.GetWindowTextW(X4);
		x_5.GetWindowTextW(X5);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || Y1 == _T("") || Y2 == _T("") || X5 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(Y1) && judgenum(Y2) && judgenum(X5))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			x22 = _ttof(X2);
			y22 = _ttof(Y2);
			r1 = _ttof(X3);
			x44 = _ttof(X4);
			height = _ttof(X5);
			circular_truncated_cone cir_trun_con1(x11, y11, r1, height, x22, y22, x44);
			if (x11==x22&&y11==y22)
			{
				result.Format(_T("圆台的体积为%f%s"), cir_trun_con1.volume(), volume_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("所输入的信息构不成圆台"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	}
	}

	// TODO: 在此添加控件通知处理程序代码
}




void CcalgraphyDlg::OnBnClickedButton8()
{
	CString result = _T("");
	if (n3 == 0)
	{
		switch (n1)
		{
		case 1:
			x_1.GetWindowTextW(X1);
			x_2.GetWindowTextW(X2);
			y_1.GetWindowTextW(Y1);
			y_2.GetWindowTextW(Y2);
			x_3.GetWindowTextW(X3);
			y_3.GetWindowTextW(Y3);
			x_4.GetWindowTextW(X4);
			y_4.GetWindowTextW(Y4);
			if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T(""))
			{
				MessageBox(_T("请完整输入坐标内容"), _T("警告"), MB_OK);
			}
			else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4))
			{
				x11 = _ttof(X1);
				x22 = _ttof(X2);
				y11 = _ttof(Y1);
				y22 = _ttof(Y2);
				x33 = _ttof(X3);
				y33 = _ttof(Y3);
				x44 = _ttof(X4);
				y44 = _ttof(Y4);
				parallelogram pall(x11, y11, x22, y22, x33, y33, x44, y44);
				if (pall.judge4())
				{
					result.Format(_T("平行四边形周长为%f%s"), pall.length(), length_unit(n2));
					SetDlgItemText(IDC_EDIT1, result);
				}
				else
				{
					MessageBox(_T("你输入的坐标构不成平行四边形"), _T("警告"), MB_OK);
				}
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;

		case 2:
			x_1.GetWindowTextW(X1);
			y_1.GetWindowTextW(Y1);
			x_2.GetWindowTextW(X2);
			if (X1 == _T("") || X2 == _T("") || Y1 == _T(""))
			{
				MessageBox(_T("请完整输入该输入的内容"), _T("警告"), MB_OK);
			}
			else if (judgenum(X1) && judgenum(Y1) && judgenum(X1))
			{
				x11 = _ttof(X1);
				y11 = _ttof(Y1);
				r1 = _ttof(X2);
				Circle cir1(x11, y11, r1);
				result.Format(_T("圆的周长为%f%s"), cir1.length(),length_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;

		case 3:
			x_1.GetWindowTextW(X1);
			y_1.GetWindowTextW(Y1);
			x_2.GetWindowTextW(X2);
			x_3.GetWindowTextW(X3);
			if (X1 == _T("") || X2 == _T("") || X3 == _T("") || Y1 == _T(""))
			{
				MessageBox(_T("请完整输入该输入的内容"),_T("警告"), MB_OK);
			}
			else if (judgenum(X1) && judgenum(Y1) && judgenum(X2) && judgenum(X3))
			{
				x11 = _ttof(X1);
				y11 = _ttof(Y1);
				r1 = _ttof(X2);
				arc = _ttof(X3);
				Angle A1(x11, y11, r1, arc);
				result.Format(_T("圆弧周长为%f%s"), A1.length(),length_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
				MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
			break;
		}
	}
	else if (n3 == 1)
	{
	switch (n1)
	{
	case 0:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			height = _ttof(X4);
			triangular_prism tri_prism(x11, y11, x22, y22, x33, y33, height);
			if (tri_prism.judge1())
			{
				result.Format(_T("三棱柱的面积为%f%s"), tri_prism.area(),area_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你输入的坐标构不成三角形"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 1:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T(""))
		{	
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			x44 = _ttof(X4);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			y44 = _ttof(Y4);
			height = _ttof(X5);
			triangular_pyramid tri_pyramid(x11, y11, x22, y22, x33, y33, height, x44, y44);
			if (tri_pyramid.judge1())
			{
				result.Format(_T("三棱锥的面积为%f%s"), tri_pyramid.area(), area_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你输入的坐标构不成三角形"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 2:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			x44 = _ttof(X4);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			y44 = _ttof(Y4);
			height = _ttof(X5);
			quadrangular quad(x11, y11, x22, y22, x33, y33, x44, y44, height);
			result.Format(_T("四棱柱的面积为%f%s"),quad.area(), area_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 3:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		y_5.GetWindowTextW(Y5);
		x_6.GetWindowTextW(X6);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T("")||Y5==_T("")||X6==_T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4) && judgenum(Y5) && judgenum(X6))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			x22 = _ttof(X2);
			y22 = _ttof(Y2);
			x33 = _ttof(X3);
			y33 = _ttof(Y3);
			x44 = _ttof(X4);
			y44 = _ttof(Y4);
			x55 = _ttof(X5);
			y55 = _ttof(Y5);
			height = _ttof(X6);
			rectangular_pyramid rec_pyramid(x11, y11, x22, y22, x33, y33, x44, y44, height, x55, y55);
			result.Format(_T("四棱锥的面积为%f%s"), rec_pyramid.area(), area_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 4:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		y_5.GetWindowTextW(Y5);
		x_6.GetWindowTextW(X6);
		y_6.GetWindowTextW(Y6);
		x_7.GetWindowTextW(X7);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T("") || X6 == _T("") || Y6 == _T("") || X7 == _T("") || Y5 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4) && judgenum(Y5) && judgenum(X6) && judgenum(Y6) && judgenum(X7))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			x33 = _ttof(X3);
			x44 = _ttof(X4);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			y33 = _ttof(Y3);
			y44 = _ttof(Y4);
			x55 = _ttof(X5);
			y55 = _ttof(Y5);
			x66 = _ttof(X6);
			y66 = _ttof(Y6);
			height= _ttof(X7);
			Three_prism thr_prism(x11, y11, x22, y22, x33, y33, height, x44, y44, x55, y55, x66, y66);
			if (thr_prism.judge2())
			{
				result.Format(_T("三棱台的面积为%f%s"), thr_prism.area(), area_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你输入的信息构不成三棱台"), _T("警告"), MB_OK);
			}
		}
		break;
	case 5:
		x_1.GetWindowTextW(X1);
		x_2.GetWindowTextW(X2);
		y_1.GetWindowTextW(Y1);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		y_3.GetWindowTextW(Y3);
		x_4.GetWindowTextW(X4);
		y_4.GetWindowTextW(Y4);
		x_5.GetWindowTextW(X5);
		y_5.GetWindowTextW(Y5);
		x_6.GetWindowTextW(X6);
		y_6.GetWindowTextW(Y6);
		x_7.GetWindowTextW(X7);
		y_7.GetWindowTextW(Y7);
		x_8.GetWindowTextW(X8);
		y_8.GetWindowTextW(Y8);
		x_9.GetWindowTextW(X9);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || X5 == _T("") || Y1 == _T("") || Y2 == _T("") || Y3 == _T("") || Y4 == _T("") || X6 == _T("") || Y6 == _T("") || X7 == _T("") || Y5 == _T("")||Y8==_T("")||Y7==_T("")||X8==_T("")||X9==_T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(X5) && judgenum(X6) && judgenum(X7) && judgenum(X8) && judgenum(X9) && judgenum(Y1) && judgenum(Y2) && judgenum(Y3) && judgenum(Y4) && judgenum(Y5) && judgenum(Y6) && judgenum(Y7) && judgenum(Y8))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			x22 = _ttof(X2);
			y22 = _ttof(Y2);
			x33 = _ttof(X3);
			y33 = _ttof(Y3);
			x44 = _ttof(X4);
			y44 = _ttof(Y4);
			x55 = _ttof(X5);
			y55 = _ttof(Y5);
			x66 = _ttof(X6);
			y66 = _ttof(Y6);
			x77 = _ttof(X7);
			y77 = _ttof(Y7);
			x88 = _ttof(X8);
			y88 = _ttof(Y8);
			height = _ttof(X9);
			quadrangular_frustum_pyramid quad_frust_pyramid(x11, y11, x22, y22, x33, y33, x44, y44,x55, y55, x66, y66, x77, y77, x88,y88,height);
			if (quad_frust_pyramid.judge3())
			{
				result.Format(_T("四棱台面积为%f%s"), quad_frust_pyramid.area(), area_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("你所输入的数据构不成四棱台"), _T("警告"), MB_OK);
			}	
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 6:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		if (X1 == _T("") || Y1 == _T("") || X2 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1= _ttof(X2);
			ball Ball1(x11, y11, r1);
			result.Format(_T("球的面积为%f%s"), Ball1.area(), area_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 7:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		x_3.GetWindowTextW(X3);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || Y1 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1= _ttof(X2);
			height = _ttof(X3);
			cylinder cylin1(x11, y11, r1, height);
			result.Format(_T("圆柱的面积为%f%s"), cylin1.area(), area_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 8:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		x_3.GetWindowTextW(X3);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || Y1 == _T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			height = _ttof(X3);
			cone con1(x11, y11, r1, height);
			result.Format(_T("圆柱的面积为%f%s"),con1.area(),area_unit(n2));
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	case 9:
		x_1.GetWindowTextW(X1);
		y_1.GetWindowTextW(Y1);
		x_2.GetWindowTextW(X2);
		y_2.GetWindowTextW(Y2);
		x_3.GetWindowTextW(X3);
		x_4.GetWindowTextW(X4);
		x_5.GetWindowTextW(X5);
		if (X1 == _T("") || X2 == _T("") || X3 == _T("") || X4 == _T("") || Y1 == _T("") || Y2 == _T("")||X5==_T(""))
		{
			MessageBox(_T("请输入完整内容"), _T("警告"), MB_OK);
		}
		else if (judgenum(X1) && judgenum(X2) && judgenum(X3) && judgenum(X4) && judgenum(Y1) && judgenum(Y2) && judgenum(X5))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			x22 = _ttof(X2);
			y22 = _ttof(Y2);
			r1 = _ttof(X3);
			x44 = _ttof(X4);
			height = _ttof(X5);
			circular_truncated_cone cir_trun_con1(x11, y11, r1, height, x22, y22, x44);
			if (x11==x22&&y11==y22)
			{
				result.Format(_T("圆台的面积为%f%s"), cir_trun_con1.area(), area_unit(n2));
				SetDlgItemText(IDC_EDIT1, result);
			}
			else
			{
				MessageBox(_T("所输入的信息构不成圆台"), _T("警告"), MB_OK);
			}
		}
		else
		{
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		}
		break;
	}
	}
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
	n2 = combox3.GetCurSel();
	GetDlgItem(IDC_COMBO1)->ShowWindow(0);
	if (n2 == 0 || n2 == 1|| n2 == 2)	
	{
		GetDlgItem(IDC_COMBO1)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_COMBO1)->ShowWindow(0);
	}
	// TODO: 在此添加控件通知处理程序代码
}
void CcalgraphyDlg::ShowHide(int b, int c, int d, int e, int f, int g, int h,int i)
{
	
	GetDlgItem(IDC_EDIT2)->ShowWindow(b);
	GetDlgItem(IDC_EDIT6)->ShowWindow(b);
	GetDlgItem(IDC_P1)->ShowWindow(b);
	//
	GetDlgItem(IDC_EDIT3)->ShowWindow(c);
	GetDlgItem(IDC_EDIT7)->ShowWindow(c);
	GetDlgItem(IDC_P2)->ShowWindow(c);
	//
	GetDlgItem(IDC_P3)->ShowWindow(d);
	GetDlgItem(IDC_EDIT4)->ShowWindow(d);
	//

	GetDlgItem(IDC_EDIT5)->ShowWindow(e);
	GetDlgItem(IDC_P4)->ShowWindow(e);
	//
	
	GetDlgItem(IDC_EDIT8)->ShowWindow(f);
	GetDlgItem(IDC_EDIT9)->ShowWindow(g);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(h);
	GetDlgItem(IDC_BUTTON8)->ShowWindow(i);
}
bool CcalgraphyDlg::judgenum(CString s1)
{
	int i;
	int n = s1.GetLength();
	if ((s1[0] == '-' || (s1[0] >= '0' && s1[0] <= '9'))&&n>=4)
	{
		for (i = 0; i < s1.GetLength(); i++)
		{
			if (i == s1.GetLength() - 3||s1[i]=='-')
				i++;
			if (s1[i] >= '0' && s1[i] <= '9')
				continue;
			else
			{
				return false;
				break;
			}
		}
		if (i == s1.GetLength())
		{
			return true;
		}
	}
	else
		return false;
}



void CcalgraphyDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnStnClickedP1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnStnClickedP5()
{
	// TODO: 在此添加控件通知处理程序代码
}


HBRUSH CcalgraphyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd == this)
	{
		return m_bkBrush;
	}

	return hbr;
}


LRESULT CcalgraphyDlg::OnNcHitTest(CPoint point)
{
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


void CcalgraphyDlg::OnStnClickedP3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnCbnSelchangeCombo2()
{
	n3 = combox2.GetCurSel();
	combox1.ResetContent();
	ShowHide(0, 0, 0, 0, 0, 0, 0, 0);
	ShowHide1(0, 0, 0, 0, 0);
	if (n3 == 0)
	{
		combox1.InsertString(0, _T("线段"));
		combox1.InsertString(1, _T("平行四边形"));
		combox1.InsertString(2, _T("圆"));
		combox1.InsertString(3, _T("圆弧"));
	}
	else if (n3 == 1)
	{
		combox1.InsertString(0, _T("三棱柱"));
		combox1.InsertString(1, _T("三棱锥"));
		combox1.InsertString(2, _T("四棱柱"));
		combox1.InsertString(3, _T("四棱锥"));
		combox1.InsertString(4, _T("三棱台"));
		combox1.InsertString(5, _T("四棱台"));
		combox1.InsertString(6, _T("球体"));
		combox1.InsertString(7, _T("圆柱"));
		combox1.InsertString(8, _T("圆锥"));
		combox1.InsertString(9, _T("圆台"));
	}
	GetDlgItem(IDC_COMBO3)->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnEnChangeEdit14()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnEnChangeEdit16()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
void CcalgraphyDlg::ShowHide1(int a, int b, int c, int d, int e)
{
	GetDlgItem(IDC_P6)->ShowWindow(a);
	GetDlgItem(IDC_EDIT10)->ShowWindow(a);
	GetDlgItem(IDC_EDIT11)->ShowWindow(a);
	//
	GetDlgItem(IDC_P7)->ShowWindow(b);
	GetDlgItem(IDC_EDIT12)->ShowWindow(b);
	GetDlgItem(IDC_EDIT13)->ShowWindow(b);
	//
	GetDlgItem(IDC_P8)->ShowWindow(c);
	GetDlgItem(IDC_EDIT14)->ShowWindow(c);
	GetDlgItem(IDC_EDIT15)->ShowWindow(c);
	//
	GetDlgItem(IDC_P9)->ShowWindow(d);
	GetDlgItem(IDC_EDIT16)->ShowWindow(d);
	GetDlgItem(IDC_EDIT17)->ShowWindow(d);
	//
	GetDlgItem(IDC_P10)->ShowWindow(e);
	GetDlgItem(IDC_EDIT18)->ShowWindow(e);
}


void CcalgraphyDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
CString CcalgraphyDlg::area_unit(int n)
{
	CString unit;
	switch (n)
	{
	case 0:
		unit = "平方厘米";
		break;
	case 1:
		unit = "平方毫米";
		break;
	case 2:
		unit = "平方米";
		break;
	}
	return unit;
}
CString CcalgraphyDlg::volume_unit(int n)
{
	CString unit;
	switch (n)
	{
	case 0:
		unit = "立方厘米";
		break;
	case 1:
		unit = "立方毫米";
		break;
	case 2:
		unit = "立方米";
		break;
	}
	return unit;
}
CString CcalgraphyDlg::length_unit(int n)
{
	CString unit;
	switch (n)
	{
	case 0:
		unit = "厘米";
		break;
	case 1:
		unit = "毫米";
		break;
	case 2:
		unit = "米";
		break;
	}
	return unit;

}

void CcalgraphyDlg::OnBnClickedButton5()
{
	CString result = _T("");
	show_result.GetWindowTextW(result);
	if (result == _T(""))
	{
		MessageBox(_T("请计算出结果，再进行存档"), _T("警告"), MB_OK);
	}
	else
	{
		box1.DoModal();
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


void CcalgraphyDlg::OnCbnSelchangeCombo4()
{
	
	// TODO: 在此添加控件通知处理程序代码
}

void inputbox::OnBnClickedButton1()
{
	file_name.GetWindowTextW(filename);
	if (filename == _T(""))
	{
		MessageBox(_T("请输入存档名"), _T("警告"), MB_OK);
	}
	else
	{
		CString inpath = _T("");
		inpath.Format(_T("E:\\c++\\项目\\存档\\%s.txt"), filename);
		ofstream outfile(inpath, ios::out);
		
		outfile.close();

	}
	// TODO: 在此添加控件通知处理程序代码
}
void inputbox::OnBnClickedButton3()
{
	CDialog::OnOK();
	EndDialog(1);
	// TODO: 在此添加控件通知处理程序代码
}


