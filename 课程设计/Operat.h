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

void Manage_Mainmenu_Operat(Identity*& manager);//mananger�����˵��Ĳ���ʵ��

void Student_Mainmenu_Operat(Identity*& student);//student�����˵��Ĳ���ʵ��

void Teacher_Mainmenu_Operat(Identity*& teacher);//teacher�����˵��Ĳ���ʵ��


Identity* Login_AND_Creat(string file_name, char select);//���ڲ�ͬ����ݽ��е�¼��������Ӧ����//����ֵΪIdentityָ��