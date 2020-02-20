
// TestView.h : interface of the CTestView class
//

#pragma once
#include"SPhere.h"
#include "Transform3.h"

class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

	// Attributes
public:
	CTestDoc* GetDocument() const;

	// Operations
public:
	void DoubleBuffer(CDC* pDC);//双缓冲绘图
	void DrawObject(CDC* pDC);//绘制对象
	void CollisionDetection(void);//碰撞检测函数
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Implementation
public:
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int nWidth, nHeight;//客户区的宽度和高度
	int nHalfWidth, nHalfHeight;//客户区半宽和半高
	CSphere sphere;//球体对象
	CTransform3 transform;//变换
	double Alpha, Beta, Gamma;//x方向旋转α角，y方向旋转β角，绕z轴旋转角γ
	BOOL bPlay;//动画
	CP3 ptCenter;//中心点
	CP3 Direction;//运动方向
	int nRadius;
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGraphAnimation();
	afx_msg void OnUpdateGraphAnimation(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in TestView.cpp
inline CTestDoc* CTestView::GetDocument() const
{
	return reinterpret_cast<CTestDoc*>(m_pDocument);
}
#endif

