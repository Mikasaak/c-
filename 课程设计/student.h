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

	vector<ComputerRoom>Vcom;//������Ż�����Ϣ������

	int Creat_ComputerRoom_Vector();

	Student();//�޲ι���

	Student(int id,string username,string password);//�вι���

	virtual void Menu();//��ʾѧ����ݵĲ����˵�

	bool ApplyOrder();//����ԤԼ//�ɹ�����true ʧ�ܷ���false

	void ShowMyOrder();//��ʾ�ҵ�ԤԼ

	void ShowAllOreder();//��ʾ�����˵�ԤԼ

	void CancalMyOrder();//ȡ���Լ���ԤԼ

};