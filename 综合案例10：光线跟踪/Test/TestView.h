
// TestView.h : interface of the CTestView class
//

#pragma once
#include "ViewPlane.h"//视平面
#include "Lighting.h"//光照类
#include "Material.h"//材质类
#include "Sphere.h"//球体类
#include "Torus.h"//圆环类
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
	void SetScene(CDC* pDC);//设置场景
	void RenderScene(CDC* pDC,int nDepth);//渲染场景
	void RenderAntiAliasingScene(CDC* pDC,int nDepth);//渲染反走样场景
    CRGB RayTracing(CRay Ray, int nDepth);//光线跟踪
	CRay Reflect(CRay IncidentLight, CIntersection Hit);//反射
    CRGB Shader(CRay Ray, CIntersection  Hit, int nDepth);//着色    
    CRay Refract(CRay IncidentLight, CIntersection Hit);//折射
	BOOL ShadowCast(CIntersection Hit);//投射阴影
public:
	
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
	int nClientWidth,nClientHeight;//客户区宽度和高度
	int	nLightSourceNumber;//光源数量
	CLighting* pLight;//光照环境
	int nVResolution,nHResolution;//水平与垂直分辨率
	CViewPlane ViewPlane;//视平面
	CGeometricObject* pObjects[2];//几何对象指针
	CMaterial Material[2];//物体材质
	int nObjectNumber;//物体数量
	CRGB bkColor;//背景色
	double PixelSize;//像素大小
	CP3 EyePoint;//视点
	double zViewPlane;//视平面在z轴上的位置
	double R,d;//视径和视距
	double nHittoLightSource;//碰撞点与光源的距离
	CIntersection MiniHit;//最小碰撞点 
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in TestView.cpp
inline CTestDoc* CTestView::GetDocument() const
   { return reinterpret_cast<CTestDoc*>(m_pDocument); }
#endif

