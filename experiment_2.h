#pragma once
#include<iostream>
using namespace std;
#include<string>
#define PI 3.1415926
class Shape//定义基类
{
public:
	virtual double area()const = 0;//声明求面积的虚函数
	virtual double length()const = 0;//声明求周长的虚函数
	virtual double volume()const = 0;//声明求体积的函数
};
class Point//定义Shape的派生类Point
{
public:
	Point(double = 0, double = 0);//定义构造函数
	double getX()const
	{
		return x;
	}//获取X坐标的函数
	double getY()const
	{
		return y;
	}//获取Y坐标的函数
	void setX(double);
	void setY(double);
	~Point();//定义析构函数
	double x;
	double y;
};
class line :public Point,public Shape//定义Point的派生类line
{
protected:
	double x1;
	double y1;
public:
	line(double = 0, double = 0, double = 0, double = 0);//声明构造函数
	virtual double length()const;//声明求周长的虚函数
	virtual double area() const;//声明求面积的虚函数
	virtual double volume()const;
	~line();//定义析构函数
};
class triangle :public line
{
protected:
	double x2;
	double y2;
public:
	triangle(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double length()const;
	virtual double area() const;
	virtual double volume()const=0;
	~triangle();
	bool judge1();
};
class triangular_pyramid :public triangle//三棱锥
{
public:
	triangular_pyramid(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;

	~triangular_pyramid();
protected:
	double x3;
	double y3;
	double h;
};
class triangular_prism :public triangle//三棱柱
{
public:
	triangular_prism(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area() const;
	virtual double volume()const;
	~triangular_prism();
protected:
	double h2;
};
class Three_prism :public triangular_pyramid//三棱台
{
public:
	Three_prism(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	bool judge2();
	~Three_prism();
protected:
	double x4;
	double y4;
	double x5;
	double y5;
};
class parallelogram :public line//定义line类的派生类parallelogram
{
protected:
	double x6;
	double x7;
	double y6;
	double y7;
public:
	parallelogram(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);//声明构造函数
	virtual double length()const;//声明求周长的虚函数,返还周长的数值
	virtual double area()const;//声明求面积的虚函数，返还面积的数值
	bool judge(double, double, double, double, double, double, double, double);//声明判断是否构成平行四边形的函数，如果是则返还真值，如果不是则返还假
	bool judge4();
	~parallelogram();//定义析构函数
};
class rectangular_pyramid :public parallelogram//四棱锥
{
public:
	rectangular_pyramid(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	~rectangular_pyramid();
protected:
	double x8;
	double y8;
	double h3;
};
class quadrangular :public parallelogram//四棱柱
{
public:
	quadrangular(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual  double volume()const;
	~quadrangular();
protected:
	double h4;
};
class quadrangular_frustum_pyramid :public rectangular_pyramid//四棱台
{
public:
	quadrangular_frustum_pyramid(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	bool judge3();
protected:
	double x9;
	double y9;
	double x10;
	double y10;
	double x11;
	double y11;
};
class Circle :public Point, public Shape//定义Point的派生类Circle
{
protected:
	double radius;
public:
	Circle(double = 0, double = 0, double = 0);//声明构造函数
	void getradius(double);//声明获取半径的函数
	virtual double area()const;//声明求面积的虚函数，返还面积的数值
	virtual double length()const;//声明求周长的虚函数，返还周长的数值
	virtual double volume()const;
	~Circle();
};
class Angle :public Circle//定义Circle类的派生类Arc
{
private:
	double angle;
public:
	Angle(double = 0, double = 0, double = 0, double = 0);//定义构造函数
	virtual double area()const;//声明求面积的虚函数，返还面积的数值
	virtual double length()const;//声明求周长的虚函数，返还周长的数
	~Angle();//定义析构函数
};
class ball :public Circle//球
{
public:
	ball(double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
};
class cone :public Circle//圆锥
{
public:
	cone(double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	~cone();
protected:
	double h5;
};
class  cylinder :public cone//圆柱
{
public:
	cylinder(double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	~cylinder();
};
class circular_truncated_cone :public cone//圆台
{
public:
	circular_truncated_cone(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	~circular_truncated_cone();
private:
	double radius1;
	double x12;
	double y12;
};