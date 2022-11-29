#include"Screen.h"
#include<iostream>
using namespace std;

//主选择操作界面
void Main_Operat_Screen()
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "*************************机房预约系统*************************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "请选择您的身份\n" << endl;//构建一开始的主界面
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 1.学生         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 2.老师         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 3.管理员       \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 0.退出系统     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "请输入您的选择:\n";
}

//管理员选择操作界面
void Manager_Operat_Screen(const string username)
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "*************管理员-" << username << "-登录此系统*************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "请选择您要进行的操作\n" << endl;//构建一开始的主界面
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 1.添加账号         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 2.查看账号         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 3.查看机房         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 4.显示所有预约     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 5.清空预约         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t *.注销并返回上一级 \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 0.直接退出系统     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "请输入您的选择:\n";
}

//学生选择操作界面
void Student_Operat_Screen(const string username)
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "*************同学--" << username << "-登录此系统**************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "请选择您要进行的操作\n" << endl;//构建一开始的主界面
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 1.申请预约         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 2.查看我的预约     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 3.查看所有预约     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 4.取消预约         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t *.注销并返回上一级 \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 0.退出系统         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "请输入您的选择:\n";
}

//教师选择操作界面
void Teacher_Operat_Screen(const string username)
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "**************教师--" << username << "-登录此系统*************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "请选择您要进行的操作\n" << endl;//构建一开始的主界面
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 1.查看所有预约     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 2.审核预约         \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t *.注销并返回上一级 \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*\t\t 0.直接退出系统     \t*\n";
	cout << "\t*\t\t\t\t\t*\n";
	cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout << "请输入您的选择:\n";
}

//学生登录界面
void Student_Login_Screen()
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "*********************欢迎进入学生登录界面*********************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "若想返回上一级请按 *  || 直接退出系统请按 0 || 继续请按其他键 \n";

}

//教师登录界面
void Teacher_Login_Screen()
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "*********************欢迎进入教师登录界面*********************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "若想返回上一级请按 *  || 直接退出系统请按 0 || 继续请按其他键 \n";
}

//管理员登录界面
void Manager_Login_Screen()
{
	system("cls");
	cout << "--------------------------------------------------------------\n";
	cout << "********************欢迎进入管理员登录界面********************\n";
	cout << "--------------------------------------------------------------\n";
	cout << "若想返回上一级请按 *  || 直接退出系统请按 0 || 继续请按其他键 \n";
}

//登录成功的反馈提示
void Login_Success_Prompt(const char type)
{
	if (type == '1')
	{
		cout << endl;
		cout << "------------------------学生登录成功！------------------------\n";
		cout << endl;
		system("pause");
	}

	if (type == '2')
	{
		cout << endl;
		cout << "------------------------教师登录成功！------------------------\n";
		cout << endl;
		system("pause");
	}
	if (type == '3')
	{
		cout << endl;
		cout << "-----------------------管理员登录成功！-----------------------\n";
		cout << endl;
		system("pause");
	}
}

//登录失败的提示
void Login_Fail_Prompt()
{

	cout << endl;
	cout << "--------------------------登录失败！--------------------------\n";
	cout << endl;
	system("pause");
}

//注销成功的反馈提示
void Logout_Prompt()
{
	cout << endl;
	cout << "--------------------------注销成功！--------------------------\n";
	cout << endl;
	system("pause");
}

//预约清空成功的反馈提示
void Clear_Success()
{
	cout << endl;
	cout << "------------------------预约清空成功！------------------------\n";
	cout << endl;
	system("pause");
}

//直接退出系统的提示
void Direct_Exit_Prompt()
{
	cout << endl;
	cout << "--------------------------------------------------------------\n";
	cout << "******************系统退出成功，欢迎下次使用******************\n";
	cout << "--------------------------------------------------------------\n";
	cout << endl;
	system("TASKKILL /F /IM 课程设计.exe ");
}

//显示账号添加状态的提示 fir = 1代表学生;2代表教师   sec=1代表成功，2代表失败
void Is_Add_Account_Prompt(const char fir, const char sec)
{
	if (fir == '1')//fir = 1代表学生
	{
		if (sec == '1')
		{
			cout << endl;
			cout << "-----------------------学生账号添加成功-----------------------\n";
			cout << endl;
			system("pause");
		}
		if (sec == '2')
		{
			cout << endl;
			cout << "----------------------学生账号添加失败！----------------------\n";
			cout << "------------------输入的学号与已有账号的重复------------------\n";
			cout << "--------------------请重新输入学生账号信息--------------------\n";
			cout << endl;
			system("pause");
		}

	}
	if (fir == '2')//fir = 1代表教师
	{
		if (sec == '1')
		{
			cout << endl;
			cout << "-----------------------教师账号添加成功-----------------------\n";
			cout << endl;
			system("pause");
		}
		if (sec == '2')
		{
			cout << endl;
			cout << "----------------------教师账号添加失败！----------------------\n";
			cout << "-----------------输入的职工号与已有账号的重复-----------------\n";
			cout << "--------------------请重新输入教师账号信息--------------------\n";
			cout << endl;
			system("pause");
		}
	}
}

//显示是否有账号信息的提示//1代表学生||2代表老师
void Is_Have_Account_Prompt(const char type)
{
	if (type == '1')
	{
		cout << "------------------------无学生账号信息------------------------\n";
		system("pause");
	}
	if (type == '2')
	{
		cout << "------------------------无教师账号信息------------------------\n";
		system("pause");
	}
}

//显示所在操作层userType表示用户类型 operatType表示指令序号
void Operat_Lev_Showing(const char userType,const int operatType)
{
	if (userType == 'M')//在mananger的指令
	{
		if (operatType == 1)
			cout << "**********************进行添加账号的操作**********************\n";

		if (operatType == 2)
			cout << "**********************进行查看账号的操作**********************\n";

		if (operatType == 3)
			cout << "********************进行查看机房信息的操作********************\n";

		if (operatType == 4)
			cout << "********************进行显示所有预约的操作********************\n";

		if (operatType == 5)
			cout << "**********************进行清空预约的操作**********************\n";
	}

	if (userType == 'S')//在student的指令
	{
		if (operatType == 1)
			cout << "**********************进行申请预约的操作**********************\n";

		if (operatType == 2)
			cout << "********************进行显示我的预约的操作********************\n";

		if (operatType == 3)
			cout << "******************进行显示所有人的预约的操作******************\n";

		if (operatType == 4)
			cout << "*******************进行取消自己的预约的操作*******************\n";
	}

	if (userType == 'T')//在teacher的指令
	{
		if (operatType == 1)
			cout << "******************进行显示所有人的预约的操作******************\n";

		if (operatType == 2)
			cout << "******************进行审核申请人的预约的操作******************\n";

		if (operatType == 3)
			cout << "********************进行查看学生账号的操作********************\n";
	}
}

//进行申请预约的操作提示和机房情况说明界面
void ApplyOrder_Tips()
{
	cout << "--------------------------------------------------------------\n";
	cout << "-------机房基本全年开放，如有特殊情况将会在界面进行提示-------\n";
	cout << "---------------机房每天的开放时间为8:00至21:00----------------\n";
	//cout << "特殊提示：";
	cout << "--------------------------------------------------------------\n";
	cout << "|请根据提示依次输入 使用日期 使用时间段 机房编号来进行填写   |\n";
	cout << "|(也可中间用空格隔开一次性输入)                              |\n";
	cout << "|使用日期请按照：   年 月 日   进行填写  例如2022 1 6        |\n";
	cout << "|使用时间段请按照： 时间 时间  进行填写  例如16 30 18 30     |\n";
	cout << "--------------------------------------------------------------\n";
}

//申请预约成功的提示
void Apply_Success_Prompt()
{
	cout << endl;
	cout << "------------------------预约添加成功！------------------------\n";
	cout << endl;
	system("pause");
}//

//申请预约失败的提示
void Apply_Fail_Prompt()
{
	cout << endl;
	cout << "------------------------预约添加失败！------------------------\n";
	cout << "----您的预约与其他预约相冲突，请重新挑选机房或时间进行预约----\n";
	cout << endl;
	system("pause");
}//

//取消预约成功的提示
void Cancel_Success_Prompt() 
{
	cout << endl;
	cout << "------------------------取消预约成功！------------------------\n";
	cout << endl;
	system("pause");
}

//取消操作成功的提示
void Cancel_Operat_Prompt()
{
	cout << endl;
	cout << "------------------------取消操作成功！------------------------\n";
	cout << endl;
	system("pause");
}