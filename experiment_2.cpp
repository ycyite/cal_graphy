#include"pch.h"
#include<iostream>
#include<cmath>
#include"experiment_2.h"
using namespace std;
Point::Point(double a, double b)
{
	x = a;
	y = b;
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
line::line(double q, double w, double e, double r) :Point(q, w)
{
	x1 = e;
	y1 = r;
}
double line::length() const
{
	return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
}
double line::area() const
{
	return 0;
}
line::~line()
{
}
parallelogram::parallelogram(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4) :line(a1, b1, a2, b2)
{
	x2 = a3;
	y2 = b3;
	x3 = a4;
	y3 = b4;
}
bool parallelogram::judge()
{
	if ((x - x1) == (x2 - x3) && (y - y1) == (y2 - y3))
		return true;
	else
		return false;
}
double parallelogram::length()const
{
	double a, b;
	a = sqrt(pow((x - x1), 2) + pow((y - y1), 2));
	b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	return (a + b) * 2;
}
double parallelogram::area()const
{
	double p, a, b, c, s;
	a = sqrt(pow((x - x1), 2) + pow((y - y1), 2));
	b = sqrt(pow((x - x2), 2) + pow((y - y2), 2));
	c = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	p = (a + b + c) / 2;
	s = 2 * sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}
parallelogram::~parallelogram()
{
}
inline Circle::Circle(double x, double y, double R) :Point(x, y)
{
	x4 = x;
	y4 = y;
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
Angle::Angle(double a, double b, double c, double an) :Circle(a, b, c)
{
	angle = an;
}
double Angle::length()const
{
	return (2 * radius + radius * (angle / 180) * PI);
}
double Angle::area()const
{
	double area;
	area = radius * radius * (angle / 360) * PI;
	return (area);
}
Angle::~Angle()//定义析构函数
{
}