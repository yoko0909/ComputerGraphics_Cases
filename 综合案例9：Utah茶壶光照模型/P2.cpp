#include "StdAfx.h"
#include "P2.h"
#include<math.h>

CP2::CP2(void)
{
	x = 0.0, y = 0.0, w = 1.0;
	c = CRGB(0.5, 0.4, 0.0);
}

CP2::CP2(double x,double y,CRGB c)
{
	this->x = x;
	this->y = y; 
	this->w = 1.0;
	this->c = c;
}

CP2::CP2(double x,double y)
{
	this->x = x;
	this->y = y;
	this->w = 1.0;
	this->c = CRGB(1.0,1.0,1.0);
}

CP2::~CP2(void)
{
	
}

CP2 operator + (const CP2 &p0, const CP2 &p1)//和
{	
	CP2 result;
	result.x = p0.x + p1.x;
	result.y = p0.y + p1.y;
	return result;
}

CP2 operator - (const CP2 &p0, const CP2 &p1)//差
{
	CP2 result;
	result.x = p0.x - p1.x;
	result.y = p0.y - p1.y;
	return result;
}

CP2 operator * (const CP2 &p, double scalar)//点和常量的积
{	
	return CP2(p.x * scalar, p.y * scalar);
}

CP2 operator * (double scalar, const CP2 &p)//常量和点的积
{	
	return CP2(p.x * scalar,p.y * scalar);
}

CP2 operator / (const CP2 &p, double scalar)//数除
{
	if(fabs(scalar) < 1e-4)
		scalar = 1.0;
	CP2 result;
	result.x = p.x / scalar;
	result.y = p.y / scalar;
	return result;
}

CP2 operator += (CP2 &p0, CP2 &p1)
{
	p0.x += p1.x;
	p0.y += p1.y;
	return p0;
}

CP2 operator-=(CP2 &p0, CP2 &p1)
{
	p0.x -= p1.x;
	p0.y -= p1.y;
	return p0;
}

CP2 operator *= (CP2 &p, double scalar)
{
	p.x *= scalar;
	p.y *= scalar;
	return p;
}

CP2 operator /= (CP2 &p, double scalar)
{
	if(fabs(scalar) < 1e-4)
		scalar = 1.0;
	p.x /= scalar;
	p.y /= scalar;
	return p;
}