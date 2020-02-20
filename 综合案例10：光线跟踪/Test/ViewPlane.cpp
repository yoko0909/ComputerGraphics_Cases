#include "StdAfx.h"
#include "ViewPlane.h"


CViewPlane::CViewPlane(void)
{	 
}

CViewPlane::~CViewPlane(void)
{
}

void CViewPlane::SetResolution(int HorRes, int VerRes)
{
	this->HorRes = HorRes;//屏幕新水平分辨率
	this->VerRes = VerRes;//屏幕新垂直分辨率
}

void CViewPlane::SetSampleNumber(int SampleNumber)
{
	this->SampleNumber = SampleNumber;//采样率
}


