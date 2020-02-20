#pragma once
#include "GeometricObject.h"

class CSphere:public CGeometricObject//球类
{
public:
	CSphere(void);
	virtual ~CSphere(void);
	CSphere(double Radius, CP3 Center, CMaterial Material);//球体构造函数
    BOOL Hit(CRay Ray,CIntersection &Hit);//光线碰撞检测函数
public:
	double Radius;//球体半径
	CP3 Center;//球心坐标
};