#include<iostream>
using namespace std;
#include<string>
class Shape
{
	public:
		virtual double area()const=0;
		virtual double length()const=0;
};
class Point
{
	protected:
		double x;
		double y;	
	public:
		Point()
		{
			x=0.0;
			y=0.0;
		}
		void getX(double);
		void getY(double);
		~Point();		
};
class line:public Point,public Shape
{
	protected:
		Point p1;
		Point p2;
	public:
		line(Point,Point);
		virtual double length()const;
		~line();				
};
class parallelogram:public line
{
	protected:
		Point p3;
		Point p4;
		Point p5;
		Point p6;
	public:
		parallelogram(Point,Point,Point,Point);
		virtual double length()const;
		virtual double area()const;
		bool judge();
		~parallelogram();
};
class Circle:public Point,public Shape
{
	protected:
		Point p7;
		double radius;
	public:
		Circle(Point,double);
		void getradius(double);
		virtual double area()const;
		~Circle();
};
class Arc :public Circle
{
	private:
		double angle;
	public:
		Arc(Point,double,double);
		virtual double area()const;
		virtual double length()const;
		~Arc();
};


