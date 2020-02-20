#include "StdAfx.h"
#include "P3.h"


CP3::CP3(void)
{
	x=0,y=0,z=0,w=1;
}

CP3::CP3(double x,double y,double z):CP2(x,y)
{
	this->z=z;
}

CP3::~CP3(void)
{
}

CP3 operator += (CP3 &p0, CP3 &p1)
{
	p0.x = p0.x + p1.x;
	p0.y = p0.y + p1.y;
	p0.z = p0.z + p1.z;
	return p0;
}

