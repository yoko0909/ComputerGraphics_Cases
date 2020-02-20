#pragma once
#include"P3.h"

class CTransform3
{
public:
	CTransform3(void);
	virtual ~CTransform3(void);
	void Identity(void);//单位矩阵初始化
	void SetMatrix(CP3* P, int ptNumber);//三维顶点数组初始化
	void Translate(double tx, double ty, double tz);//平移变换
	void Scale(double sx,double sy, double sz);//缩放变换
	void Scale(double sx,double sy, double sz,CP3 p);//相对于任意点的缩放变换
	void Scale(double s);//整体缩放变换
	void Scale(double s, CP3 p);//相对于任意点的整体缩放变换
	void RotateX(double beta);//绕X轴旋转变换
	void RotateY(double beta);//绕Y轴旋转变换
	void RotateZ(double beta);//绕Z轴旋转变换	
	void RotateX(double beta, CP3 p);//相对于任意点的绕X轴旋转变换
	void RotateY(double beta, CP3 p);//相对于任意点的绕Y轴旋转变换
	void RotateZ(double beta, CP3 p);//相对于任意点的绕Z轴旋转变换
	void ReflectX(void);//关于X轴反射变换
	void ReflectY(void);//关于Y轴反射变换
	void ReflectZ(void);//关于Z轴反射变换
	void ReflectXOY(void);//关于XOY面反射变换
	void ReflectYOZ(void);//关于YOZ面反射变换
	void ReflectZOX(void);//关于ZOX面反射变换
	void ShearX(double b, double c);//沿X方向错切变换
	void ShearY(double d, double f);//沿Y方向错切变换
	void ShearZ(double g, double h);//沿Z方向错切变换
	void MultiplyMatrix(void);//矩阵相乘
public:
	double	M[4][4];//三维变换矩阵	
	CP3* P;//三维顶点数组名
	int	ptNumber;//三维顶点个数
};



