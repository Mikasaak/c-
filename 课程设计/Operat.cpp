#include"Operat.h"

//mananger的主菜单的操作实现
void Manage_Mainmenu_Operat(Identity*& manager)//管理员菜单中的操作逻辑
{

	while (true)//不选择退出该层操作则一直在此层进行选择操作
	{
		manager->Menu();//利用多态用父类指针调用显示菜单的函数
		
		Manager* user = (Manager*)manager;//把父类指针转换为Manger指针

		char select;//用于接收选择的变量
		cin >> select;//用户输入选择
		cin.ignore(10000, '\n');//清理输入缓存区
		if (select == '1')//进行添加账号的操作
		{
			Operat_Lev_Showing('M',1);//显示操作层（添加账号）
			user->Add_Account();
		}

		if (select == '2')//进行查看账号的操作
		{
			Operat_Lev_Showing('M', 2);//显示操作层（查看账号）
			user->Show_Accouen();
		}

		if (select == '3') //进行查看机房的操作
		{
			Operat_Lev_Showing('M', 3);//显示操作层（查看机房）
			user->Show_ComputerRoom_info();

		}
		if (select == '4')//进行显示所有预约的操作
		{
			Operat_Lev_Showing('M', 4);//显示操作层（清空预约）
			user->Show_All_Oreder();
		}

		if (select == '5')//进行清空预约的操作
		{
			Operat_Lev_Showing('M', 4);//显示操作层（清空预约）
			user->Clean_Order();

		}

		if (select == '*')//进行返回注销并上一级的操作
		{
			delete manager;
			Logout_Prompt();
			system("cls");
			return;
		}

		if (select == '0')//进行返回直接退出系统操作
			Direct_Exit_Prompt();
	}
}

//student的主菜单的操作实现
void Student_Mainmenu_Operat(Identity*& student)
{
	while (true)//不选择退出该层操作则一直在此层进行选择操作
	{
		student->Menu();//利用多态用父类指针调用显示菜单的函数

		Student* user = (Student*)student;//把父类指针转换为Student指针

		char select;//用于接收选择的变量
		cin >> select;//用户输入选择
		cin.ignore(10000, '\n');//清理输入缓存区

		if (select == '1')//进行申请预约的操作
		{
			Operat_Lev_Showing('S',1);//显示操作层（申请预约）
			user->ApplyOrder();
			//system("pause");
		}

		if (select == '2')//进行显示用户自己预约的操作
		{
			Operat_Lev_Showing('S', 2);//显示操作层（显示我的预约）
			user->ShowMyOrder(); 
			system("pause");
		}

		if (select == '3') //进行显示所有人的预约的操作
		{
			Operat_Lev_Showing('S', 3);//显示操作层（显示所有人的预约）
			user->ShowAllOreder();
			system("pause");
		}

		if (select == '4')//进行取消自己的预约的操作
		{
			Operat_Lev_Showing('S', 4);//显示操作层（取消自己的预约）
			user->CancalMyOrder();
			system("pause");
		}

		if (select == '*')//进行返回注销并上一级的操作
		{
			delete student;
			Logout_Prompt();
			system("cls");
			return;
		}

		if (select == '0')//进行返回直接退出系统操作
			Direct_Exit_Prompt();
	}
}

//teacher的主菜单的操作实现
void Teacher_Mainmenu_Operat(Identity*& teacher)
{
	while (true)//不选择退出该层操作则一直在此层进行选择操作
	{
		teacher->Menu();//利用多态用父类指针调用显示菜单的函数

		Teacher* user = (Teacher*)teacher;//把父类指针转换为Manger指针

		char select;//用于接收选择的变量
		cin >> select;//用户输入选择
		cin.ignore(10000, '\n');//清理输入缓存区

		if (select == '1')//进行显示所有人的预约的操作
		{
			Operat_Lev_Showing('T',1);//显示操作层（显示所有人的预约）
			user->ShowAllOreder();

		}

		if (select == '2')//进行审核申请人的预约的操作
		{
			Operat_Lev_Showing('T', 2);//显示操作层（审核申请人的预约）
			user->AuditOrder();

		}

		if (select == '*')//进行返回注销并上一级的操作
		{
			delete teacher;
			Logout_Prompt();
			system("cls");
			return;
		}

		if (select == '0')//进行返回直接退出系统操作
			Direct_Exit_Prompt();
	}
}

//用于不同的身份进行登录并创建相应对象//返回值为Identity指针
Identity* Login_AND_Creat(string file_name, char select)
{
	Identity* person = NULL;//父类指针用于指向子类对象

	ifstream read;
	read.open(file_name, ios::in);
	if (!read.is_open())
	{
		cout << "file_not_open\n";
		read.close();
		return person;
	}
	int ID = 0;
	string username;//三个参数接收用户输入的信息
	string password;
	if (select != '3')
	{
		cout << "请输入您的学号或职工号\nID:";
		cin >> ID;
	}
	cout << "请输入您的用户名\nUsername:";
	cin >> username;
	cout << "请输入您的密码\nPassword:";
	cin >> password;
	if (select == '1')//对学生身份的人进行身份验证
	{
		int check_ID;//文件中读出的用于验证登录的ID,username,password
		string check_username;
		string check_password;
		while (read >> check_ID && read >> check_username && read >> check_password)//按行读入
		{
			if (check_ID == ID && check_username == username && check_password == password)//进行比较
			{
				Login_Success_Prompt(select);//登陆成功的提示
				person = new Student(ID, username, password);//用基类指针接收指向创建的学生对象
				return person;
			}

		}


	}
	else if (select == '2')//对教师身份的人进行身份验证
	{
		int check_ID;//文件中读出的用于验证登录的ID,username,password
		string check_username;
		string check_password;
		while (read >> check_ID && read >> check_username && read >> check_password)//按行读入
		{
			if (check_ID == ID && check_username == username && check_password == password)//进行比较
			{
				Login_Success_Prompt(select);//登陆成功的提示
				person = new Teacher(ID, username, password);//用基类指针接收指向创建的教师对象
				return person;
			}
		}
	}
	else if (select == '3')//对管理员身份的人进行身份验证
	{
		//文件中读出的用于验证登录的username,password
		string check_username;
		string check_password;
		while (read >> check_username && read >> check_password)//按行读入
		{
			if (check_username == username && check_password == password)//进行比较
			{
				Login_Success_Prompt(select);//登陆成功的提示
				person = new Manager(username, password);//用基类指针接收指向创建的管理员对象
				return person;
			}

		}
	}


	Login_Fail_Prompt();//登录失败的提示
	return person;



}