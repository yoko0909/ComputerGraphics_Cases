#pragma once
#include "RGB.h"

class CMaterial
{
public:
	CMaterial(void);
	virtual~CMaterial(void);
	void SetAmbient(CRGB c);//设置环境光的反射率	
	void SetDiffuse(CRGB c);//设置漫反射光的反射率
	void SetSpecular(CRGB c);//设置镜面反射光的反射率
	void SetEmission(CRGB c);//设置自身辐射的颜色
	void SetExponent(double n);//设置高光指数
public:
	CRGB M_Ambient;//环境光的反射率
	CRGB M_Diffuse;//漫反射光的反射率
	CRGB M_Specular;//镜面反射光的反射率
	CRGB M_Emission;//自身辐射的颜色
	double M_n;//高光指数
	double M_eta;//材质的折射率
};