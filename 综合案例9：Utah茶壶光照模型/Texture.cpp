#include "StdAfx.h"
#include "Texture.h"

CTexture::CTexture(void)
{
	image = NULL;
}

CTexture::~CTexture(void)
{

}

void CTexture::GetImage(UINT nIDResource)//准备位图
{
	CBitmap NewBitmap;
	NewBitmap.LoadBitmap(nIDResource);
	NewBitmap.GetBitmap(&bmp);//将CBitmap的信息保存到Bitmap结构体中
	int nbytesize = bmp.bmWidthBytes * bmp.bmHeight;
	image = new BYTE[nbytesize];
	NewBitmap.GetBitmapBits(nbytesize, (LPVOID)image);
}

void CTexture::DeleteObject(void)//释放位图
{
	if(NULL != image)
		delete []image;
}