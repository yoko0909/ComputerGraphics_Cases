#pragma once
#include "LightSource.h"
#include "Material.h"
#include "Vector3.h"

class CLighting
{
public:
	CLighting(void);
	CLighting(int nLightNumber);
	virtual ~CLighting(void);
	void SetLightNumber(int nLightNumber);//设置光源数量
	CRGB Illuminate(CP3 ViewPoint, CP3 Point, CVector3 ptNormal, CMaterial* pMaterial);//计算光照	
public:
	int nLightNumber;//光源数量
	CLightSource* LightSource;//光源数组
	CRGB Ambient;//环境光
};