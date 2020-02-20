
// TestView.h : interface of the CTestView class
//
#pragma once
#include "Teapot.h"
#include "Transform3.h"

class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

	// Attributes
public:
	CTestDoc * GetDocument() const;

	// Operations
public:
	void DoubleBuffer(CDC* pDC);//双缓冲绘图
	void DrawObject(CDC* pDC);//绘制对象
	void InitializeLightingScene(void);//初始化光照场景
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
	CRect rect;//客户区矩形
	CTeapot teapot;//Utah茶壶
	CTransform3 transform;//变换
	double Alpha, Beta;//x方向旋转α角,y方向旋转β角
	BOOL bPlay;//动画
	int	nLightSourceNumber;//光源数量
	CLighting* pLight;//光照环境
	CMaterial* pMaterial;//物体材质
	CTexture   Texture[2];//物体纹理
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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in TestView.cpp
inline CTestDoc* CTestView::GetDocument() const
{
	return reinterpret_cast<CTestDoc*>(m_pDocument);
}
#endif

