#pragma once
#include"RGB.h"

class CT2  
{
public:
	CT2(void);
	virtual ~CT2(void);
	CT2(double u, double v);
	friend CT2 operator + (const CT2 &t0, const CT2 &t1);//‘ÀÀ„∑˚÷ÿ‘ÿ
	friend CT2 operator - (const CT2 &t0, const CT2 &t1);
	friend CT2 operator * (const CT2 &t, double scalar);
	friend CT2 operator * (double scalar, const CT2 &t);
	friend CT2 operator / (const CT2 &t,double scalar);
	friend CT2 operator += (CT2 &t0, CT2 &t1);
	friend CT2 operator -= (CT2 &t0, CT2 &t1);
	friend CT2 operator *= (CT2 &t, double scalar);
	friend CT2 operator /= (CT2 &t, double scalar);
public:
	double u, v;
	CRGB c;
};

