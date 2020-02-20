#include "StdAfx.h"
#include "Intersection.h"

CIntersection::CIntersection(void)
{
	t = 100000;
    Point = CP3(0,0,0);
    Normal = CVector3(0,0,0);
}

CIntersection::~CIntersection(void)
{
}
