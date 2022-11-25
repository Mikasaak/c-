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

	vector<Student>Vstu;//�������ѧ���˺���Ϣ������

	vector<Teacher>Vtea;//������Ž�ʦ�˺���Ϣ������

	vector<ComputerRoom>Vcom;//������Ż�����Ϣ������
	
	pair<int, int> Creat_ST_Vector();//��student��teacher���˺���Ϣ����vector����������ֵΪpair��һ��Ԫ��Ϊstudent��
	//�˺Ÿ������ڶ���Ԫ��Ϊteacher�˺ŵĸ���
	int Creat_ComputerRoom_Vector();//��ʼ����Ż�����Ϣ������

	Manager();//�޲ι���

	Manager(string username, string password);//�вι���

	virtual void Menu();//��ʾ����Ա��ݵĲ����˵�

	void Add_Account();//����˺�

	void Show_Accouen();//��ʾ�˺�

	void Show_ComputerRoom_info();//��ʾ������Ϣ

	void Show_All_Oreder();//��ʾ�����˵�ԤԼ

	void Clean_Order();//���ԤԼ��¼

	bool Is_Repeat(const int id, const char type);//��⴫���ID�����Ƿ������е�ѧ������ʦ��ID�����ظ���
												//����bool���ͣ�����ظ�����true�����򷵻�false��

	

};
