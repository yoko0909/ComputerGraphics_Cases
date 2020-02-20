#include "stdafx.h"
#include "Sphere.h"
#include <math.h>

CSphere::CSphere(void)
{
}

CSphere::~CSphere(void)
{
}

CSphere::CSphere(double Radius, CP3 Center, CMaterial Material)
{
	this->Radius = Radius;
	this->Center = Center;
	this->Material = Material;
} 

BOOL CSphere::Hit(CRay Ray, CIntersection &Hit) //获取光线与球体的交点
{
	CVector3 VectorC(Center);//定义球心位置向量
	CVector3 VectorCO = Ray.Origin - VectorC;// VectorCO为从球心指向光线起点的向量
	double A = DotProduct(Ray.Direction,Ray.Direction); 
	double B = 2 * DotProduct(VectorCO , Ray.Direction); 
	double C = DotProduct(VectorCO , VectorCO) - Radius * Radius;
	double D = B * B - 4 * A * C;
	if (D >= 0)
	{
		double t0 = (-B - sqrt(D)) / (2 * A);
		double t1 = (-B + sqrt(D)) / (2 * A);
		if (t0 > Epsilon)
		{
			Hit.t = t0;
			Hit.Point = Ray.GetPoint(Hit.t);//交点坐标
            Hit.Normal = CVector3(Center, Hit.Point);//交点的法向量
		}
		else if (fabs(t0) < Epsilon && t1 > Epsilon)
		{
			Hit.t = t1;
			Hit.Point = Ray.GetPoint(Hit.t);
            Hit.Normal = CVector3(Hit.Point, Center);//交点的法向量		
		}
		else
			return FALSE;
	    Hit.Material = Material;
		return TRUE;
	}
	return FALSE;
}