
// cal_graphyDlg.h: 头文件
//

#pragma once

// CcalgraphyDlg 对话框
class CcalgraphyDlg : public CDialogEx
{
// 构造
public:
	CcalgraphyDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void ShowHide(int , int , int , int , int , int , int ,int );
	void ShowHide1(int, int, int, int, int);
	CString area_unit(int n);
	CString volume_unit(int n);
	CString length_unit(int n);
	bool judgenum(CString);
//郭必然提议定义一个函数减少工作量
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAL_GRAPHY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox combox1;
	afx_msg void OnLbnSelchangeList4();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit9();
	
	CEdit x3;
	
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedButton8();
	CEdit x_1;
	CEdit y_1;
	CEdit x_2;
	CEdit y_2;
	CEdit x_3;
	CEdit y_3;
	CEdit x_4;
	CEdit y_4;
	CEdit show_result;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox combox3;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedP1();
	afx_msg void OnStnClickedP5();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	CBrush m_bkBrush;
	afx_msg void OnStnClickedP3();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox combox2;
	afx_msg void OnEnChangeEdit14();
	afx_msg void OnEnChangeEdit16();
	CEdit x_5;
	CEdit y_5;
	CEdit x_6;
	CEdit y_6;
	CEdit x_7;
	CEdit y_7;
	CEdit x_8;
	CEdit y_8;
	CEdit x_9;
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnCbnSelchangeCombo4();
};

