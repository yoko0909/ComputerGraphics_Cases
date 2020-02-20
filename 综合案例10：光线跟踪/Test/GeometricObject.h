#pragma once
#include "Intersection.h"
#include "Material.h"

#define Epsilon 0.001
#define HugeValue 100000

class CGeometricObject//几何对象类
{
public:
	CGeometricObject(void);
	virtual ~CGeometricObject(void);
	virtual BOOL Hit(CRay Ray, CIntersection &Hit) = 0;//光线碰撞检测函数
public:
	CMaterial Material;  //每个物体的材质
};

