#include "StdAfx.h"
#include "Torus.h"

CTorus::CTorus(void)
{
}

CTorus::~CTorus(void)
{
}

CTorus::CTorus(CP3 Center,double R, double r, CMaterial Material)
{
	this->R = R;
	this->r = r;
	this->Material = Material;
	this->Center = Center;
}
CVector3 CTorus::ComputeNormal(const CP3 &p) const 
{
	CVector3 Normal;
	double parameter = R * R + r * r;
	double x = p.x - Center.x;
	double y = p.z - Center.z;
	double z = p.y - Center.y;
	double sum = x * x + y * y + z * z;	
	Normal.x = 4.0 * x * (sum - parameter);
	Normal.y = 4.0 * z * (sum - parameter); 
	Normal.z = 4.0 * y * (sum - parameter + 2.0 * R * R);
	Normal.Normalize();
	return Normal;
}

BOOL CTorus::Hit(CRay Ray, CIntersection &Hit)//计算光线与圆环体的交点
{
	CVector3 VectorO(Center);//环心位置向量
	double ox = Ray.Origin.x - VectorO.x; 
	double oy = Ray.Origin.z - VectorO.z; 
	double oz = Ray.Origin.y - VectorO.y;
	double dx = Ray.Direction.x; 
	double dy = Ray.Direction.z;
	double dz = Ray.Direction.y;
	double coefficient[5];//五个系数
	double root[4];//四个根
	double sum 	= dx * dx + dy * dy + dz * dz;
	double e = ox * ox + oy * oy + oz * oz - R * R - r * r;
	double f = ox * dx + oy * dy + oz * dz;
	double g = 4.0 * R * R;
	coefficient[0] = e * e - g * (r * r - oy * oy);//常数项
	coefficient[1] = 4.0 * f * e + 2.0 * g * oy * dy;
	coefficient[2] = 2.0 * sum * e + 4.0 * f * f + g * dy * dy;
	coefficient[3] = 4.0 * sum * f;
	coefficient[4] = sum * sum;
	int NumofRoots = equation.SolveQuartic(coefficient, root);
	BOOL bIntersected = FALSE;
	double 	t = HugeValue;
	if(NumofRoots  == 0)  
		return FALSE;
	for(int j = 0; j < NumofRoots; j++)  
		if(root[j] > Epsilon)
		{
			bIntersected = TRUE;
			if (root[j] < t)
				t = root[j];
		}
	if(!bIntersected)
		return FALSE;
	Hit.t = t;
	Hit.Point = Ray.GetPoint(Hit.t);//交点坐标
	Hit.Normal= ComputeNormal(Hit.Point);
	Hit.Material = Material;
	return TRUE;
}