#include "StdAfx.h"
#include "Point2.h"
#include <math.h>

CPoint2::CPoint2(void)
{
	x = 0;
	y = 0;
	c = CRGB(0, 0, 0);
}

CPoint2::CPoint2(int x, int y)
{
	this->x = x;
	this->y = y;
	c = CRGB(0, 0, 0);
}

CPoint2::CPoint2(int x, int y, CRGB c)
{
	this->x = x;
	this->y = y;
	this->c = c;
}

CPoint2::~CPoint2(void)
{
}

CPoint2 operator + (const CPoint2 &pt0, const CPoint2 &pt1)//和
{	
	CPoint2 point;
	point.x = pt0.x + pt1.x;
	point.y = pt0.y + pt1.y;
	return point;
}

CPoint2 operator - (const CPoint2 &pt0, const CPoint2 &pt1)//差
{
	CPoint2 point;
	point.x = pt0.x - pt1.x;
	point.y = pt0.y - pt1.y;
	return point;
}

CPoint2 operator * (const CPoint2 &pt, int scalar)//点和常量的积
{	
	return CPoint2(pt.x * scalar, pt.y * scalar);
}

CPoint2 operator * (int scalar, const CPoint2 &pt)//点和常量的积
{	
	return CPoint2(pt.x * scalar, pt.y * scalar);
}

CPoint2 operator / (const CPoint2 &pt, double scalar)//数除
{
	if(fabs(scalar) < 1e-4)
		scalar = 1.0;
	CPoint2 point;
	point.x = int(pt.x / scalar);
	point.y = int(pt.y / scalar);
	return point;
}
