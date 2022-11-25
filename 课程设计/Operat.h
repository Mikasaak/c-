#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include"globalFile.h"
#include"identity.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
#include"Screen.h"

void Manage_Mainmenu_Operat(Identity*& manager);//mananger的主菜单的操作实现

void Student_Mainmenu_Operat(Identity*& student);//student的主菜单的操作实现

void Teacher_Mainmenu_Operat(Identity*& teacher);//teacher的主菜单的操作实现


Identity* Login_AND_Creat(string file_name, char select);//用于不同的身份进行登录并创建相应对象//返回值为Identity指针