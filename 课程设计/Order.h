#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<tuple>
#include"globalFile.h"
#include<sstream>
using namespace std;

class Date
{
	friend ostream& operator << (ostream& cout, Date& D);
public:
	int Year;
	int Month;
	int Day;
	Date(const int year, const int month, const int day);
	bool operator == ( Date& D );
};

class Time
{
	friend ostream& operator<<(ostream& cout, Time& T);
public:
	int Begin_Hour;
	int Begin_Minute;
	int End_Hour;
	int End_Minute;
	Time(const int behour , const int beminute , const int endhour , const int endminute);//Time���вι���
	bool Is_meet(Time& T);//
	bool operator == (Time& T);

};

class OrderLog
{
public:
	vector<tuple<string,Date,Time>> V_DateAndTime;
	//��¼����ԤԼ��Ϣ��������
	map<int, unordered_map<string, string>>M_AllOrder;
	
	int Map_size=0;

	OrderLog();//OrderLog���캯��

	void UpdateOrder(const char type);//����ԤԼ��¼//��typeΪ1��ʱ�������ı������¸���M_AllOrder��V_DateAndTime
										//��typeΪ1��ʱ������M_AllOrder�����¸����ı�
};