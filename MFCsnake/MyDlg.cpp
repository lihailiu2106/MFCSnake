// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCsnake.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// CMyDlg �Ի���

IMPLEMENT_DYNAMIC(CMyDlg, CDialog)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{

	//  m_n1 = 0;
	//  m_n1 = 0;
	//  m_n1 = 0;
	//  m_�� = 0;
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
	//  DDX_Text(pDX, IDC_EDIT1, m_��);
	//  DDV_MinMaxInt(pDX, m_��, 1, 100);
	DDX_Text(pDX, IDC_EDIT1, m_n1);
	DDV_MinMaxInt(pDX, m_n1, 1, 10);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
//	ON_EN_CHANGE(IDC_EDIT1, &CMyDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMyDlg ��Ϣ�������


//void CMyDlg::OnEnChangeEdit1()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}
// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCsnake.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

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


// MyDlg ��Ϣ�������
