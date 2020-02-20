#include "StdAfx.h"
#include "Line.h"


CLine::CLine(void)
{

}

CLine::~CLine(void)
{

}

void CLine::MoveTo(CDC* pDC, int x0, int y0, COLORREF c0)
{
	this->x0 = x0;
	this->y0 = y0;
	this->c0 = c0;
}

void CLine::LineTo(CDC* pDC, int x1, int y1, COLORREF c1)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	bool bInterChange = false;
	int e, signX, signY, temp;
    signX = (x1 > x0) ? 1 :((x1 < x0) ? -1 : 0);
  	signY = (y1 > y0) ? 1 :((y1 < y0) ? -1 : 0);
	if(dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
        bInterChange = true;
	}
	e = -dx;
	int x = x0 , y  = y0;
	//double dr = (GetRValue(c1) - GetRValue(c0)) / double(dx);
	//double dg = (GetGValue(c1) - GetGValue(c0)) / double(dx);
	//double db = (GetBValue(c1) - GetBValue(c0)) / double(dx);
	for (int i = 1; i <= dx; i++)
	{
		double r = (i - 1) / double(dx) * GetRValue(c0) + (dx - i) / double(dx) * GetRValue(c1);
		double g = (i - 1) / double(dx) * GetGValue(c0) + (dx - i) / double(dx) * GetGValue(c1);
		double b = (i - 1) / double(dx) * GetBValue(c0) + (dx - i) / double(dx) * GetBValue(c1); 

		COLORREF  clr = RGB(r, g, b);
		pDC->SetPixelV(x, y, clr);
		if(bInterChange)
			y += signY;
		else 
			x += signX;
		e += 2 * dy;
		if(e >= 0)
		{
			if(bInterChange)
				x += signX;
			else
				y += signY;
            e -= 2 * dx;
		}
	}
}