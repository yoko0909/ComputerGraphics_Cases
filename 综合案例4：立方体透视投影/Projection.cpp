#include "StdAfx.h"
#include "Projection.h"
#include "math.h"
#define PI 3.1415926


CProjection::CProjection(void)
{
	R = 1200, d = 800, Phi = 90.0, Psi = 0.0;//视点位于正前方
	InitialParameter();
}


CProjection::~CProjection(void)
{
}

void CProjection::InitialParameter()//透视变换参数初始化
{
	k[0] = sin(PI * Phi / 180);//Phi代表φ
	k[1] = cos(PI * Phi / 180);
	k[2] = sin(PI * Psi / 180);//Psi代表ψ
	k[3] = cos(PI * Psi / 180);
	k[4] = k[0] * k[2];
	k[5] = k[0] * k[3];
	k[6] = k[1] * k[2];
	k[7] = k[1] * k[3];
	EyePoint.x = R * k[4];// EyePoint代表视点
	EyePoint.y = R * k[1];// R为视径
	EyePoint.z = R * k[5];
}

CP2 CProjection::PerspectiveProjection(CP3 WorldPoint)//透视投影
{
	CP3 ViewPoint;//观察坐标系三维点
	ViewPoint.x = k[3] * WorldPoint.x - k[2] * WorldPoint.z;
	ViewPoint.y =-k[6] * WorldPoint.x + k[0] * WorldPoint.y - k[7] * WorldPoint.z;
	ViewPoint.z =-k[4] * WorldPoint.x - k[1] * WorldPoint.y - k[5] * WorldPoint.z + R;
    CP2 ScreenPoint;//屏幕坐标系二维点
	ScreenPoint.x = d * ViewPoint.x / ViewPoint.z; 
	ScreenPoint.y = d * ViewPoint.y / ViewPoint.z; 
    return ScreenPoint;
}

CP2 CProjection::OrthogonalProjection(CP3 WorldPoint)//正交投影
{
	CP2 ScreenPoint;
    ScreenPoint.x = WorldPoint.x;
	ScreenPoint.y = WorldPoint.y;
	return ScreenPoint;
}

CP2 CProjection::CavalierProjection(CP3 WorldPoint)//斜等测投影
{
	CP2 ScreenPoint;
	double Alpha = 45 * PI / 180;
   	ScreenPoint.x = WorldPoint.x - WorldPoint.z * cos(Alpha);
	ScreenPoint.y = WorldPoint.y - WorldPoint.z * cos(Alpha);
	return ScreenPoint;
}

CP2 CProjection::CabinetProjection(CP3 WorldPoint)//斜二测投影
{
	CP2 ScreenPoint;
	double Alpha = 45 * PI / 180;
    ScreenPoint.x = WorldPoint.x - WorldPoint.z / 2 * cos(Alpha);
	ScreenPoint.y = WorldPoint.y - WorldPoint.z / 2 * cos(Alpha);
	return ScreenPoint;
}