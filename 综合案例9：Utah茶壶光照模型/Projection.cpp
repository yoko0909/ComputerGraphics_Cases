#include "StdAfx.h"
#include "Projection.h"
#include "math.h"
#define PI 3.1415926


CProjection::CProjection(void)
{
	R = 1200, d = 800, Phi = 80.0, Psi = 0.0;//视点位于正前方
	InitialParameter();
}

CProjection::~CProjection(void)
{
}

void CProjection::InitialParameter(void)//透视变换参数初始化
{
	k[0] = sin(PI * Phi / 180);//Phi代表φ
	k[1] = cos(PI * Phi / 180);
	k[2] = sin(PI * Psi / 180);//Psi代表ψ
	k[3] = cos(PI * Psi / 180);
	k[4] = k[0] * k[2];
	k[5] = k[0] * k[3];
	k[6] = k[1] * k[2];
	k[7] = k[1] * k[3];
	EyePoint.x = R * k[4];//设置视点	
	EyePoint.y = R * k[1];
	EyePoint.z = R * k[5];
}
   
CP3 CProjection::PerspectiveProjection(CP3 WorldPoint)
{
	CP3 ViewPoint;//观察坐标系三维点
	ViewPoint.x = k[3] * WorldPoint.x - k[2] * WorldPoint.z; 
	ViewPoint.y =-k[6] * WorldPoint.x + k[0] * WorldPoint.y - k[7] * WorldPoint.z;
    ViewPoint.z =-k[4] * WorldPoint.x - k[1] * WorldPoint.y - k[5] * WorldPoint.z + R;
	ViewPoint.c = WorldPoint.c;
    CP3 ScreenPoint;//屏幕坐标系三维点
	ScreenPoint.x = d * ViewPoint.x / ViewPoint.z; 
	ScreenPoint.y = d * ViewPoint.y / ViewPoint.z;
	ScreenPoint.z = (ViewPoint.z - d) * d/ViewPoint.z;//Bouknight公式;
	ScreenPoint.c = ViewPoint.c;
	return ScreenPoint;
}

CP3 CProjection::OrthogonalProjection(CP3 WorldPoint)//正交投影
{
	CP3 ScreenPoint;//屏幕坐标系三维点
	ScreenPoint.x = WorldPoint.x;
	ScreenPoint.y = WorldPoint.y;
	ScreenPoint.z =-WorldPoint.z;
	ScreenPoint.c = WorldPoint.c;
	return ScreenPoint;
}
