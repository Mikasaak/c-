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
	Time(const int behour , const int beminute , const int endhour , const int endminute);//Time的有参构造
	bool Is_meet(Time& T);//
	bool operator == (Time& T);

};

class OrderLog
{
public:
	vector<tuple<string,Date,Time>> V_DateAndTime;
	//记录所有预约信息的容器，
	map<int, unordered_map<string, string>>M_AllOrder;
	
	int Map_size=0;

	OrderLog();//OrderLog构造函数

	void UpdateOrder(const char type);//更新预约记录//当type为1的时候是用文本来重新更新M_AllOrder和V_DateAndTime
										//当type为1的时候是用M_AllOrder来重新更新文本
};