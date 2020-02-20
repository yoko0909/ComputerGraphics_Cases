#include "StdAfx.h"
#include "T2.h"
#include "math.h"


CT2::CT2(void)
{
	u = 0;
	v = 0;
}

CT2::CT2(double u, double v)
{
	this->u = u;
	this->v = v;
}

CT2::~CT2(void)
{

}

CT2 operator + (const CT2 &t0, const CT2 &t1)//和
{	
	CT2 result;
	result.u = t0.u + t1.u;
	result.v = t0.v + t1.v;
	return result;
}

CT2 operator - (const CT2 &t0, const CT2 &t1)//差
{
	CT2 result;
	result.u = t0.u - t1.u;
	result.v = t0.v - t1.v;
	return result;
}

CT2 operator * (const CT2 &t, double scalar)//点和常量的积
{	
	return CT2(t.u * scalar, t.v * scalar);
}

CT2 operator * (double scalar, const CT2 &t)//常量和点的积
{	
	return CT2(t.u * scalar, t.v * scalar);
}

CT2 operator / (const CT2 &t,double scalar)//数除
{
	if(fabs(scalar) < 1e-4)
		scalar = 1.0;
	CT2 result;
	result.u = t.u/scalar;
	result.v = t.v/scalar;
	return result;
}

CT2 operator += (CT2 &t0, CT2 &t1)
{
	t0.u = t0.u + t1.u;
	t0.v = t0.v + t1.v;
	return t0;
}

CT2 operator -= (CT2 &t0, CT2 &t1)
{
	t0.u = t0.u - t1.u;
	t0.v = t0.v - t1.v;
	return t0;
}

CT2 operator *= (CT2 &t, double scalar)
{
	t.u = t.u * scalar;
	t.v = t.v * scalar;
	return t;
}

CT2 operator /= (CT2 &t, double scalar)
{
	if(fabs(scalar) < 1e-4)
		scalar = 1.0;
	t.u = t.u/scalar;
	t.v = t.v/scalar;
	return t;
}

