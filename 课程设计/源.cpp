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
		char select = 0;//接受用户的输入选择
		cin >> select;//按照第一个读到的字符判断
		cin.ignore(10000,'\n');//清空之后的一行缓存区
		switch (select)
		{
		case '1'://用户身份为学生
		{
			while (true)
			{
				Student_Login_Screen();
				char flag;//用于控制是否返回上一级界面
				cin >> flag;
				cin.ignore(10000, '\n');//清理一行输入缓存区
				if (flag == '*')
					break;
				if (flag == '0')
					Direct_Exit_Prompt();
				Identity* user = Login_AND_Creat(STUDENT_FILE, '1');
				if (user != NULL)
					Student_Mainmenu_Operat(user); //进行Student的主菜单的操作//各种操作选择及操作的进行在函数内进行
			}
			break;
		}
		case '2'://用户身份为老师
		{
			while (true)
			{
				system("cls");
				Teacher_Login_Screen();
				char flag;//用于控制是否返回上一级界面
				cin >> flag;
				cin.ignore(10000, '\n');//清理一行输入缓存区
				if (flag == '*')
					break;
				if (flag == '0')
					Direct_Exit_Prompt();
				Identity* user = Login_AND_Creat(TEACHER_FILE, '2');
				if (user != NULL)
					Teacher_Mainmenu_Operat(user); //进行Teacher的主菜单的操作//各种操作选择及操作的进行在函数内进行
			}
			break;
		}

		case '3'://用户身份为管理员
		{
			while (true)
			{
				system("cls");
				Manager_Login_Screen();
				char flag;//用于控制是否返回上一级界面
				cin >> flag;
				cin.ignore(10000, '\n');//清理一行输入缓存区
				if (flag == '*')
					break;
				if (flag == '0')
					Direct_Exit_Prompt();
				Identity* user = Login_AND_Creat(MANAGER_FILE, '3');

				if (user != NULL)
					Manage_Mainmenu_Operat(user); //进行mananger的主菜单的操作//各种操作选择及操作的进行在函数内进行
			}
			break;

		}

		case '0'://退出系统
		{
			cout << "已退出本系统\n";
			system("pause");
			return 0;
			break;
		}
		default://输入的选择不正确

			cout << "请您输入正确的选择\n";
			system("pause");
			system("cls");
			break;
		}		
	}
	system("pause");
}
