#pragma once
#include "Facet.h"
#include "Projection.h"
#include "ZBuffer.h"
#include"Texture.h"

class CBicubicBezierPatch
{
public:
	CBicubicBezierPatch(void);
	virtual ~CBicubicBezierPatch(void);
	void ReadControlPoint(CP3* V, int ReNumber);//读入16个控制点
	void ReadTexture(CTexture* pTexture);//读入纹理
	void SetScene(CLighting* pLight, CMaterial* pMaterial);//设置场景
	void DrawCurvedPatch(CDC* pDC, CZBuffer*pZBuffer, int nPatch);
private:
	void Recursion(CDC* pDC, CZBuffer* pZBuffer, int ReNumber, CT2* pRect,int nPatch);
	void Tessellation(CT2* pRect, CP3* P, CVector3* N, CT2* T, int nPatch);//细分曲面
	void DrawFacet(CDC* pDC, CZBuffer* pZBuffer, CP3* P, CVector3* N, CT2* T);//绘制四边形
	void LeftMultiplyMatrix(double M[4][4], CP3 V[4][4]);//左乘顶点矩阵
	void RightMultiplyMatrix(CP3 V[4][4], double M[4][4]);//右乘顶点矩阵
	void TransposeMatrix(double M[4][4]);//转置矩阵
public:
	int ReNumber;//递归次数
	CP3 V3[16];//三维控制点
	CProjection projection;//投影对象
	CLighting* pLight;//光照
	CMaterial* pMaterial;//材质
	CTexture* pTexture;//纹理
	int TextureIndex;//索引
};

