#include "StdAfx.h"
#include "BicubicBezierPatch.h"
#include <math.h>
#define ROUND(d) int(d + 0.5)

CBicubicBezierPatch::CBicubicBezierPatch(void)
{
	ReNumber = 0;
}

CBicubicBezierPatch::~CBicubicBezierPatch(void)
{
}

void CBicubicBezierPatch::ReadControlPoint(CP3* V, int ReNumber)
{
	for (int i = 0; i < 16; i++)
		V3[i] = V[i];
	this->ReNumber = ReNumber;
}

void CBicubicBezierPatch::DrawCurvedPatch(CDC* pDC)
{
	CT2 Rect[4];
	Rect[0] = CT2(0, 0); Rect[1] = CT2(1, 0);//初始化uv
	Rect[2] = CT2(1, 1); Rect[3] = CT2(0, 1);
	Recursion(pDC, ReNumber, Rect);//递归函数
}

void CBicubicBezierPatch::Recursion(CDC* pDC, int ReNumber, CT2* pRect)
{
	if (ReNumber == 0)
	{
		CP3 P[4];
		Tessellation(pRect, P);
		DrawFacet(pDC, P);//绘制小平面
		return;
	}
	else
	{
		double HalfU = (pRect[0].u + pRect[1].u) / 2.0;
		double HalfV = (pRect[0].v + pRect[3].v) / 2.0;
		CT2 SubRect[4][4];//一分为四个
		//左下子长方形
		SubRect[0][0] = pRect[0];
		SubRect[0][1].u = HalfU;     SubRect[0][1].v = pRect[0].v;
		SubRect[0][2].u = HalfU;     SubRect[0][2].v = HalfV;
		SubRect[0][3].u = pRect[0].u; SubRect[0][3].v = HalfV;
		//右下子长方形
		SubRect[1][0] = SubRect[0][1];
		SubRect[1][1] = pRect[1];
		SubRect[1][2].u = pRect[1].u; SubRect[1][2].v = HalfV;
		SubRect[1][3] = SubRect[0][2];
		//右上子长方形
		SubRect[2][0] = SubRect[1][3];
		SubRect[2][1] = SubRect[1][2];
		SubRect[2][2] = pRect[2];
		SubRect[2][3].u = HalfU; SubRect[2][3].v = pRect[2].v;
		//左上子长方形
		SubRect[3][0] = SubRect[0][3];
		SubRect[3][1] = SubRect[2][0];
		SubRect[3][2] = SubRect[2][3];
		SubRect[3][3] = pRect[3];
		Recursion(pDC, ReNumber - 1, SubRect[0]);
		Recursion(pDC, ReNumber - 1, SubRect[1]);
		Recursion(pDC, ReNumber - 1, SubRect[2]);
		Recursion(pDC, ReNumber - 1, SubRect[3]);
	}
}

void CBicubicBezierPatch::Tessellation(CT2* pRect, CP2* P)
{
	double M[4][4];//系数矩阵Mbe
	M[0][0] = -1; M[0][1] = 3; M[0][2] = -3; M[0][3] = 1;
	M[1][0] = 3;  M[1][1] = -6; M[1][2] = 3;  M[1][3] = 0;
	M[2][0] = -3; M[2][1] = 3; M[2][2] = 0;  M[2][3] = 0;
	M[3][0] = 1;  M[3][1] = 0; M[3][2] = 0;  M[3][3] = 0;
	CP3 VT[4][4];//曲线计算用控制点数组
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			VT[i][j] = V3[i * 4 + j];
	LeftMultiplyMatrix(M, VT);//系数矩阵左乘三维点矩阵
	TransposeMatrix(M);//计算转置矩阵
	RightMultiplyMatrix(VT, M);//系数矩阵右乘三维点矩阵
	double u0, u1, u2, u3, v0, v1, v2, v3;//u，v参数的幂
	for (int i = 0; i < 4; i++)
	{
		u3 = pow(pRect[i].u, 3.0), u2 = pow(pRect[i].u, 2.0), u1 = pow(pRect[i].u, 1.0), u0 = 1;
		v3 = pow(pRect[i].v, 3.0), v2 = pow(pRect[i].v, 2.0), v1 = pow(pRect[i].v, 1.0), v0 = 1;
		CP3 P3 = (u3 * VT[0][0] + u2 * VT[1][0] + u1 * VT[2][0] + u0 * VT[3][0]) * v3
			+ (u3 * VT[0][1] + u2 * VT[1][1] + u1 * VT[2][1] + u0 * VT[3][1]) * v2
			+ (u3 * VT[0][2] + u2 * VT[1][2] + u1 * VT[2][2] + u0 * VT[3][2]) * v1
			+ (u3 * VT[0][3] + u2 * VT[1][3] + u1 * VT[2][3] + u0 * VT[3][3]) * v0;
		P[i] = projection.PerspectiveProjection(P3);
	}
}

void CBicubicBezierPatch::DrawFacet(CDC* pDC, CP2* P)
{
	pDC->MoveTo(ROUND(P[0].x), ROUND(P[0].y));
	pDC->LineTo(ROUND(P[1].x), ROUND(P[1].y));
	pDC->LineTo(ROUND(P[2].x), ROUND(P[2].y));
	pDC->LineTo(ROUND(P[3].x), ROUND(P[3].y));
	pDC->LineTo(ROUND(P[0].x), ROUND(P[0].y));
}

void CBicubicBezierPatch::LeftMultiplyMatrix(double M[4][4], CP3 V[4][4])//左乘矩阵M*V
{
	CP3 VT[4][4];//临时矩阵
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			VT[i][j] = M[i][0] * V[0][j] + M[i][1] * V[1][j] + M[i][2] * V[2][j] + M[i][3] * V[3][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			V[i][j] = VT[i][j];
}

void CBicubicBezierPatch::RightMultiplyMatrix(CP3 V[4][4], double M[4][4])//右乘矩阵V*M
{
	CP3 VT[4][4];//临时矩阵
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			VT[i][j] = V[i][0] * M[0][j] + V[i][1] * M[1][j] + V[i][2] * M[2][j] + V[i][3] * M[3][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			V[i][j] = VT[i][j];
}

void CBicubicBezierPatch::TransposeMatrix(double M[4][4])//转置矩阵
{
	double VT[4][4];//临时矩阵
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			VT[j][i] = M[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			M[i][j] = VT[i][j];
}

void CBicubicBezierPatch::DrawControlGrid(CDC* pDC)//绘制控制网格
{
	CP2 P2[4][4];//二维控制点
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			P2[i][j] = projection.PerspectiveProjection(V3[i * 4 + j]);//透视投影
	CPen NewPen, *pOldPen;
	NewPen.CreatePen(PS_SOLID, 3, RGB(0, 128, 0));
	pOldPen = pDC->SelectObject(&NewPen);
	for (int i = 0; i < 4; i++)
	{
		pDC->MoveTo(ROUND(P2[i][0].x), ROUND(P2[i][0].y));
		for (int j = 1; j < 4; j++)
			pDC->LineTo(ROUND(P2[i][j].x), ROUND(P2[i][j].y));
	}
	for (int j = 0; j < 4; j++)
	{
		pDC->MoveTo(ROUND(P2[0][j].x), ROUND(P2[0][j].y));
		for (int i = 1; i < 4; i++)
			pDC->LineTo(ROUND(P2[i][j].x), ROUND(P2[i][j].y));
	}
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}