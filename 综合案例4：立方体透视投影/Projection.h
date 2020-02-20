#pragma once
#include "P3.h"
class CProjection
{
public:
	CProjection(void);
	virtual ~CProjection(void);
	void InitialParameter(void);//透视投影参数初始化
	CP2 PerspectiveProjection(CP3 WorldPoint);//透视投影
	CP2 OrthogonalProjection(CP3 WorldPoint);//正交投影
	CP2 CavalierProjection(CP3 WorldPoint);//斜等测投影
	CP2 CabinetProjection(CP3 WorldPoint);//斜二测投影
public:
	CP3 EyePoint;//视点
private:
	double k[8];//透视投影常数
	double R, Psi, Phi,d;//视点的球坐标
};

