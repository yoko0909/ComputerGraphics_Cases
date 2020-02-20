#pragma once
#include"Facet.h"
#include "P3.h"

class CSphere
{
public:
	CSphere(void);
	virtual ~CSphere(void);
	void SetptCenter(CP3 ptCenter);
	void ReadVertex(void);	//读入点表
	void ReadFacet(void);	//读入面表
	void Draw(CDC* pDC);	//绘制图形
public:
	CP3* P;			//点表
	int N1, N2;		//N1为纬度区域,N2为经度区域
	CFacet** F;		//面表
	CP3 ptCenter;	//中心点
};

