
// cal_graphyDlg.h: 头文件
//

#pragma once


// CcalgraphyDlg 对话框
class CcalgraphyDlg : public CDialogEx
{
// 构造
public:
	CcalgraphyDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void ShowHide(int);
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
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedButton8();
	CEdit x1;
	CEdit y1;
	CEdit x2;
	CEdit y2;
	CEdit y3;
	CEdit x4;
	CEdit y4;
	CEdit show_result;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox combox3;
};

