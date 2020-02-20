#include "StdAfx.h"
#include "Triangle.h"
#include <math.h>
#define ROUND(d) int(d + 0.5)

CTriangle::CTriangle(void)
{
}

CTriangle::CTriangle(CP2 P0, CP2 P1, CP2 P2)
{
	point0.x = ROUND(P0.x);
	point0.y = ROUND(P0.y);
	point0.c = P0.c;
	point1.x = ROUND(P1.x);
	point1.y = ROUND(P1.y);
	point1.c = P1.c;
	point2.x = ROUND(P2.x);
	point2.y = ROUND(P2.y);
	point2.c = P2.c;
}

CTriangle::~CTriangle(void)
{
}
void CTriangle::GouraudShader(CDC* pDC)
{
	SortVertex();//point0点为y坐标最小的点,point1点为y坐标最大的点,point2点的y坐标位于二者之间。如果y值相同，取x最小的点
	//定义三角形覆盖的扫描线条数
	int nTotalScanLine = point1.y - point0.y + 1;
	//定义span的起点与终点数组
	SpanLeft  = new CPoint2[nTotalScanLine];//跨度坐标数组
	SpanRight = new CPoint2[nTotalScanLine];//跨度右边数组
		
	//判断三角形与P0P1边的位置关系，0-1-2为右手系
	int nDeltz = (point1.x - point0.x) * (point2.y - point1.y) - (point1.y - point0.y) * (point2.x - point1.x);//点矢量叉积的z坐标
	if(nDeltz > 0)//三角形位于P0P1边的左侧
	{
		nIndex = 0;
		DDA(point0, point2, TRUE);
		DDA(point2, point1, TRUE);
		nIndex = 0;
		DDA(point0, point1, FALSE);
	}
	else//三角形位于P0P1边的右侧
	{
		nIndex = 0;
		DDA(point0, point1, TRUE);
		nIndex = 0;	
		DDA(point0, point2, FALSE);
		DDA(point2, point1, FALSE);
	}
	CRGB clr;
	for(int y = point0.y ; y < point1.y; y++)//下闭上开
	{
		int n = y - point0.y;
		for(int x = SpanLeft[n].x; x < SpanRight[n].x; x++)//左闭右开
		{
			clr = LinearInterp(x, SpanLeft[n].x, SpanRight[n].x, SpanLeft[n].c, SpanRight[n].c);
			pDC->SetPixelV(x, y, RGB(clr.red * 255, clr.green * 255, clr.blue * 255));
		}
	}
	if(SpanLeft)
	{
		delete []SpanLeft;
		SpanLeft = NULL;
	}
	if(SpanRight)
	{
		delete []SpanRight;
		SpanRight = NULL;
	}
}

void CTriangle::DDA(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature)
{
	int dx = PEnd.x - PStart.x;
	int dy = PEnd.y - PStart.y;
	double m = double(dx)/dy;
	double x =  PStart.x;
	for(int y = PStart.y; y < PEnd.y; y++)
	{
		CRGB crColor = LinearInterp(y, PStart.y, PEnd.y, PStart.c, PEnd.c);
		if(bFeature)
			SpanLeft[nIndex++] = CPoint2(ROUND(x), y, crColor);
		else
			SpanRight[nIndex++] = CPoint2(ROUND(x), y, crColor);
		x += m;
	}
}

void CTriangle::SortVertex()
{
	CPoint2 pt[3];
	pt[0] = point0;
	pt[1] = point1;
	pt[2] = point2;
	for(int i = 0; i < 2; i++)
	{
		int min = i;
		for(int j = i + 1; j < 3; j++)
			if(pt[j].y < pt[min].y)
				min = j;
		CPoint2 pTemp = pt[i];
		pt[i] = pt[min];
		pt[min] = pTemp;
	}
	point0 = pt[0];
	point1 = pt[2];
	point2 = pt[1];
}

CRGB CTriangle::LinearInterp(double t, double tStart, double tEnd, CRGB cStart, CRGB cEnd)//颜色线性插值
{
	CRGB color;
	color = (tEnd - t) / (tEnd - tStart) * cStart + (t - tStart) / (tEnd - tStart) * cEnd;
	return color;
}