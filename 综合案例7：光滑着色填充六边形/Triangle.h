#pragma once
#include "P2.h"//带颜色的浮点数二维点类
#include "Point2.h"//带颜色的整数二维点类

class CTriangle//三角形填充类
{
public:
	CTriangle(void);
	CTriangle(CP2 P0, CP2 P1, CP2 P2);//浮点数顶点构造三角形
	virtual ~CTriangle(void);
	void GouraudShader(CDC* pDC);//填充三角形
private:
	void DDA(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature);//边标记
	CRGB LinearInterp(double t, double tStart, double tEnd, CRGB cStart, CRGB cEnd);//颜色线性插值
	void SortVertex(void);//三角形顶点排序
private:
	CPoint2 point0, point1, point2;//三角形的整数顶点
	CPoint2* SpanLeft; //跨度的起点数组标志
	CPoint2* SpanRight;//跨度的终点数组标志
	int nIndex;//扫描线索引
};

