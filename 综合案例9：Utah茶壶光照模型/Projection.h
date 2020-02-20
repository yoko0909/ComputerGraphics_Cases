#pragma once
#include "P3.h"

class CProjection
{
public:
	CProjection(void);
	virtual ~CProjection(void);
	void InitialParameter(void);
	CP3 PerspectiveProjection(CP3 WorldPoint);//透视投影
	CP3 OrthogonalProjection(CP3 WorldPoint);//正交投影	
public:
	CP3 EyePoint;//视点
private:
	double k[8];//透视投影常数
	double R, Phi, Psi, d;//视点球坐标
};

