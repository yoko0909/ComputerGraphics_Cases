#include "StdAfx.h"
#include "Point3.h"


CPoint3::CPoint3(void)
{
}

CPoint3::CPoint3(int x, int y, double z):CPoint2(x, y)
{
	this->z = z;
}

CPoint3::~CPoint3(void)
{
}
