
// MFCsnakeView.cpp : CMFCsnakeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCsnake.h"
#endif

#include "MFCsnakeDoc.h"
#include "MFCsnakeView.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "windows.h"

#define ONE_BEEP 100

#define NOTE_1 440
#define NOTE_2 495
#define NOTE_3 550
#define NOTE_4 587
#define NOTE_5 660
#define NOTE_6 733
#define NOTE_7 325
// CMFCsnakeView

IMPLEMENT_DYNCREATE(CMFCsnakeView, CView)

BEGIN_MESSAGE_MAP(CMFCsnakeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCsnakeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_general, &CMFCsnakeView::OnGeneral)
	ON_COMMAND(ID_hard, &CMFCsnakeView::OnHard)
	ON_COMMAND(ID_load, &CMFCsnakeView::OnLoad)
	ON_COMMAND(ID_new, &CMFCsnakeView::OnNew)
	ON_COMMAND(ID_nghtmare, &CMFCsnakeView::OnNghtmare)
	ON_COMMAND(ID_pause, &CMFCsnakeView::OnPause)
	ON_COMMAND(ID_save, &CMFCsnakeView::OnSave)
	ON_COMMAND(ID_set, &CMFCsnakeView::OnSet)
	ON_COMMAND(ID_start, &CMFCsnakeView::OnStart)
	ON_COMMAND(ID_easy, &CMFCsnakeView::OnEasy)
	ON_COMMAND(ID_end, &CMFCsnakeView::OnEnd)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_BGM_start, &CMFCsnakeView::OnBgmStart)
	ON_COMMAND(ID_BGM_end, &CMFCsnakeView::OnBgmEnd)
	ON_COMMAND(ID_bkg1, &CMFCsnakeView::OnBkg1)
	ON_COMMAND(ID_bkg2, &CMFCsnakeView::OnBkg2)
	ON_COMMAND(ID_bkg3, &CMFCsnakeView::OnBkg3)
	ON_COMMAND(ID_myset, &CMFCsnakeView::OnMyset)
	ON_COMMAND(ID_demo, &CMFCsnakeView::OnDemo)
END_MESSAGE_MAP()

// CMFCsnakeView 构造/析构

CMFCsnakeView::CMFCsnakeView()
{
	// TODO: 在此处添加构造代码
	phead=(snake*)malloc(sizeof(snake));
p1=(snake*)malloc(sizeof(snake));
p2=(snake*)malloc(sizeof(snake));
p3=(snake*)malloc(sizeof(snake));
phead->next=p3;
p1->x=100;
p1->y=100;
p1->next=NULL;
p2->x=120;
p2->y=100;
p2->next=p1;
p3->x=140;
p3->y=100;
p3->next=p2;
flag=0;
score=0;
level=100;
space=0;
zhangai=0;
dir=3;
len=3;
bkp=1;
srand((unsigned)time(NULL));
	foodx=(rand()%39+1)*20;
	foody=(rand()%29+1)*20;

//障碍物
	if(zhangai==0){
 for(int i=0;i<30;i++)
	{
		obs1[i].x=100+20*i;
		obs1[i].y=500;
 }
 for(int i=0;i<30;i++)
	{
		obs2[i].x=100+20*i;
		obs2[i].y=200;
 }
	}
	else
  for(int i=0;i<30;i++)
	{
		do{
		obs[i].x=(rand()%39+1)*20;
		obs[i].y=(rand()%29+1)*20;
		}while(obs[i].x==100&&obs[i].y==100||obs[i].x==120&&obs[i].y==100||obs[i].x==140&&obs[i].y==100||obs[i].x==1600&&obs[i].y==100||obs[i].x==foodx&&obs[i].y==foody);
 }
//图片
	m_Bitmap1.LoadBitmapW(IDB_BITMAP1);
	m_Bitmap2.LoadBitmapW(IDB_BITMAP2);
	m_Bitmap3.LoadBitmapW(IDB_BITMAP3);
	m_Bitmap4.LoadBitmapW(IDB_BITMAP4);
	m_Bitmap5.LoadBitmapW(IDB_BITMAP5);
	m_Bitmap6.LoadBitmapW(IDB_BITMAP6);
	BITMAP bm1;
	BITMAP bm2;
	BITMAP bm3;
	BITMAP bm4;
	BITMAP bm5;
	BITMAP bm6;
	m_Bitmap1.GetBitmap(&bm1);
	m_nWidth1=bm1.bmWidth;
	m_nHeight1=bm1.bmHeight;
	
	m_Bitmap2.GetBitmap(&bm2);
	m_nWidth2=bm2.bmWidth;
	m_nHeight2=bm2.bmHeight;

	m_Bitmap3.GetBitmap(&bm3);
	m_nWidth3=bm3.bmWidth;
	m_nHeight3=bm3.bmHeight;

	m_Bitmap4.GetBitmap(&bm4);
	m_nWidth4=bm4.bmWidth;
	m_nHeight4=bm4.bmHeight;

	m_Bitmap5.GetBitmap(&bm5);
	m_nWidth5=bm5.bmWidth;
	m_nHeight5=bm5.bmHeight;

	m_Bitmap6.GetBitmap(&bm6);
	m_nWidth6=bm6.bmWidth;
	m_nHeight6=bm6.bmHeight;

}

CMFCsnakeView::~CMFCsnakeView()
{
}

BOOL CMFCsnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCsnakeView 绘制

void CMFCsnakeView::OnDraw(CDC* pDC)
{
	CMFCsnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect ClientRect;
	GetClientRect(&ClientRect);
	int nWidth =ClientRect.Width();					
	int nHeight=ClientRect.Height();  
	CDC MemDC;
	CBitmap MemBitmap;	
	MemDC.CreateCompatibleDC(pDC);
	MemBitmap.CreateCompatibleBitmap(pDC,nWidth,nHeight);
	MemDC.SelectObject(&MemBitmap);
	MemDC.FillSolidRect(0,0,nWidth,nHeight,RGB(255,255,255));
	//背景
	if(bkp==1){
	CDC MemDC3;
	MemDC3.CreateCompatibleDC(NULL);
	MemDC3.SelectObject(&m_Bitmap3);
	MemDC.StretchBlt(0,0,nWidth,nHeight,&MemDC3,0,0,m_nWidth3,m_nHeight3,SRCCOPY);
	}
	else if(bkp==2){
	CDC MemDC4;
	MemDC4.CreateCompatibleDC(NULL);
	MemDC4.SelectObject(&m_Bitmap4);
	MemDC.StretchBlt(0,0,nWidth,nHeight,&MemDC4,0,0,m_nWidth4,m_nHeight4,SRCCOPY);
	}
	else{
	CDC MemDC5;
	MemDC5.CreateCompatibleDC(NULL);
	MemDC5.SelectObject(&m_Bitmap5);
	MemDC.StretchBlt(0,0,nWidth,nHeight,&MemDC5,0,0,m_nWidth5,m_nHeight5,SRCCOPY);
	}

	MemDC.MoveTo(15,15);
	MemDC.LineTo(1205,15);
	
	MemDC.MoveTo(15,15);
	MemDC.LineTo(15,605);

	MemDC.MoveTo(1205,15);
	MemDC.LineTo(1205,605);
	
	MemDC.MoveTo(15,605);
	MemDC.LineTo(1205,605);

	MemDC.MoveTo(20,20);
	MemDC.LineTo(20,600);

	MemDC.MoveTo(20,600);
	MemDC.LineTo(800,600);

	MemDC.MoveTo(20,20);
	MemDC.LineTo(800,20);

    MemDC.MoveTo(800,20);
	MemDC.LineTo(800,600);
	//MemDC.Rectangle(15,15,1205,605);
	//MemDC.Rectangle(20,20,800,600);
	CBrush DrawBrush1=(RGB(100,100,100));
	CBrush *Drawbrush1=MemDC.SelectObject(&DrawBrush1);
	for(int i=0;i<29;i++)
	{
		MemDC.MoveTo(20,20+20*i);
		MemDC.LineTo(800,20+20*i);
	}
		for(int i=0;i<39;i++)
	{
		MemDC.MoveTo(20+20*i,20);
		MemDC.LineTo(20+20*i,600);
	}
		DrawBrush1.DeleteObject();

//障碍物
		for(int i=0;i<30;i++)
		{
			CDC MemDC6;
			MemDC6.CreateCompatibleDC(NULL);
			MemDC6.SelectObject(&m_Bitmap6);
			if(zhangai==0){
			MemDC.TransparentBlt(obs1[i].x+1,obs1[i].y+1,19,19,&MemDC6,0,0,m_nWidth6,m_nHeight6,RGB(255,255,255));
			MemDC.TransparentBlt(obs2[i].x+1,obs2[i].y+1,19,19,&MemDC6,0,0,m_nWidth6,m_nHeight6,RGB(255,255,255));
			}
			else
			MemDC.TransparentBlt(obs[i].x+1,obs[i].y+1,19,19,&MemDC6,0,0,m_nWidth6,m_nHeight6,RGB(255,255,255));
		}
	snake *q;
	CDC MemDC2;
	MemDC2.CreateCompatibleDC(NULL);
	MemDC2.SelectObject(&m_Bitmap2);
	for(q=phead;q!=NULL;q=q->next)
	{
		MemDC.TransparentBlt(q->x+1,q->y+1,18,18,&MemDC2,0,0,m_nWidth2,m_nHeight2,RGB(255,255,255));
		//MemDC.StretchBlt(q->x+1,q->y+1,18,18,&MemDC2,0,0,m_nWidth2,m_nHeight2,SRCCOPY);
		//MemDC.Rectangle(q->x,q->y,q->x+20,q->y+20);
	}
	
	//CBrush DrawBrush2=(RGB(20,70,100));
	//CBrush *Drawbrush2=MemDC.SelectObject(&DrawBrush2);
	//MemDC.Rectangle(foodx, foody, foodx + 20, foody + 20);
   // DrawBrush2.DeleteObject();
	//食物
	CDC MemDC1;
	MemDC1.CreateCompatibleDC(NULL);
	MemDC1.SelectObject(&m_Bitmap1);
	//MemDC.StretchBlt(foodx+1,foody+1,18,18,&MemDC1,0,0,m_nWidth1,m_nHeight1,SRCCOPY);
	MemDC.TransparentBlt(foodx+1,foody+1,18,18,&MemDC1,0,0,m_nWidth1,m_nHeight1,RGB(255,255,255));

	CFont font;
	font.CreateFont(
		40,
		0,
		0,
		0,
		FW_NORMAL,
		FALSE,
		FALSE,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH|FF_SWISS,
		_T("黑体")
		);
	CFont* Oldfont=MemDC.SelectObject(&font);
	MemDC.SetTextColor(RGB(0,0,0));
	MemDC.SetBkMode(TRANSPARENT);
	MemDC.SetBkColor(RGB(255,255,255));
	//分数显示
	CString str1;
	str1.Format(_T("分数为:%d"), score);
	MemDC.TextOutW(900, 200,str1);

	pDC->BitBlt(0,0,nWidth,nHeight,&MemDC,0,0,SRCCOPY);
	MemBitmap.DeleteObject();
    MemDC.DeleteDC();
}


// CMFCsnakeView 打印


void CMFCsnakeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCsnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCsnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCsnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCsnakeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCsnakeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCsnakeView 诊断

#ifdef _DEBUG
void CMFCsnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCsnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCsnakeDoc* CMFCsnakeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCsnakeDoc)));
	return (CMFCsnakeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCsnakeView 消息处理程序


void CMFCsnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nChar)
	{
	case VK_UP:
		if(dir!=downdir&&flag==1)
			dir =updir;
		break;
	case VK_DOWN:
		if(dir!=updir&&flag==1)
		    dir=downdir;
		break;
	case VK_LEFT:
		if(dir!=rightdir&&flag==1)
			dir=leftdir;
		break;
	case VK_RIGHT:
		if(dir!=leftdir&&flag==1)
			dir=rightdir;
		break;
	case VK_SPACE:
		if(space==0)
		OnPause();
		else
		OnStart();
		break;
	}
	flag=0;
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFCsnakeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	s=(snake*)malloc(sizeof(snake));
	switch(dir)
	{
	case 0:
		s->x=phead->next->x;s->y=phead->next->y-20;break;
	case 1:
		s->x=phead->next->x;s->y=phead->next->y+20;break;
	case 2:
		s->x=phead->next->x-20;s->y=phead->next->y;break;
	case 3:                              
		s->x=phead->next->x+20;s->y=phead->next->y;break;
	}
	flag=1;
	if(knockwall()||knocksnake())
	{
		flag=0;
		KillTimer(1);
		AfxMessageBox(_T("游戏结束"));
		
	}
	else
	{
		s->next=phead->next;phead->next=s;
		if(phead->next->x==foodx&&phead->next->y==foody)
		{
			Beep(NOTE_4,ONE_BEEP);
			food();
			score+=10;
			len++;
		}
		else
		{
	while (s->next->next != NULL)
			{
				s=s->next;
			}
			s->next = NULL;
	
		}
	    Invalidate();
		UpdateWindow();
	}
	CView::OnTimer(nIDEvent);
}
int CMFCsnakeView::knockwall()
{ 
	for(int i=0;i<30;i++)
	{
		if(s->x==obs1[i].x&&s->y==obs1[i].y)
			return 1;
	}
	for(int i=0;i<30;i++)
	{
		if(s->x==obs2[i].x&&s->y==obs2[i].y)
			return 1;
	}
	for(int i=0;i<30;i++)
	{
		if(s->x==obs[i].x&&s->y==obs[i].y)
			return 1;
	}
	if ((s->x==0)|| s->x ==800|| s->y ==0||s->y==600)
		return 1;
	
	else
		return 0;
}

int CMFCsnakeView::knocksnake()
{
	snake *p = phead->next->next;
	while (p->next != NULL)
	{
		if (p->x == s->x&&p->y == s->y)
			return 1;
		p= p->next;
	}
	return 0;
}
void CMFCsnakeView::food()
{
	foodx=(rand()%39+1)*20;
	foody=(rand()%29+1)*20;
	for(int i=0;i<30;i++)
		{
			if(obs1[i].x==foodx&&obs1[i].y==foody)
			{
				food();
			}
		}
	for(int i=0;i<30;i++)
		{
			if(obs2[i].x==foodx&&obs2[i].y==foody)
			{
				food();
			}
		}
	for(int i=0;i<30;i++)
	{
		if(obs[i].x==foodx&&obs[i].y==foody)
			{
				food();
			}
   }
	snake *p=phead->next;
	while(p->next!=NULL)
	{
		if(p->x==foodx&&p->y==foody)
		{
			food();
		}
		
		p=p->next;
	}
}

void CMFCsnakeView::rewrite()
{
	phead->next=p3;
p1->x=100;
p1->y=100;
p1->next=NULL;
p2->x=120;
p2->y=100;
p2->next=p1;
p3->x=140;
p3->y=100;
p3->next=p2;
flag=0;
score=0;
level=100;
dir=3;
space=0;
len=3;
/*srand((unsigned)time(NULL));
	foodx=(rand()%39+1)*20;
	foody=(rand()%29+1)*20;*/
food();
if(zhangai==0){

 for(int i=0;i<30;i++)
	{
		obs[i]=NULL;
		obs1[i].x=100+20*i;
		obs1[i].y=500;
 }
  for(int i=0;i<30;i++)
	{
		obs2[i].x=100+20*i;
		obs2[i].y=200;
 }
}
else
   for(int i=0;i<30;i++)
	{
		obs1[i]=NULL;
		obs2[i]=NULL;
		do{
		obs[i].x=(rand()%39+1)*20;
		obs[i].y=(rand()%29+1)*20;
		}while(obs[i].x==100&&obs[i].y==100||obs[i].x==120&&obs[i].y==100||obs[i].x==140&&obs[i].y==100||obs[i].x==160&&obs[i].y==100||obs[i].x==foodx&&obs[i].y==foody);
   }
}

void CMFCsnakeView::OnGeneral()
{
	// TODO: 在此添加命令处理程序代码
	level=200;
}


void CMFCsnakeView::OnHard()
{
	// TODO: 在此添加命令处理程序代码
	level=100;
}


void CMFCsnakeView::OnLoad()
{
	// TODO: 在此添加命令处理程序代码
	LoadGame();
	Invalidate();

}


void CMFCsnakeView::OnNew()
{
	// TODO: 在此添加命令处理程序代码
	rewrite();
	Invalidate();
}


void CMFCsnakeView::OnNghtmare()
{
	// TODO: 在此添加命令处理程序代码
	level=10;
}


void CMFCsnakeView::OnPause()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	space=1;
}


void CMFCsnakeView::OnSave()
{
	// TODO: 在此添加命令处理程序代码
	/*CFile mFile(_T("user.out"),CFile::modeWrite|CFile::modeCreate);
	mFile.Write(&dir,sizeof(dir));
	mFile.Write(&flag,sizeof(flag));
	mFile.Write(&foodx,sizeof(foodx));
	mFile.Write(&foody,sizeof(foody));
	mFile.Write(&level,sizeof(level));
	mFile.Write(&score,sizeof(score));
	mFile.Write(&space,sizeof(space));

	mFile.Flush();
	mFile.Close();*/
	SaveGame();
}


void CMFCsnakeView::OnSet()
{
	// TODO: 在此添加命令处理程序代码
	AfxMessageBox(_T("通过上下左右按键控制方向，空格键暂停和继续\r\n作者：刘礼海\r\n班级：信计二班"));
}


void CMFCsnakeView::OnStart()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1,level,NULL);
	space=0;
}


void CMFCsnakeView::OnEasy()
{
	// TODO: 在此添加命令处理程序代码
	level=300;
}


void CMFCsnakeView::OnEnd()
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}


BOOL CMFCsnakeView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return true;
	return CView::OnEraseBkgnd(pDC);
}


void CMFCsnakeView::OnBgmStart()
{
	// TODO: 在此添加命令处理程序代码
	sndPlaySound(_T("res\\message.wav"),SND_ASYNC|SND_LOOP);
}


void CMFCsnakeView::OnBgmEnd()
{
	// TODO: 在此添加命令处理程序代码
		sndPlaySound(NULL,SND_SYNC);
}

void CMFCsnakeView::SaveGame()
{
	snake *pTra=phead->next;
	FILE *pFile=fopen("data.txt","wb+");
	int nCount=len;
	fwrite(&nCount,4,1,pFile);
	for(int i=0;i<nCount;i++)
	{
		fwrite(&pTra->x,4,1,pFile);
		fwrite(&pTra->y,4,1,pFile);
		pTra=pTra->next;
	}
	for(int i=0;i<30;i++)
	{
		fwrite(&obs[i].x,4,1,pFile);
		fwrite(&obs[i].y,4,1,pFile);
	}
	fwrite(&foodx,4,1,pFile);
	fwrite(&foody,4,1,pFile);
	fwrite(&score,4,1,pFile);
	fwrite(&dir,4,1,pFile);
	fwrite(&zhangai,4,1,pFile);
	fwrite(&flag,4,1,pFile);
	fwrite(&level,4,1,pFile);
	fwrite(&len,4,1,pFile);
	fclose(pFile);
}

void CMFCsnakeView::LoadGame()
{
	snake *pTail=phead;
	FILE *pFile=fopen("data.txt","rb+");
	int nCount=0;
	fread(&nCount,4,1,pFile);
	for (int i = 0; i <nCount; i++)
	{
		snake* pNewNode = (snake*)malloc(sizeof(snake));
		fread(&pNewNode->x, 4, 1, pFile);
		fread(&pNewNode->y, 4, 1, pFile);
		pTail->next = pNewNode;
		pTail = pNewNode;
		pTail->next = NULL;
	}
	for(int i=0;i<30;i++)
	{
		fread(&obs[i].x,4,1,pFile);
		fread(&obs[i].y,4,1,pFile);
	}
	fread(&foodx, 4, 1, pFile);
	fread(&foody, 4, 1, pFile);
	fread(&score, 4, 1, pFile);
	fread(&dir, 4, 1, pFile);
	fread(&zhangai, 4, 1, pFile);
	fread(&flag, 4, 1, pFile);
	fread(&level, 4, 1, pFile);
	fread(&len, 4, 1, pFile);
}

void CMFCsnakeView::OnBkg1()
{
	// TODO: 在此添加命令处理程序代码
	bkp=1;
	Invalidate();
}


void CMFCsnakeView::OnBkg2()
{
	// TODO: 在此添加命令处理程序代码
	bkp=2;
	Invalidate();
}


void CMFCsnakeView::OnBkg3()
{
	// TODO: 在此添加命令处理程序代码
	bkp=3;
	Invalidate();
}



void CMFCsnakeView::OnMyset()
{
	// TODO: 在此添加命令处理程序代码
	CMyDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		level=100/dlg.m_n1;
	}
}


void CMFCsnakeView::OnDemo()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		zhangai=dlg.m_n2;
	}
}
