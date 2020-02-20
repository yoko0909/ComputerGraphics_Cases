#pragma once
#include"Projection.h"
#include"Facet.h"

class CCube
{
public:
	CCube(void);
	virtual ~CCube(void);
	void ReadVertex(void);//读入点表
	void ReadFacet(void);//读入面表
	void Draw(CDC* pDC);//绘制图形	
public:	
	CP3 P[8];//点表
private:
	CFacet F[6];//面表
	CProjection projection;//投影
};

