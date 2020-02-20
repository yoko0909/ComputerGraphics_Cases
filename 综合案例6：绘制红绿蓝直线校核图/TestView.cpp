
// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Test.h"
#endif

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <math.h>
#define ROUND(d) int(d + 0.5)
#define PI 3.1415926
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here
	
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	int nClientWidth = rect.Width();
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width()/2 ,-rect.Height() / 2);
	double R = nClientWidth / 8;
	CLine line;

	//左圆 起点, 终点, 起点颜色, 终点颜色
	double CenterLeftX0, CenterLeftY0, CenterLeftX1, CenterLeftY1;
	COLORREF clrLeft0, clrLeft1;
	
	//CenterLeftX0 = 0, CenterLeftY0 = 0.0, clrLeft0 = RGB(255, 0, 0), clrLeft1 = RGB(0, 0, 255);
	//CenterLeftX1 = 200;
	//CenterLeftY1 = 80;
	//line.MoveTo(pDC, ROUND(CenterLeftX0), ROUND(CenterLeftY0), clrLeft0);//绘制红色左圆
	//line.LineTo(pDC, ROUND(CenterLeftX1), ROUND(CenterLeftY1), clrLeft1);

	//中圆 起点, 终点, 起点颜色, 终点颜色
	double CenterX0, CenterY0, CenterX1, CenterY1;
	COLORREF clr0, clr1;
	//右圆 起点, 终点, 起点颜色, 终点颜色
	double CenterRightX0, CenterRightY0, CenterRightX1, CenterRightY1;
	COLORREF clrRight0, clrRight1;

	CenterLeftX0 = -nClientWidth / 3, CenterLeftY0 = 0.0, clrLeft0 = RGB(150, 150, 150), clrLeft1 = RGB(255, 0, 0);//左圆
	CenterX0 =  0.0, CenterY0 = 0.0, clr0 = RGB(150, 150, 150), clr1 = RGB(0, 255, 0);//中圆
	CenterRightX0 = nClientWidth / 3, CenterRightY0 = 0.0, clrRight0 = RGB(150, 150, 150), clrRight1 = RGB(0, 0, 255);//右圆
	
	for(int i = 0; i < 360; i++)
	{
		CenterLeftX1 = CenterLeftX0 + R * cos(i * PI / 180);
		CenterLeftY1 = CenterLeftY0 + R * sin(i * PI / 180);
		line.MoveTo(pDC, ROUND(CenterLeftX0), ROUND(CenterLeftY0), clrLeft1);//绘制红色左圆
		line.LineTo(pDC, ROUND(CenterLeftX1), ROUND(CenterLeftY1), clrLeft0);

		CenterX1 = CenterX0 + R * cos(i * PI / 180);
		CenterY1 = CenterY0 + R * sin(i * PI / 180);
		line.MoveTo(pDC, ROUND(CenterX0), ROUND(CenterY0), clr1);//绘制绿色中圆
		line.LineTo(pDC, ROUND(CenterX1), ROUND(CenterY1), clr0);

		CenterRightX1 = CenterRightX0 + R * cos(i * PI / 180);
		CenterRightY1 = CenterRightY0 + R * sin(i * PI / 180);
		line.MoveTo(pDC, ROUND(CenterRightX0), ROUND(CenterRightY0), clrRight1);//绘制蓝色右圆
		line.LineTo(pDC, ROUND(CenterRightX1), ROUND(CenterRightY1), clrRight0);
	}	
}

 
// CTestView printing


void CTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


void CTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG
