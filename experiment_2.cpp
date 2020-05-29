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
triangle::triangle(double a, double b, double c, double d, double e, double f) :line(a, b, c, d)
{
	x2 = e;
	y2 = f;
}
double triangle::length()const
{
	double a, b, c;
	a = sqrt(pow((x - x1), 2) + pow((y - y1), 2));
	b = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	c = sqrt(pow((x - x2), 2) + pow((y - y2), 2));
	return (a + b + c);
}
double triangle::area()const
{
	return(fabs(x * y1 - x * y2 + x1 * y2 - x1 * y + x2 * y - x1 * y1)/2);
}
bool triangle::judge1()
{
	double a, b, c;
	a = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
	b = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
	c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if ((a + b > c) && (a + c > b) && (b + c > a))
	{
		return true;
	}
	else
		return false;
}
triangle::~triangle()
{
}
triangular_pyramid::triangular_pyramid(double a, double b, double c, double d, double e, double f, double i, double g, double q) :triangle(a, b, c, d, e, f)
{
	x3 = g;
	y3 = q;
	h = i;
}
double triangular_pyramid::area()const
{
	double a1, b1, c1, a2, b2, c2, a3, b3, c3, s1, s2, s3, S1, S2, S3;
	a1 = sqrt((pow((x2 - x3), 2) + pow((y2 - y3), 2)) + pow(h, 2));
	b1 = sqrt((pow((x - x3), 2) + pow((y - y3), 2)) + pow(h, 2));
	c1 = sqrt((pow((x - x2), 2) + pow((y - y2), 2)));
	a2 = sqrt((pow((x1 - x3), 2) + pow((y1 - y3), 2)) + pow(h, 2));
	b2 = sqrt((pow((x - x3), 2) + pow((y - y3), 2)) + pow(h, 2));
	c2 = sqrt((pow((x - x1), 2) + pow((y - y1), 2)));
	a3 = sqrt((pow((x2 - x3), 2) + pow((y2 - y3), 2)) + pow(h, 2));
	b3 = sqrt((pow((x1 - x3), 2) + pow((y1 - y3), 2)) + pow(h, 2));
	c3 = sqrt((pow((x1 - x2), 2) + pow((y1 - y2), 2)));
	s1 = (a1 + b1 + c1) / 2;
	s2 = (a2 + b2 + c2) / 2;
	s3 = (a3 + b3 + c3) / 2;
	S1 = sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));
	S2 = sqrt(s2 * (s2 - a2) * (s2 - b2) * (s2 - c2));
	S3 = sqrt(s3 * (s3 - a3) * (s3 - b3) * (s3 - c3));
	return (S1 + S2 + S3 + triangle::area());
}
double triangular_pyramid::volume()const
{
	return (triangle::area() * h / 3);
}
triangular_pyramid::~triangular_pyramid()
{
}
triangular_prism::triangular_prism(double _x, double _y, double _x1, double _y1, double _x2, double _y2, double _h) :triangle(_x, _y, _x1, _y1, _x2, _y2)
{
	h2 = _h;
}
double triangular_prism::area() const
{
	return triangle::length() * h2 + 2 * triangle::area();
}
double triangular_prism::volume() const
{
	// return  (x1 * y2 + x2 * y + x * y1 - x1 * y - x2 * y1 - x * y2) * h2;
	return triangle::area() * h2;
}
triangular_prism::~triangular_prism()
{
}
Three_prism::Three_prism(double a, double b, double c, double d, double e, double f, double g, double s, double i, double j, double k, double l, double m) :triangular_pyramid(a, b, c, d, e, f, g, s, i)
{
	x4 = j;
	y4 = k;
	x5 = l;
	y5 = m;
}
double Three_prism::area()const
{
	double s1, s2, h1, h2, h3, a1, a2, a3, b1, b2, b3, p1, p2;
	a1 = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	a2 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	a3 = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	b1 = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
	b2 = sqrt((x5 - x4) * (x5 - x4) + (y5 - y4) * (y5 - y4));
	b3 = sqrt((x5 - x3) * (x5 - x3) + (y5 - y3) * (y5 - y3));
	h1 = sqrt(((x + x1) / 2 - (x3 + x4) / 2) * ((x + x1) / 2 - (x3 + x4) / 2) + ((y + y1) / 2 - (y3 + y4) / 2) * ((y + y1) / 2 - (y3 + y4) / 2) + h * h);
	h2 = sqrt(((x + x2) / 2 - (x3 + x5) / 2) * ((x + x2) / 2 - (x3 + x5) / 2) + ((y + y2) / 2 - (y3 + y5) / 2) * ((y + y2) / 2 - (y3 + y5) / 2) + h * h);
	h3 = sqrt(((x1 + x2) / 2 - (x4 + x5) / 2) * ((x1 + x2) / 2 - (x4 + x5) / 2) + ((y1 + y2) / 2 - (y4 + y5) / 2) * ((y1 + y2) / 2 - (y4 + y5) / 2) + h * h);
	p1 = a1 + a2 + a3, p2 = b1 + b2 + b3;
	s1 = sqrt(p1 * (p1 - a1) * (p1 - a2) * (p1 - a3));
	s2 = sqrt(p2 * (p2 - b1) * (p2 - b2) * (p2 - b3));

	double area;
	area = s1 + s2 + ((a1 + b1) * h1 + (a2 + b2) * h2 + (a3 + b3) * h3) / 2;
	return area;
}
double Three_prism::volume()const
{
	double s1, s2, h1, h2, h3, a1, a2, a3, b1, b2, b3, p1, p2;
	a1 = sqrt(((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
	a2 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	a3 = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	b1 = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
	b2 = sqrt((x5 - x4) * (x5 - x4) + (y5 - y4) * (y5 - y4));
	b3 = sqrt((x5 - x3) * (x5 - x3) + (y5 - y3) * (y5 - y3));
	h1 = sqrt(fabs(((x + x1) / 2 - (x3 + x4) / 2) * ((x + x1) / 2 - (x3 + x4) / 2) + ((y + y1) / 2 - (y3 + y4) / 2) * ((y + y1) / 2 - (y3 + y4) / 2) + h * h));
	h2 = sqrt(fabs(((x + x2) / 2 - (x3 + x5) / 2) * ((x + x2) / 2 - (x3 + x5) / 2) + ((y + y2) / 2 - (y3 + y5) / 2) * ((y + y2) / 2 - (y3 + y5) / 2) + h * h));
	h3 = sqrt(fabs(((x1 + x2) / 2 - (x4 + x5) / 2) * ((x1 + x2) / 2 - (x4 + x5) / 2) + ((y1 + y2) / 2 - (y4 + y5) / 2) * ((y1 + y2) / 2 - (y4 + y5) / 2) + h * h));
	p1 = a1 + a2 + a3, p2 = b1 + b2 + b3;
	s1 = sqrt(fabs(p1 * (p1 - a1) * (p1 - a2) * (p1 - a3)));
	s2 = sqrt(fabs(p2 * (p2 - b1) * (p2 - b2) * (p2 - b3)));
	double volume;
	volume = (s1 + s2 + sqrt(s1 * s2)) * h / 3;
	return volume;
}
bool Three_prism::judge2()
{
	double a = sqrt(pow((x1 - x), 2) + pow((y1 - y), 2));
	double b = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	double c = sqrt(pow((x2 - x), 2) + pow((y2 - y), 2));
	double a_1 = sqrt(pow((x3 - x4), 2) + pow((y3 - y4), 2));
	double b_1 = sqrt(pow((x5 - x4), 2) + pow((y5 - y4), 2));
	double c_1 = sqrt(pow((x3 - x5), 2) + pow((y3 - y5), 2));
	
		if (((x1 - x) * (y3 - y4) == (y1 - y) * (x3 - x4)) && ((x2 - x) * (y5 - y3) == (y2 - y) * (x5 - x3)) && (((a_1 / a) == (b_1 / b)) && ((a_1 / a) == (c_1 / c))))
			return true;
		else
			return false;
	
}
Three_prism::~Three_prism()
{
}
parallelogram::parallelogram(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4) :line(a1, b1, a2, b2)
{
	x6 = a3;
	y6 = b3;
	x7 = a4;
	y7 = b4;
}
bool parallelogram::judge()
{
	if ((x - x1)*(y6 - y7)==(x6-x7)*(y-y1))
		return true;
	else
		return false;
}
double parallelogram::length()const
{
	double a, b;
	a = sqrt(pow((x - x1), 2) + pow((y - y1), 2));
	b = sqrt(pow((x1 - x7), 2) + pow((y1 - y7), 2));
	return (a + b) * 2;
}
double parallelogram::area()const
{
	double p, a, b, c, s;
	a = sqrt(pow((x - x1), 2) + pow((y - y1), 2));
	b = sqrt(pow((x - x6), 2) + pow((y - y6), 2));
	c = sqrt(pow((x1 - x6), 2) + pow((y1 - y6), 2));
	p = (a + b + c) / 2;
	s = 2 * sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}
parallelogram::~parallelogram()
{
}
rectangular_pyramid::rectangular_pyramid(double a, double b, double c, double d, double e, double f, double g, double h, double k, double i, double j) :parallelogram(a, b, c, d, e, f, g, h)
{
	x8 = g;
	y8 = j;
	h3 = k;
}
double rectangular_pyramid::area()const
{
	double a, b, s, s1, s2, s3, s4, a1, a2, a3, a4, H1, H2, H3, H4;
	if (x6 != x)
	{
		a = fabs(x6 - x);
		b = fabs(y7 - y6);
		s = a * b;
		a1 = fabs(y8 - y);
		a2 = fabs(x6 - x8);
		a3 = fabs(b - a1);
		a4 = fabs(a - a2);
	}
	else
	{
		a = fabs(x - x1);
		b = fabs(y6 - y);
		s = a * b;
		a1 = fabs(y8 - y);
		a2 = fabs(x - x8);
		a3 = fabs(b - a1);
		a4 = fabs(a - a2);
	}
	H1 = sqrt(pow(a1, 2) + pow(h3, 2));
	H2 = sqrt(pow(a2, 2) + pow(h3, 2));
	H3 = sqrt(pow(a3, 2) + pow(h3, 2));
	H4 = sqrt(pow(a4, 2) + pow(h3, 2));
	s1 = a * H1 / 2;
	s2 = b * H2 / 2;
	s3 = a * H3 / 2;
	s4 = b * H4 / 2;
	return (s + s1 + s2 + s3 + s4);
}
double rectangular_pyramid::volume()const
{
	double v, s, a, b;
	if (x6 != x)
	{
		a = fabs(x6 - x);
		b = fabs(y7 - y6);
	}
	else
	{
		a = fabs(x - x1);
		b = fabs(y6 - y);
	}
	s = a * b;
	v = s * h3 / 3;
	return v;
}
rectangular_pyramid::~rectangular_pyramid()
{}
quadrangular::quadrangular(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3, double _x4, double _y4, double _h4) : parallelogram(x, y, x1, y1, x6, y6, x7, y7)
{
	h4 = _h4;
}
double quadrangular::area() const
{
	double hemA = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	double hemB = sqrt((x6 - x1) * (x6 - x1) + (y6 - y1) * (y6 - y1));
	double hemC = sqrt((x7 - x6) * (x7 - x6) + (y7 - y6) * (y7 - y6));
	double hemD = sqrt((x - x7) * (x - x7) + (y - y7) * (y - y7));
	double hemE = sqrt((x7 - x1) * (x7 - x1) + (y7 - y1) * (y7 - y1));
	double p1 = (hemA + hemD + hemE) / 2.0;
	double p2 = (hemB + hemC + hemE) / 2.0;
	double s1 = sqrt(p1 * (p1 - hemA) * (p1 - hemD) * (p1 - hemE));
	double s2 = sqrt(p2 * (p1 - hemB) * (p2 - hemC) * (p2 - hemE));
	return (2 * (s1 + s2) + (hemA + hemB + hemC + hemD) * h4);
}
double quadrangular::volume() const
{
	double hemA = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	double hemB = sqrt((x6 - x1) * (x6 - x1) + (y6 - y1) * (y6 - y1));
	double hemC = sqrt((x7 - x6) * (x7 - x6) + (y7 - 6) * (y7 - y6));
	double hemD = sqrt((x - x7) * (x - x7) + (y - y7) * (y - y7));
	double hemE = sqrt((x7 - x1) * (x7 - x1) + (y7 - y1) * (y7 - y1));
	double p1 = (hemA + hemD + hemE) / 2.0;
	double p2 = (hemB + hemC + hemE) / 2.0;
	double s1 = sqrt(p1 * (p1 - hemA) * (p1 - hemD) * (p1 - hemE));
	double s2 = sqrt(p2 * (p1 - hemB) * (p2 - hemC) * (p2 - hemE));
	return (s1 + s2) * h4;
}
quadrangular::~quadrangular()
{
}
quadrangular_frustum_pyramid::quadrangular_frustum_pyramid(double a, double b, double c, double d, double e, double f, double g, double i, double j, double k, double l, double m, double n, double o, double p, double q, double h)
{
	x = a; y = b;
	x1 = c; y1 = d;
	x6 = e; y6 = f;
	x7 = g; y7 = i;
	x8 = j; y8 = k;
	x9 = l; y9 = m;
	x10 = n; y10 = o;
	x11 = p; y11 = q;
	h3 = h;

}
double quadrangular_frustum_pyramid::area()const
{
	double a = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	double b = sqrt((x6 - x1) * (x6 - x1) + (y6 - y1) * (y6 - y1));
	double c = sqrt((x8 - x9) * (x8 - x9) + (y8 - y9) * (y8 - y9));
	double d = sqrt((x10 - x9) * (x10 - x9) + (y10 - y9) * (y10 - y9));
	double a1 = sqrt((a * a) + (b * b));
	double c1 = sqrt((c * c) + (d * d));
	double s1 = a * b;
	double s2 = c * d;
	double h_1 = sqrt(fabs(c - a) * fabs(c - a) + h3 * h3);
	double h_2 = sqrt(fabs(d - b) * fabs(d - b) + h3 * h3);
	double s_1 = (c + a) * h_1 / 2;
	double s_2 = (b + d) * h_2 / 2;
	return (s1 + s2 + 2 * s_1 + 2 * s_2);
}
double quadrangular_frustum_pyramid::volume()const
{
	double a = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	double b = sqrt((x6 - x1) * (x6 - x1) + (y6 - y1) * (y6 - y1));
	double c = sqrt((x8 - x9) * (x8 - x9) + (y8 - y9) * (y8 - y9));
	double d = sqrt((x10 - x9) * (x10 - x9) + (y10 - y9) * (y10 - y9));
	double a1 = sqrt((a * a) + (b * b));
	double c1 = sqrt((c * c) + (d * d));
	double s1 = a * b;
	double s2 = c * d;
	double l_1 = (a + c) / 2;
	double l_2 = (b + d) / 2;
	double s = l_1 * l_2;
	return ((s1 + s2 + 4 * s) * h3 / 6);
}
bool quadrangular_frustum_pyramid::judge3()
{
	double a = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
	double b = sqrt((x6 - x1) * (x6 - x1) + (y6 - y1) * (y6 - y1));
	double a_1 = sqrt((x7 - x6) * (x7 - x6) + (y7 - y6) * (y7 - y6));
	double b_1 = sqrt((x - x7) * (x - x7) + (y - y7) * (y - y7));
	double c = sqrt((x8 - x9) * (x8 - x9) + (y8 - y9) * (y8 - y9));
	double d = sqrt((x10 - x9) * (x10 - x9) + (y10 - y9) * (y10 - y9));
	double c_1 = sqrt((x10 - x11) * (x10 - x11) + (y10 - y11) * (y10 - y11));
	double d_1 = sqrt((x8 - x11) * (x8 - x11) + (y8 - y11) * (y8 - y11));
	if (((x1 - x) * (y9 - y8) == (y1 - y) * (x9 - x8)) && ((x10 - x9) * (y6 - y1) == (y10 - y9) * (x6 - x1)) && ((a_1 / c_1) == (b_1 / d_1)))
		return true;
	else 
		return false;

}
inline Circle::Circle(double a, double b, double R) :Point(x, y)
{
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
Circle::~Circle()
{
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
	area = radius * radius * (angle / 180) * PI;
	return (area);
}
Angle::~Angle()//定义析构函数
{
}
ball::ball(double a, double b, double c) :Circle(a, b, c)
{
}
double ball::area()const
{
	return (4 * PI * pow(radius, 2));
}
double ball::volume()const
{
	return (PI * pow(radius, 3) * 4 / 3);
}
cone::cone(double a, double b, double c, double d) : Circle(a, b, c)
{
	h5 = d;
}
double cone::area()const
{
	double l;
	l = sqrt(pow(h5, 2) + pow(radius, 2));
	return (PI * radius * l + PI * pow(radius, 2));
}
double cone::volume()const
{
	return((1 / 3) * h5 * PI * pow(radius, 2));
}
cone::~cone()
{}
cylinder::cylinder(double a, double b, double c, double d) : cone(a, b, c, d)
{}
double cylinder::area()const
{
	double l = sqrt(pow(h5, 2) + pow(radius, 2));
	return (2 * PI * radius * h5 + 2 * PI * pow(radius, 2));
}
double cylinder::volume()const
{
	return 2 * PI * pow(radius, 2) * h5;
}
cylinder::~cylinder()
{
}
circular_truncated_cone::circular_truncated_cone(double a, double b, double c, double d, double e, double f, double h) :cone(a, b, c, d)
{
	x12 = e;
	y12 = f;
	radius1 = h;
}
double circular_truncated_cone::area()const
{
	double l = sqrt(fabs(radius - radius1) * fabs(radius - radius1) + h5 * h5);
	return (PI * radius * radius + PI * radius1 * radius1 + PI * radius * l + PI * radius1 * l);
}
double circular_truncated_cone::volume()const
{
	double v;
	v = PI * h5 * (radius1 * radius1 + radius * radius + radius1 * radius) / 3;
	return v;
}
circular_truncated_cone::~circular_truncated_cone()
{
}
double line::volume()const
{
	return 0;
}
double Circle::volume()const
{
	return 0;
}

