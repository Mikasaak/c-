#pragma once
#include<iostream>
#include"identity.h"
#include"Screen.h"
using namespace std;

class Teacher :public Identity
{
public:
	int Teacher_ID;
	Teacher();//�޲ι���

	Teacher(int empid, string username, string password);//�вι���

	virtual void Menu();//��ʾ��ʦ��ݵĲ����˵�

	void ShowAllOreder();//��ʾ�����˵�ԤԼ

	void AuditOrder();//��������˵�ԤԼ

};
