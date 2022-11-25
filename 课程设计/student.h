#pragma once
#include<iostream>
#include"identity.h"
#include"Screen.h"
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include"computerRoom.h"
#include"Order.h"
#include"globalFile.h"
#include"Order.h"
using namespace std;

class Student:public Identity
{
public:
	int Student_ID;

	OrderLog orderlog;

	vector<ComputerRoom>Vcom;//用来存放机房信息的容器

	int Creat_ComputerRoom_Vector();

	Student();//无参构造

	Student(int id,string username,string password);//有参构造

	virtual void Menu();//显示学生身份的操作菜单

	bool ApplyOrder();//申请预约//成功返回true 失败返回false

	void ShowMyOrder();//显示我的预约

	void ShowAllOreder();//显示所有人的预约

	void CancalMyOrder();//取消自己的预约

};