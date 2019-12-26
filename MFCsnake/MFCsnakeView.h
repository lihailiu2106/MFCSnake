
// MFCsnakeView.h : CMFCsnakeView ��Ľӿ�
//

#pragma once

#include"mmsystem.h"

#define updir 0
#define downdir 1
#define leftdir 2
#define rightdir 3

#define snake_width 20
#define bord_width  800
#define bord_higth  600

struct snake
{
	int x,y;
	snake *next;
};
class CMFCsnakeView : public CView
{
	public:
		int len;
	//�ϰ���
		CPoint obs1[30];
		CPoint obs2[30];
		CPoint obs[30];
		int zhangai;
	//ʳ��ͼƬ
CBitmap m_Bitmap1;
int m_nHeight1;
int m_nWidth1;
//����
CBitmap m_Bitmap2;
int m_nHeight2;
int m_nWidth2;
//����
CBitmap m_Bitmap3;
int m_nHeight3;
int m_nWidth3;
CBitmap m_Bitmap4;
int m_nHeight4;
int m_nWidth4;
CBitmap m_Bitmap5;
int m_nHeight5;
int m_nWidth5;

int bkp;
//�ϰ���ͼƬ
CBitmap m_Bitmap6;
int m_nHeight6;
int m_nWidth6;

	//��
snake *phead,*p1,*p2,*p3,*s;
int foodx,foody;
int dir;
int flag;
int score;
int level;
int space;

int knockwall();
int knocksnake();
void food();
void rewrite();
void SaveGame();
void LoadGame();
protected: // �������л�����
	CMFCsnakeView();
	DECLARE_DYNCREATE(CMFCsnakeView)

// ����
public:
	CMFCsnakeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCsnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnGeneral();
	afx_msg void OnHard();
	afx_msg void OnLoad();
	afx_msg void OnNew();
	afx_msg void OnNghtmare();
	afx_msg void OnPause();
	afx_msg void OnSave();
	afx_msg void OnSet();
	afx_msg void OnStart();
	afx_msg void OnEasy();
	afx_msg void OnEnd();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBgmStart();
	afx_msg void OnBgmEnd();
	afx_msg void OnBkg1();
	afx_msg void OnBkg2();
	afx_msg void OnBkg3();
	afx_msg void OnMyset();
	afx_msg void OnDemo();
};

#ifndef _DEBUG  // MFCsnakeView.cpp �еĵ��԰汾
inline CMFCsnakeDoc* CMFCsnakeView::GetDocument() const
   { return reinterpret_cast<CMFCsnakeDoc*>(m_pDocument); }
#endif

