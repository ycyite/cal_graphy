#pragma once
#include<iostream>
using namespace std;
#include<string>
#define PI 3.1415926
class Shape//�������
{
public:
	virtual double area()const = 0;//������������麯��
	virtual double length()const = 0;//�������ܳ����麯��
	virtual double volume()const = 0;//����������ĺ���
};
class Point//����Shape��������Point
{
public:
	Point(double = 0, double = 0);//���幹�캯��
	double getX()const
	{
		return x;
	}//��ȡX����ĺ���
	double getY()const
	{
		return y;
	}//��ȡY����ĺ���
	void setX(double);
	void setY(double);
	~Point();//������������
	double x;
	double y;
};
class line :public Point,public Shape//����Point��������line
{
protected:
	double x1;
	double y1;
public:
	line(double = 0, double = 0, double = 0, double = 0);//�������캯��
	virtual double length()const;//�������ܳ����麯��
	virtual double area() const;//������������麯��
	virtual double volume()const;
	~line();//������������
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
class triangular_pyramid :public triangle//����׶
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
class triangular_prism :public triangle//������
{
public:
	triangular_prism(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area() const;
	virtual double volume()const;
	~triangular_prism();
protected:
	double h2;
};
class Three_prism :public triangular_pyramid//����̨
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
class parallelogram :public line//����line���������parallelogram
{
protected:
	double x6;
	double x7;
	double y6;
	double y7;
public:
	parallelogram(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);//�������캯��
	virtual double length()const;//�������ܳ����麯��,�����ܳ�����ֵ
	virtual double area()const;//������������麯���������������ֵ
	bool judge(double, double, double, double, double, double, double, double);//�����ж��Ƿ񹹳�ƽ���ı��εĺ�����������򷵻���ֵ����������򷵻���
	bool judge4();
	~parallelogram();//������������
};
class rectangular_pyramid :public parallelogram//����׶
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
class quadrangular :public parallelogram//������
{
public:
	quadrangular(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual  double volume()const;
	~quadrangular();
protected:
	double h4;
};
class quadrangular_frustum_pyramid :public rectangular_pyramid//����̨
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
class Circle :public Point, public Shape//����Point��������Circle
{
protected:
	double radius;
public:
	Circle(double = 0, double = 0, double = 0);//�������캯��
	void getradius(double);//������ȡ�뾶�ĺ���
	virtual double area()const;//������������麯���������������ֵ
	virtual double length()const;//�������ܳ����麯���������ܳ�����ֵ
	virtual double volume()const;
	~Circle();
};
class Angle :public Circle//����Circle���������Arc
{
private:
	double angle;
public:
	Angle(double = 0, double = 0, double = 0, double = 0);//���幹�캯��
	virtual double area()const;//������������麯���������������ֵ
	virtual double length()const;//�������ܳ����麯���������ܳ�����
	~Angle();//������������
};
class ball :public Circle//��
{
public:
	ball(double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
};
class cone :public Circle//Բ׶
{
public:
	cone(double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	~cone();
protected:
	double h5;
};
class  cylinder :public cone//Բ��
{
public:
	cylinder(double = 0, double = 0, double = 0, double = 0);
	virtual double area()const;
	virtual double volume()const;
	~cylinder();
};
class circular_truncated_cone :public cone//Բ̨
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