#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity//��ݻ���
{
public:
	string UserName;//�û���
	string Password;//����
	virtual void Menu() = 0;//���麯��Menu����������д����ʵ�ָ�����ݵĲ����˵�
	
};