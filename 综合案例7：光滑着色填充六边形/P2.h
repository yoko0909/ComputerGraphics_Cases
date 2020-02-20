#pragma once
#include "RGB.h"

class CP2
{
public:
	CP2(void);	
	CP2(double x, double y);
	CP2(double x, double y, CRGB c);
	virtual ~CP2(void);
	friend CP2 operator + (const CP2 &p1, const CP2 &p2);//‘ÀÀ„∑˚÷ÿ‘ÿ
	friend CP2 operator - (const CP2 &p1, const CP2 &p2);
	friend CP2 operator * (const CP2 &p, double scalar);
	friend CP2 operator * (double scalar, const CP2 &p);
	friend CP2 operator / (const CP2 &p, double scalar);
public:
	double x;
	double y;
	CRGB c;
};

