// inputbox.cpp: 实现文件
//

#include "pch.h"
#include "cal_graphy.h"
#include "inputbox.h"
#include "afxdialogex.h"
// inputbox 对话框

IMPLEMENT_DYNAMIC(inputbox, CDialogEx)

inputbox::inputbox(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDC_INPUTBOX, pParent)
{

}

inputbox::~inputbox()
{
}

void inputbox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, file_name);
}


BEGIN_MESSAGE_MAP(inputbox, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &inputbox::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &inputbox::OnBnClickedButton3)
END_MESSAGE_MAP()


// inputbox 消息处理程序









