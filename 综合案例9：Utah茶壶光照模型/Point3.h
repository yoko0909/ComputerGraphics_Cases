#pragma once
#include "Point2.h"

class CPoint3 : public CPoint2
{
public:
	CPoint3(void);
	CPoint3(int x, int y, double z);
	virtual ~CPoint3(void);
public:
	double z;
};