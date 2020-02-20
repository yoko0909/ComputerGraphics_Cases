#pragma once
class CRGB
{
public:
	CRGB(void);
	CRGB(double red, double green, double blue, double alpha = 0.0);
	virtual ~CRGB(void);	
	friend CRGB operator + (const CRGB &clr0, const CRGB &clr1);//运算符重载
	friend CRGB operator - (const CRGB &clr0, const CRGB &clr1);
	friend CRGB operator * (const CRGB &clr0, const CRGB &clr1);
	friend CRGB operator * (const CRGB &clr, double scalar);
	friend CRGB operator * (double scalar, const CRGB &clr);
	friend CRGB operator / (const CRGB &clr, double scalar);
	friend CRGB operator += (CRGB &clr0, CRGB &clr1);
	friend CRGB operator -= (CRGB &clr0, CRGB &clr1);
	friend CRGB operator *= (CRGB &clr0, CRGB &clr1);
	friend CRGB operator /= (CRGB &clr, double scalar);
	void   Normalize();	//归一化到[0,1]区间
public:
	double red;//红色分量
	double green;//绿色分量
	double blue;//蓝色分量
	double alpha;//alpha分量	
};

