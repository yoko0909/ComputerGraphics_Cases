#include "StdAfx.h"
#include "Ray.h"
#include <math.h>

CRay::CRay(void)
{
}

CRay::~CRay(void)
{
}

CRay::CRay(CVector3 Origin, CVector3 Direction)
{
	this->Origin = Origin;
	this->Direction = Direction;
}

CP3 CRay::GetPoint(double t)
{
	CP3 point;
	point.x = Origin.x + t * Direction.x;
	point.y = Origin.y + t * Direction.y;
	point.z = Origin.z + t * Direction.z;
	return point;
}

