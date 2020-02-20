#pragma once
#include "p2.h"

class CP3 : public CP2
{
public:
	CP3(void);
	virtual ~CP3(void);
	CP3(double x, double y, double z);
	friend CP3 operator + (const CP3 &p0, const CP3 &p1);//‘ÀÀ„∑˚÷ÿ‘ÿ
	friend CP3 operator - (const CP3 &p0, const CP3 &p1);
	friend CP3 operator * (const CP3 &p, double scalar);
	friend CP3 operator * (double scalar, const CP3 &p);
	friend CP3 operator / (const CP3 &p, double scalar);
	friend CP3 operator += (CP3 &p0, CP3 &p1);
	friend CP3 operator -= (CP3 &p0, CP3 &p1);
	friend CP3 operator *= (CP3 &p, double scalar);
	friend CP3 operator /= (CP3 &p, double scalar);
public:
	double z;
};

