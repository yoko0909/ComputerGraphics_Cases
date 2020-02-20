#pragma once
#include "GeometricObject.h"
#include "Equation.h"  //引用求解一元四次方程类

class CTorus:public CGeometricObject//圆环体类
{
public:
	CTorus(void);
	virtual ~CTorus(void);
	CTorus(CP3 Center,double R, double r, CMaterial Material);
	BOOL Hit(CRay Ray, CIntersection &Hit);//光线碰撞检测函数
	CVector3 ComputeNormal(const CP3& p) const;//计算法向量函数
public:
	double R;//扫掠半径
	double r;//管状半径
	CEquation equation;//求解一元四次方程对象
	CP3 Center;//圆环体环心坐标
};

