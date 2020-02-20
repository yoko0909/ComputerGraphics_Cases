#include "StdAfx.h"
#include "P2.h"
#include <math.h>

CP2::CP2(void)
{
	x = 0.0;
	y = 0.0;
	c = CRGB(0, 0, 0);
}

CP2::CP2(double x,double y)
{
	this->x = x;
	this->y = y;
	c = CRGB(0, 0, 0);
}

CP2::CP2(double x, double y, CRGB c)
{
	this->x = x;
	this->y = y;
	this->c = c;
}

CP2::~CP2(void)
{
}

CP2 operator + (const CP2 &p1, const CP2 &p2)//和
{	
	CP2 p;
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	return p;
}

CP2 operator - (const CP2 &p1, const CP2 &p2)//差
{
	CP2 p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}

CP2 operator * (const CP2 &p, double scalar)//点和常量的积
{	
	return CP2(p.x * scalar, p.y * scalar);
}

CP2 operator * (double scalar, const CP2 &p)//点和常量的积
{	
	return CP2(p.x * scalar, p.y * scalar);
}

CP2 operator / (const CP2 &p1, double scalar)//数除
{
	if(fabs(scalar) < 1e-4)
		scalar = 1.0;
	CP2 p;
	p.x = p1.x / scalar;
	p.y = p1.y / scalar;
	return p;
}


