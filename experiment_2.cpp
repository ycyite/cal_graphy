#include"pch.h"
#include<iostream>
#include<cmath>
#include"experiment_2.h"
using namespace std;
Point::Point()
{
	x = 0;
	y = 0;
}
Point::~Point()
{
}
inline void Point::setX(double a)
{
	x = a;
}
inline void Point::setY(double b)
{
	y = b;
}
inline line::line(double a, double b, double c, double d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
}
double line::length() const
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double line::area() const
{
	return 0;
}
line::~line()
{
}
parallelogram::parallelogram(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
{
	x3 = a1;
	x4 = a2;
	x5 = a3;
	x6 = a4;
	y3 = b1;
	y4 = b2;
	y5 = b3;
	y6 = b4;
}
bool parallelogram::judge()
{
	if ((x3 - x4) == (x5 - x6) && (y3 - y4) == (y5 - y6))
		return true;
	else
		return false;
}
double parallelogram::length()const
{
	double a, b;
	a = sqrt(pow((x3 - x4), 2) + pow((y3 - y4), 2));
	b = sqrt(pow((x3 - x5), 2) + pow((y3 - y5), 2));
	return (a + b) * 2;
}
double parallelogram::area()const
{
	double a, h, s, A, B;
	a = sqrt(pow((x3 - x4), 2) + pow((y3 - y4), 2));
	A = fabs((x5 - x3) / (x4 - x3));
	B = -1;
	h = fabs(fabs(A * (x5 - x4) + y4 - y5) / sqrt(pow(A, 2) + pow(B, 2)));
	s = a * h;
	return s;
}
parallelogram::~parallelogram()
{
}
inline Circle::Circle(double x, double y, double R)
{
	x7 = x;
	y7 = y;
	radius = R;
}
inline void Circle::getradius(double R)
{
	radius = R;
}
inline double Circle::area() const
{
	return PI * radius * radius;
}
inline double Circle::length() const
{
	return 2 * PI * radius;
}
Arc::Arc(double a,double b,double c,double an):Circle(a,b,c),angle(an)
{	
}
double Arc::length()const
{
	return (2*radius+radius*angle);
}
double Arc::area()const
{
	double area;
	area = radius * radius * angle / 2;
	return (area);
}
Arc::~Arc()//定义析构函数
{
}