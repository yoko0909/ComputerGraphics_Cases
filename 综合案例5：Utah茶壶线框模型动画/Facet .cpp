#include "StdAfx.h"
#include "Facet.h"


CFacet::CFacet(void)
{
}

CFacet::~CFacet(void)
{

}

void CFacet::SetVertexNumber(int vNumber)
{
	this->vNumber = vNumber;
}

void CFacet::SetFacetNormal(CP3 Vertex0, CP3 Vertex1, CP3 Vertex2)//表面法矢量函数
{
	CVector3 Vector01(Vertex0, Vertex1);//Vertex0与Vertex1顶点构成边矢量
	CVector3 Vector02(Vertex0, Vertex2);//Vertex0与Vertex2顶点构成边矢量
	fNormal = CrossProduct(Vector01, Vector02);
}

void CFacet::SetFacetNormal(CVertex Vertex0, CVertex Vertex1, CVertex Vertex2)//表面法矢量函数
{
	CVector3 Vector01(Vertex0.P, Vertex1.P);//Vertex0与Vertex1顶点构成边矢量
	CVector3 Vector02(Vertex0.P, Vertex2.P);//Vertex0与Vertex2顶点构成边矢量
	fNormal = CrossProduct(Vector01, Vector02);
}