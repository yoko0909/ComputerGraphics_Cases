#pragma once
#include "Ray.h"
#include "Material.h"

class CIntersection: public CRay//碰撞点类
{
public:
	CIntersection(void);
	virtual ~CIntersection(void);	
public:
	double t;//交点处光线的参数t
	CP3 Point; //碰撞点坐标
    CVector3  Normal;//碰撞点的法向量
	CMaterial Material;//碰撞点的材质 
};

