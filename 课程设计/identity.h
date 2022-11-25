#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity//身份基类
{
public:
	string UserName;//用户名
	string Password;//密码
	virtual void Menu() = 0;//纯虚函数Menu让派生类重写用于实现各个身份的操作菜单
	
};