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
	void SetFresnel(double f);//设置材质的菲涅尔反射系数
	void SetRoughness(double k);//设置材质的粗糙度
public:
	CRGB M_Ambient;//环境光的反射率
	CRGB M_Diffuse;//漫反射光的反射率
	CRGB M_Specular;//镜面反射光的反射率
	CRGB M_Emission;//自身辐射的颜色
	double M_f;//fresnel反射率
	double M_k;//斜率描述的粗糙度
};