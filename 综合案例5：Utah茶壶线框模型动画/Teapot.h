#pragma once
#include "Patch.h"
#include "BicubicBezierPatch.h"

class CTeapot
{
public:
	CTeapot(void);
	virtual~CTeapot(void);
	void ReadVertex(void);//读入控制多边形顶点
	void ReadPatch(void);//读入双三次曲面片
	void SetRecursiveNumber(int Renumber);//设置递归深度
	void Draw(CDC* pDC);//绘制整壶
public:
	int ReNumber;//递归深度
	CP3 Ver[306];//茶壶总控制点
private:
	CPatch Pat[32];//茶壶总面片
	CP3 Ver3[16];//三维控制点
	CBicubicBezierPatch bezier;//bezier曲面片
};


