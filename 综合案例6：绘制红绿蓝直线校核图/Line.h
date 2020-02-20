#pragma once


class CLine
{
public:
	CLine(void);
	virtual ~CLine(void);
	void MoveTo(CDC* pDC, int x0, int y0, COLORREF c0);
	void LineTo(CDC* pDC, int x1, int y1, COLORREF c1);
private:
	int x0, y0;//起点坐标
	COLORREF c0;//起点颜色
	int x1, y1;//终点坐标
	COLORREF c1;//终点颜色	
};

