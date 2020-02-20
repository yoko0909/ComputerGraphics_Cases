#include "StdAfx.h"
#include "Pyramid.h"
#include <math.h>//包含数学头文件
#define  PI 3.1415926//PI的宏定义
#define ROUND(d) int(d + 0.5)//四舍五入宏定义

CPyramid::CPyramid(void)
{
}


CPyramid::~CPyramid(void)
{

}

void CPyramid::ReadVertex(void)//点表
{
	P[0].x = -0.5, P[0].y = 0.0, P[0].z =  0.5;
	P[1].x =  0.5, P[1].y = 0.0, P[1].z =  0.5;
	P[2].x =  0.5, P[2].y = 0.0, P[2].z = -0.5;
	P[3].x = -0.5, P[3].y = 0.0, P[3].z = -0.5;
	P[4].x =  0.0, P[4].y = 1.0, P[4].z =  0.0;
}

void CPyramid::ReadFacet(void)//面表
{
	F[0].Number = 3, F[0].Index[0] = 0, F[0].Index[1] = 1, F[0].Index[2] = 4;
	F[1].Number = 3, F[1].Index[0] = 1, F[1].Index[1] = 2, F[1].Index[2] = 4;
	F[2].Number = 3, F[2].Index[0] = 2, F[2].Index[1] = 3, F[2].Index[2] = 4;
	F[3].Number = 3, F[3].Index[0] = 0, F[3].Index[1] = 4, F[3].Index[2] = 3;
	F[4].Number = 4, F[4].Index[0] = 0, F[4].Index[1] = 3, F[4].Index[2] = 2, F[4].Index[3] = 1;
}

void CPyramid::Draw(CDC* pDC)
{
	for(int nFacet = 0; nFacet < 5; nFacet++)//面循环
	{
		CP2 ScreenPoint,temp;
		for(int nPoint = 0; nPoint < F[nFacet].Number; nPoint++)//顶点循环
		{
			ScreenPoint.x = P[F[nFacet].Index[nPoint]].x;
			ScreenPoint.y = P[F[nFacet].Index[nPoint]].y;
			if(0 == nPoint)
			{
				pDC->MoveTo(ROUND(ScreenPoint.x), ROUND(ScreenPoint.y));
				temp = ScreenPoint;
			}
			else
			{
				pDC->LineTo(ROUND(ScreenPoint.x), ROUND(ScreenPoint.y));
			}
		}
		pDC->LineTo(ROUND(temp.x), ROUND(temp.y));//闭合四边形
	}
}
