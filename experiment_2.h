#pragma once
#include"pch.h"
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
	Point(double = 0, double = 0);//���幹�캯��
	double getX()const
	{
		return x;
	}//��ȡX����ĺ���
	double getY()const
	{
		return y;
	}//��ȡY����ĺ���
	~Point();//������������
	double x;
	double y;
};
class line :public Point//����Point��������line
{
protected:
	double x1;
	double x2;
	double y1;
	double y2;
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
	double x5;
	double x6;
	double y5;
	double y6;
public:
	parallelogram (double = 0, double = 0, double = 0, double = 0, double = 0, double = 0,double=0,double =0) ;//�������캯��
	virtual double length()const;//�������ܳ����麯��,�����ܳ�����ֵ
	virtual double area()const;//������������麯���������������ֵ
	bool judge();//�����ж��Ƿ񹹳�ƽ���ı��εĺ�����������򷵻���ֵ����������򷵻���
	~parallelogram();//������������
};
class Circle :public Point//����Point��������Circle
{
protected:
	double y7;
	double x7;
	double radius;
public:
	Circle(double=0,double=0,double=0);//�������캯��
	void getradius(double);//������ȡ�뾶�ĺ���
	virtual double area()const;//������������麯���������������ֵ
	virtual double length()const;//�������ܳ����麯���������ܳ�����ֵ
};
class Arc :public Circle//����Circle���������Arc
{
private:
	double angle;
public:
	Arc(double=0,double=0, double=0,double=0);//���幹�캯��
	virtual double area()const;//������������麯���������������ֵ
	virtual double length()const;//�������ܳ����麯���������ܳ�����ֵ
	~Arc();//������������
};