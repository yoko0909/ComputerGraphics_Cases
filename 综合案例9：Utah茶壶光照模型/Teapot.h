#pragma once
#include "Patch.h"
#include "Projection.h"
#include "BicubicBezierPatch.h"

class CTeapot
{
public:
	CTeapot(void);
	virtual~CTeapot(void);
	void ReadVertex(void);//读入控制多边形顶点
	void ReadPatch(void);//读入双三次曲面片
	void SetReNumber(int ReNumber);//设置递归次数
	void ReadTexture(CTexture *pTexture);//读入纹理
	void SetScene(CLighting* pLight, CMaterial* pMaterial);//设置场景
	void Draw(CDC* pDC, CZBuffer* pZBuffer);//绘制整壶
public:
	int ReNumber;
	CP3 Ver[306];//茶壶总控制点
	CPatch Pat[32];//茶壶总面片
	CP3 Ver3[16];//三维控制点
	CBicubicBezierPatch bezier;//bezier曲面片
	CLighting* pLight;//光照
	CMaterial* pMaterial;//材质
	CTexture* Texture;//纹理
};


