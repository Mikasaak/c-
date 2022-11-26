#pragma once
#include<iostream>
#include"identity.h"
#include"Order.h"
#include"Screen.h"
#include<sstream>
using namespace std;

class Teacher :public Identity
{
public:
	int Teacher_ID;

	OrderLog orderlog;

	Teacher();//无参构造

	Teacher(int empid, string username, string password);//有参构造

	virtual void Menu();//显示教师身份的操作菜单

	void ShowAllOreder();//显示所有人的预约

	void AuditOrder();//审核申请人的预约

};
