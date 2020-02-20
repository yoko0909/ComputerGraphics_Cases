#pragma once
#include "Point3.h"
#include "Texture.h"
#include "Lighting.h"//Phong模型

class CZBuffer  
{
public:
	CZBuffer(void);
    virtual ~CZBuffer(void);
	void SetPoint(CP3 P0, CP3 P1, CP3 P2, CVector3 N0, CVector3 N1, CVector3 N2, CT2 T0, CT2 T1, CT2 T2);// 三角形初始化
	void InitialDepthBuffer(int nWidth, int nHeight, double zDepth);//初始化深度缓冲区
	void PhongShader(CDC* pDC, CP3 ViewPoint, CLighting* pLight, CMaterial* pMaterial, CTexture* pTexture);//光滑着色
private:
	void DDA(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature);//边标记	
	CVector3 LinearInterp(double t, double tStart, double tEnd, CVector3 vStart, CVector3 vEnd);//法向量线性插值
	CT2 LinearInterp(double t, double tStart, double tEnd, CT2 uvStart, CT2 uvEnd);//纹理地址线性插值
	void SortVertex(void);//顶点排序
	CRGB GetTexture(int u, int v, CTexture* pTexture);//读取纹理颜色	
private:
	CP3 P0, P1, P2;//三角形的浮点数顶点
	CPoint3 point0, point1, point2;//三角形的整数顶点坐标
	CPoint2* SpanLeft; //跨度的起点数组标志
	CPoint2* SpanRight;//跨度的终点数组标志
	int nIndex;//记录扫描线条数
	double** zBuffer;//深度缓冲区
	int nWidth, nHeight;//缓冲区宽度与高度	
};