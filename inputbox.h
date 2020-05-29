#pragma once


// inputbox 对话框

class inputbox : public CDialogEx
{
	DECLARE_DYNAMIC(inputbox)

public:
	inputbox(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~inputbox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDC_INPUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	CEdit file_name;
};
