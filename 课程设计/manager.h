#pragma once
#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include<vector>
#include<algorithm>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:

	vector<Student>Vstu;//用来存放学生账号信息的容器

	vector<Teacher>Vtea;//用来存放教师账号信息的容器

	vector<ComputerRoom>Vcom;//用来存放机房信息的容器
	
	pair<int, int> Creat_ST_Vector();//将student和teacher的账号信息读入vector容器，返回值为pair第一个元素为student的
	//账号个数，第二个元素为teacher账号的个数
	int Creat_ComputerRoom_Vector();//初始化存放机房信息的容器

	Manager();//无参构造

	Manager(string username, string password);//有参构造

	virtual void Menu();//显示管理员身份的操作菜单

	void Add_Account();//添加账号

	void Show_Accouen();//显示账号

	void Show_ComputerRoom_info();//显示机房信息

	void Show_All_Oreder();//显示所有人的预约

	void Clean_Order();//清空预约记录

	bool Is_Repeat(const int id, const char type);//检测传入的ID号码是否与已有的学生或老师的ID号码重复，
												//返回bool类型，如果重复返回true，否则返回false；

	

};
