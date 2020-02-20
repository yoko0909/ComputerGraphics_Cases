#pragma once
#include "Vector3.h"

class CRay//光线类
{
public:
	CRay(void);
	virtual ~CRay(void);
	CRay(CVector3 Origin, CVector3 Direction);//构造光线函数	
	CP3 GetPoint(double t);//计算交点函数
public:
	CVector3 Origin;//光线的源点
	CVector3 Direction;//光线的方向
};

