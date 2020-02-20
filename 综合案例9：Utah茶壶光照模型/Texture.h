#pragma once
#include"resource.h"

class CTexture
{
public:
	CTexture(void);
	virtual~CTexture(void);
	void GetImage(UINT nIDResource);//准备位图
	void DeleteObject(void);//释放位图
public:
	BYTE* image;
	BITMAP bmp;//BITMAP结构体变量
};

