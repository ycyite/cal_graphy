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
};
class Point//����Shape��������Point
{
public:
	Point();//���幹�캯��
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
	double x2;
public:
	line(double=0,double =0,double=0,double=0);//�������캯��
	virtual double length()const;//�������ܳ����麯��
	virtual double area() const;//������������麯��
	~line();//������������
};
class parallelogram :public line//����line���������parallelogram
{
protected:
	double x3;
	double x4;
	double y3;
	double y4;
public:
	parallelogram (double = 0, double = 0, double = 0, double = 0, double = 0, double = 0,double=0,double =0) ;//�������캯��
	virtual double length()const;//�������ܳ����麯��,�����ܳ�����ֵ
	virtual double area()const;//������������麯���������������ֵ
	bool judge();//�����ж��Ƿ񹹳�ƽ���ı��εĺ�����������򷵻���ֵ����������򷵻���
	~parallelogram();//������������
};
class Circle :public Point,public Shape//����Point��������Circle
{
protected:
	double x5;
	double y5;
	double radius;
public:
	Circle(double=0,double=0,double=0);//�������캯��
	void getradius(double);//������ȡ�뾶�ĺ���
	virtual double area()const;//������������麯���������������ֵ
	virtual double length()const;//�������ܳ����麯���������ܳ�����ֵ
};
class Angle :public Circle//����Circle���������Arc
{
private:
	double angle;
public:
	Angle(double=0,double=0, double=0,double=0);//���幹�캯��
	virtual double area()const;//������������麯���������������ֵ
	virtual double length()const;//�������ܳ����麯���������ܳ�����ֵ
	~Angle();//������������
};