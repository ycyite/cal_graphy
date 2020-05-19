
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
double x11=0;
double x22=0;
double x33=0;
double x44=0;
double y11=0;
double y22=0;
double y33=0;
double y44=0;
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
CString unit1=_T("");
int n1;
int n2;
int n3;

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
END_MESSAGE_MAP()


// CcalgraphyDlg 消息处理程序

BOOL CcalgraphyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
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
			SetDlgItemText(IDC_P1, _T("第一个点："));
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
			SetDlgItemText(IDC_P1, _T("第一个点："));
			SetDlgItemText(IDC_P2, _T("半径："));
			SetDlgItemText(IDC_P3, _T("角度："));
			SetDlgItemText(IDC_BUTTON1, _T("面积"));
			SetDlgItemText(IDC_BUTTON8, _T("周长"));
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
	switch(n1)
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
		else if(judgenum(X1)&&judgenum(X2)&&judgenum(Y1)&&judgenum(Y2))
		{
			x11 = _ttof(X1);
			x22 = _ttof(X2);
			y11 = _ttof(Y1);
			y22 = _ttof(Y2);
			line lin1(x11, y11, x22, y22);
			switch(n2)
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
		else if(judgenum(X1)&&judgenum(X2)&&judgenum(X3)&&judgenum(X4)&&judgenum(Y1)&&judgenum(Y2)&&judgenum(Y3)&&judgenum(Y4))
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
			if (pall.judge())
			{
				switch(n2)
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
		else if(judgenum(X1)&&judgenum(Y1)&&judgenum(X2))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			Circle cir1(x11, y11, r1);
			switch(n2)
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
		else if(judgenum(X1)&&judgenum(X2)&&judgenum(X3)&&judgenum(Y1))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			arc = _ttof(X3);
			Angle A1(x11, y11, r1, arc);
			switch(n2)
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

	// TODO: 在此添加控件通知处理程序代码
}




void CcalgraphyDlg::OnBnClickedButton8()
{
	CString result = _T("");
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
			if (pall.judge())
			{
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
				result.Format(_T("平行四边形周长为%f%s"), pall.length(), unit1);
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
			result.Format(_T("圆的周长为%f%s"), cir1.length(), unit1);
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
		else if (judgenum(X1) && judgenum(Y1) && judgenum(X2) && judgenum(X3))
		{
			x11 = _ttof(X1);
			y11 = _ttof(Y1);
			r1 = _ttof(X2);
			arc = _ttof(X3);
			Angle A1(x11, y11, r1, arc);
			switch(n2)
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
			result.Format(_T("圆弧周长为%f%s"), A1.length(), unit1);
			SetDlgItemText(IDC_EDIT1, result);
		}
		else
			MessageBox(_T("请输入两位小数的数字"), _T("警告"), MB_OK);
		break;
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
		combox1.InsertString(9, _T("半球"));
	}
	GetDlgItem(IDC_COMBO3)->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}
