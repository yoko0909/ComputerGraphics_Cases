#pragma once

class CEquation//方程类
{
public:
	CEquation(void);
	virtual ~CEquation(void);
	int SolveQuadric(double c[3], double s[2]);//求解一元二次方程
	int SolveCubic(double c[4], double s[3]);//求解一元三次方程
	int SolveQuartic(double c[5], double s[4]);//求解一元四次方程
};

