#pragma once
#include"T2.h"
#include "Projection.h"

class CBicubicBezierPatch
{
public:
	CBicubicBezierPatch(void);
	virtual ~CBicubicBezierPatch(void);
	void ReadControlPoint(CP3* V, int ReNumber);//读入16个控制点和递归深度
	void DrawCurvedPatch(CDC* pDC);//绘制曲面
	void DrawControlGrid(CDC* pDC);//绘制控制网格
private:
	void Recursion(CDC* pDC, int ReNumber, CT2* pRect);//递归函数
	void Tessellation(CT2* pRect, CP2* P);
	void DrawFacet(CDC* pDC, CP2* P);//绘制四边形
	void LeftMultiplyMatrix(double M[4][4], CP3 V[4][4]);//左乘顶点矩阵
	void RightMultiplyMatrix(CP3 V[4][4], double M[4][4]);//右乘顶点矩阵
	void TransposeMatrix(double M[4][4]);//转置矩阵
public:
	int ReNumber;//递归次数
	CP3 V3[16];//三维控制点
	CProjection projection;//投影对象
};

