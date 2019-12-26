// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCsnake.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// CMyDlg 对话框

IMPLEMENT_DYNAMIC(CMyDlg, CDialog)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{

	//  m_n1 = 0;
	//  m_n1 = 0;
	//  m_n1 = 0;
	//  m_你 = 0;
	m_n1 = 0;
}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_n1);
	//  DDV_MinMaxInt(pDX, m_n1, 1, 1000);
	//  DDX_Text(pDX, IDC_EDIT1, m_n1);
	//  DDV_MinMaxInt(pDX, m_n1, 1, 100);
	//  DDX_Text(pDX, IDC_EDIT1, m_n1);
	//  DDV_MinMaxInt(pDX, m_n1, 1, 10);
	//  DDX_Text(pDX, IDC_EDIT1, m_你);
	//  DDV_MinMaxInt(pDX, m_你, 1, 100);
	DDX_Text(pDX, IDC_EDIT1, m_n1);
	DDV_MinMaxInt(pDX, m_n1, 1, 10);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
//	ON_EN_CHANGE(IDC_EDIT1, &CMyDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMyDlg 消息处理程序


//void CMyDlg::OnEnChangeEdit1()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialog::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}
// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCsnake.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialog)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MyDlg::IDD, pParent)
{

	//  m_n2 = 0;
	m_n2 = 0;
}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_RADIO1, m_n2);
	//  DDV_MinMaxInt(pDX, m_n2, 1, 10);
	DDX_Radio(pDX, IDC_RADIO1, m_n2);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialog)
END_MESSAGE_MAP()


// MyDlg 消息处理程序
