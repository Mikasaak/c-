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
#include"Operat.h"
#include"Order.h"
using namespace std;
int main()
{
	while (true)
	{
		Main_Operat_Screen();
		char select = 0;//�����û�������ѡ��
		cin >> select;//���յ�һ���������ַ��ж�
		cin.ignore(10000,'\n');//���֮���һ�л�����
		switch (select)
		{
		case '1'://�û����Ϊѧ��
		{
			while (true)
			{
				Student_Login_Screen();
				char flag;//���ڿ����Ƿ񷵻���һ������
				cin >> flag;
				cin.ignore(10000, '\n');//����һ�����뻺����
				if (flag == '*')
					break;
				if (flag == '0')
					Direct_Exit_Prompt();
				Identity* user = Login_AND_Creat(STUDENT_FILE, '1');
				if (user != NULL)
					Student_Mainmenu_Operat(user); //����Student�����˵��Ĳ���//���ֲ���ѡ�񼰲����Ľ����ں����ڽ���
			}
			break;
		}
		case '2'://�û����Ϊ��ʦ
		{
			while (true)
			{
				system("cls");
				Teacher_Login_Screen();
				char flag;//���ڿ����Ƿ񷵻���һ������
				cin >> flag;
				cin.ignore(10000, '\n');//����һ�����뻺����
				if (flag == '*')
					break;
				if (flag == '0')
					Direct_Exit_Prompt();
				Identity* user = Login_AND_Creat(TEACHER_FILE, '2');
				if (user != NULL)
					Teacher_Mainmenu_Operat(user); //����Teacher�����˵��Ĳ���//���ֲ���ѡ�񼰲����Ľ����ں����ڽ���
			}
			break;
		}

		case '3'://�û����Ϊ����Ա
		{
			while (true)
			{
				system("cls");
				Manager_Login_Screen();
				char flag;//���ڿ����Ƿ񷵻���һ������
				cin >> flag;
				cin.ignore(10000, '\n');//����һ�����뻺����
				if (flag == '*')
					break;
				if (flag == '0')
					Direct_Exit_Prompt();
				Identity* user = Login_AND_Creat(MANAGER_FILE, '3');

				if (user != NULL)
					Manage_Mainmenu_Operat(user); //����mananger�����˵��Ĳ���//���ֲ���ѡ�񼰲����Ľ����ں����ڽ���
			}
			break;

		}

		case '0'://�˳�ϵͳ
		{
			cout << "���˳���ϵͳ\n";
			system("pause");
			return 0;
			break;
		}
		default://�����ѡ����ȷ

			cout << "����������ȷ��ѡ��\n";
			system("pause");
			system("cls");
			break;
		}		
	}
	system("pause");
}
