#pragma once
#include "P3.h"

class CVector3
{
public:
	CVector3(void);
	virtual ~CVector3(void);
	CVector3(double x, double y, double z);//绝对向量
	CVector3(const CP3 &vertex);
	CVector3(const CP3 &Vertex0, const CP3 &Vertex1);//相对向量
	double Magnitude(void);//计算向量的模
	CVector3 Normalize(void);//规范化向量
	friend CVector3 operator + (const CVector3 &v0, const CVector3 &v1);//运算符重载
	friend CVector3 operator - (const CVector3 &v0, const CVector3 &v1);
	friend CVector3 operator * (const CVector3 &v, double scalar);
	friend CVector3 operator * (double scalar, const CVector3 &v);
	friend CVector3 operator / (const CVector3 &v, double scalar);
	friend double DotProduct(const CVector3 &v0, const CVector3 &v1);//计算向量的点积
	friend CVector3 CrossProduct(const CVector3 &v0, const CVector3 &v1);//计算向量的叉积
public:
	double x, y, z;
};

