#include "StdAfx.h"
#include "Lighting.h"
#include <math.h>
#define  PI 3.14159265


CLighting::CLighting(void)
{
	nLightNumber = 1;
	LightSource = new CLightSource[nLightNumber];
	Ambient = CRGB(0.3, 0.3, 0.3);//环境光是常数
}

CLighting::~CLighting(void)
{
	if (LightSource)
	{
		delete []LightSource;
		LightSource = NULL;
	}
}

void CLighting::SetLightNumber(int nLightNumber)
{
	if(LightSource)
		delete []LightSource;
	this->nLightNumber = nLightNumber;
	LightSource = new CLightSource[nLightNumber];
}

CLighting::CLighting(int nLightNumber)
{
	this->nLightNumber = nLightNumber;
	LightSource = new CLightSource[nLightNumber];
	Ambient = CRGB(0.3, 0.3, 0.3);
}

CRGB CLighting::Illuminate(CP3 ViewPoint, CP3 Point, CVector3 ptNormal, CMaterial* pMaterial)
{	
	CRGB ResultI = CRGB(0.0,0.0,0.0);// 初始化“最终”光强
	for(int loop = 0; loop < nLightNumber; loop++)//检查光源开关状态
	{	
		if(LightSource[loop].L_OnOff)//光源开
		{		
			CRGB I = CRGB(0.0, 0.0, 0.0);// I代表“反射”光强
			CVector3 L(Point, LightSource[loop].L_Position);// L为入射光向量
			double d = L.Magnitude();// d为入射光传播的距离 
			L = L.Normalize();//规范化入射光向量
			CVector3 N = ptNormal;
			N = N.Normalize();//规范化法向量
			//第1步，加入漫反射光
			double NdotL = max(DotProduct(N, L), 0);
			I += LightSource[loop].L_Diffuse * pMaterial->M_Diffuse * NdotL;
			//第2步，加入镜面反射光,Cook-Torrance模型
			CVector3 V(Point, ViewPoint);//V为视向量
			V = V.Normalize();//规范化视向量
			CVector3 H = (L + V).Normalize();//H为中分向量
			double NdotH = max(DotProduct(N, H), 0);//N与H的点积
			double NdotV = max(DotProduct(N, V), 0);//N与V的点积
			double VdotH = max(DotProduct(V, H), 0);//V与H的点积
			if(NdotL > 0.0 && NdotV > 0.0)
			{
				double F = pMaterial->M_f + (1.0 - pMaterial->M_f) * pow(1 - VdotH, 5.0);//fresnel项
				double r1 = 1.0 / (pMaterial->M_k * pMaterial->M_k * pow(NdotH, 4.0));
				double r2 = (NdotH * NdotH - 1.0) / (pMaterial->M_k * pMaterial->M_k * NdotH * NdotH);
				double D = r1 * exp(r2);//beckmann分布函数
				double Gm = (2.0 * NdotH * NdotV) / VdotH;//几何衰减
				double Gs = (2.0 * NdotH * NdotL) / VdotH;
				double G = min(min(1.0, Gm), Gs);
				double Rs = (F * D * G) / (NdotL * NdotV * PI);
				I += LightSource[loop].L_Specular * pMaterial->M_Specular * Rs;
			}
			//第3步，光强衰减
			double c0 = LightSource[loop].L_C0;//c0为常数衰减因子
			double c1 = LightSource[loop].L_C1;//c1为线性衰减因子
			double c2 = LightSource[loop].L_C2;//c2为二次衰减因子			
			double f = (1.0/(c0 + c1 * d + c2 * d * d));//光强衰减函数
			f = min(1.0, f);
			ResultI += I * f;
		}
		else
			ResultI += Point.c;//物体自身颜色
	}
	//第4步，加入环境光
	ResultI += Ambient * pMaterial->M_Ambient;
	//第5步，光强规范化到[0,1]区间
	ResultI.Normalize();
	//第6步，返回所计算顶点的最终的光强颜色
	return ResultI;
}
