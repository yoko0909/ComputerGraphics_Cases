#pragma once
#include "P2.h"

class CP3 :public CP2
{
public:
	CP3();
	virtual ~CP3();
	CP3(double, double, double);
	friend CP3 operator +(const CP3 &, const CP3 &);//运算符重载
	friend CP3 operator -(const CP3 &, const CP3 &);
	friend CP3 operator *(const CP3 &, double);
	friend CP3 operator *(double, const CP3 &);
	friend CP3 operator /(const CP3 &, double);
	friend CP3 operator+=(CP3 &, CP3 &);
	friend CP3 operator-=(CP3 &, CP3 &);
	friend CP3 operator*=(CP3 &, double);
	friend CP3 operator/=(CP3 &, double);
	friend BOOL operator!=(CP3 &, CP3 &);
	friend BOOL operator==(CP3 &, CP3 &);
	double Mag();//长度
public:
	double z;
};