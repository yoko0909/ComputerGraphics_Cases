#pragma once
#include "RGB.h"

class CPoint2
{
public:
	CPoint2(void);	
	CPoint2(int x, int y);
	CPoint2(int x, int y, CRGB c);
	virtual ~CPoint2(void);
	friend CPoint2 operator + (const CPoint2 &pt0, const CPoint2 &pt1);//‘ÀÀ„∑˚÷ÿ‘ÿ
	friend CPoint2 operator - (const CPoint2 &pt0, const CPoint2 &pt1);
	friend CPoint2 operator * (const CPoint2 &pt, double scalar);
	friend CPoint2 operator * (int scalar, const CPoint2 &pt);
	friend CPoint2 operator / (const CPoint2 &pt, int scalar);	
public:
	int x; 
	int y;
	CRGB c;	

};

