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
};
class Point//定义Shape的派生类Point
{
public:
	Point();//定义构造函数
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
	double x2;
public:
	line(double=0,double =0,double=0,double=0);//声明构造函数
	virtual double length()const;//声明求周长的虚函数
	virtual double area() const;//声明求面积的虚函数
	~line();//定义析构函数
};
class parallelogram :public line//定义line类的派生类parallelogram
{
protected:
	double x3;
	double x4;
	double y3;
	double y4;
public:
	parallelogram (double = 0, double = 0, double = 0, double = 0, double = 0, double = 0,double=0,double =0) ;//声明构造函数
	virtual double length()const;//声明求周长的虚函数,返还周长的数值
	virtual double area()const;//声明求面积的虚函数，返还面积的数值
	bool judge();//声明判断是否构成平行四边形的函数，如果是则返还真值，如果不是则返还假
	~parallelogram();//定义析构函数
};
class Circle :public Point,public Shape//定义Point的派生类Circle
{
protected:
	double x5;
	double y5;
	double radius;
public:
	Circle(double=0,double=0,double=0);//声明构造函数
	void getradius(double);//声明获取半径的函数
	virtual double area()const;//声明求面积的虚函数，返还面积的数值
	virtual double length()const;//声明求周长的虚函数，返还周长的数值
};
class Angle :public Circle//定义Circle类的派生类Arc
{
private:
	double angle;
public:
	Angle(double=0,double=0, double=0,double=0);//定义构造函数
	virtual double area()const;//声明求面积的虚函数，返还面积的数值
	virtual double length()const;//声明求周长的虚函数，返还周长的数值
	~Angle();//定义析构函数
};