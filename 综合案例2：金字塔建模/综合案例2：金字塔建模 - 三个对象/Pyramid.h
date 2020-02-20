#pragma once
#include "P3.h"
#include"Facet.h"

class CPyramid
{
public:
	CPyramid(void);
	virtual ~CPyramid(void);
	void ReadVertex(void);//读入点表
	void ReadFacet(void);//读入面表
	void Draw(CDC* pDC);//绘制图形
public:
	CP3 P[5];//点表
	CFacet F[5];//面表
};

