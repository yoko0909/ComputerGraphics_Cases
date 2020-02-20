#pragma once

class CViewPlane
{
public:
	CViewPlane(void);
	virtual ~CViewPlane(void);
	void SetResolution(int HorRes, int VerRes);
	void SetSampleNumber(int SampleNumber);
public:
	int HorRes;//水平分辨率
	int VerRes;//垂直分辨率
	int SampleNumber;//采样像素
};

