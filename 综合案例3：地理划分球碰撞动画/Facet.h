#pragma once

class CFacet
{
public:
	CFacet(void);
	virtual ~CFacet(void);
	void SetPtNumber(int Number);
public:
	int Number;//面的顶点数
	int Index[4];//面的顶点索引号
};

