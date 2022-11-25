#include"manager.h"
#include"Screen.h"
using namespace std;


//将student和teacher的账号信息读入vector容器，返回值为pair第一个元素为student的
//账号个数，第二个元素为teacher账号的个数
pair<int, int> Manager::Creat_ST_Vector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//对学生账号文件进行读取
	if (!ifs.is_open())//检查文件是否打开
	{
		cout << "STUDENT_FILE文件打开失败" << endl;
		ifs.close();
	}
	Vstu.clear();
	Vtea.clear();
	int studentSize = 0;
	int teacherSize = 0;
	Student S;
	while (ifs >> S.Student_ID && ifs >> S.UserName && ifs >> S.Password)//从文件中
	{
		Vstu.push_back(S);
	}
	studentSize = Vstu.size();
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);//对教师账号文件进行读取
	if (!ifs.is_open())//检查文件是否打开
	{
		cout << "TEACHER_FILE文件打开失败" << endl;
		ifs.close();
	}
	Teacher T;
	while (ifs >> T.Teacher_ID && ifs >> T.UserName && ifs >> T.Password)
	{
		Vtea.push_back(T);
	}
	teacherSize = Vtea.size();

	ifs.close();
	pair<int, int>ret(studentSize, teacherSize);
	return ret;
}

//将机房信息读入vector容器中
int Manager::Creat_ComputerRoom_Vector()
{
	ifstream ifs;
	int ComRSize = 0;
	ifs.open(COMPUTER_FILE, ios::in);//对机房信息文件进行读取
	if (!ifs.is_open())//检查文件是否打开
	{
		cout << "COMPUTER_FILE文件打开失败" << endl;
		ifs.close();
	}
	Vcom.clear();
	ComputerRoom C;
	while (ifs >> C.ComR_ID && ifs >> C.ComR_Maxsize)//从文件中对机房信息进行读取，并为ComputerRoom对象赋值
	{
		Vcom.push_back(C);//将对象存入容器中
		//cout << "ID:" << C.ComR_ID << " // " << "Maxsize:" << C.ComR_Maxsize << endl;
	}
	ifs.close();
	ComRSize = Vcom.size();
	return ComRSize;
}

//无参构造
Manager::Manager()
{

}

//有参构造初始化管理员参数，并且用vector容器储存student和teacher的账号信息
Manager::Manager(string username, string password)
{
	this->UserName = username;
	this->Password = password;
	this->Creat_ST_Vector();//初始化存放学生和老师账号信息的容器
	this->Creat_ComputerRoom_Vector();//初始化存放机房信息的容器

}

//显示管理员身份的操作菜单
void Manager::Menu()
{
	Manager_Operat_Screen(UserName);
}

//检测传入的ID号码是否与已有的学生或老师的ID号码重复，返回bool类型，如果重复返回true，否则返回false；
bool Manager::Is_Repeat(const int id, const char type)
{
	if (type == '1')//代表传入的是学生
	{
		for (Student tmp : Vstu)//遍历容器Vstu查找容器中有无与id重复的值，若有则返回true
		{
			if (tmp.Student_ID == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (Teacher tmp : Vtea)
		{
			if (tmp.Teacher_ID == id)//遍历容器Vtea查找容器中有无与id重复的值，若有则返回true
			{
				return true;
			}
		}
	}

	return false;//否则返回false
}

//添加学生或教师账号
void Manager::Add_Account()
{
	cout << "请选择要进行的操作" << endl;
	cout << "1.添加学生账号" << endl;
	cout << "2.添加教师账号" << endl;
	cout << "*.返回上一级" <<   endl;
	string file_name;
	char select;
	while (true)
	{
		cin >> select;
		cin.ignore(10000, '\n');
		if (select == '1')
		{
			file_name = STUDENT_FILE;
			cout << "请输入您要填加学生的学号、用户名、密码：\nID:";
			break;
		}
		if (select == '2')
		{
			file_name = TEACHER_FILE;
			cout << "请输入您要填加教师的职工号、用户名、密码：\nID:";
			break;
		}
		if (select == '*')
		{
			break;
		}
		cout << "请输入正确的选项" << endl;
		continue;
	}
	if (select == '*')
		return;

	while (true)
	{

		int ID;
		string username;
		string password;

		fstream add;
		

		cin >> ID;
		cout << "UserName:";
		cin >> username;
		cout << "Password:";
		cin >> password;
		if (Is_Repeat(ID, select))//检测是否与之前的重复//如果重复重新输入
		{
			Is_Add_Account_Prompt(select, '2');//显示添加账号的状态
			break;
		}

		add.open(file_name, ios::app);//以追加的方式打开文件
		if (!add.is_open())//检查文件是否打开
		{
			cout << "文件打开失败" << endl;
			add.close();
		}
		add << ID << ' ' << username << ' ' << password << ' ' << endl;//向文件中写入信息
		Is_Add_Account_Prompt(select, '1');//显示添加账号的状态
		
		if (select == '1')//更新学生和老师账号容器内的信息；防止一次性添加重复账号
		{
			Student newstu(ID, username, password);
			Vstu.push_back(newstu);
		}
		if (select == '2')
		{
			Teacher newstu(ID, username, password);
			Vtea.push_back(newstu);
		}
		add.close();//关闭流
		break;
	}
}

//显示账号
void Manager::Show_Accouen()
{
	cout << "请输入查看账号的类型" << endl;
	cout << "1.查看学生账号" << endl;
	cout << "2.查看教师账号" << endl;
	cout << "3.查看所有账号" << endl;
	char select;
	while (true)
	{
		cin >> select;
		cin.ignore(10000, '\n');
		if (select == '1')
		{
			cout << "以下是所有学生账号的信息：" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//有无账号信息的提示
			for (Student out : Vstu)
			{
				cout << "ID:" << out.Student_ID << endl;
				cout << "Username:" << out.UserName << endl;
				cout << "Password:" << out.Password << endl;
				cout << "------------------------------" << endl;
			}
			system("pause");
			break;
		}
		if (select == '2')
		{
			cout << "以下是所有教师账号的信息：" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//有无账号信息的提示
			for (Teacher out : Vtea)
			{
				cout << "ID:" << out.Teacher_ID << endl;
				cout << "Username:" << out.UserName << endl;
				cout << "Password:" << out.Password << endl;
				cout << "------------------------------" << endl;
			}
			system("pause");
			break;
		}
		if (select == '3')
		{
			cout << "以下是所有学生账号的信息：" << endl;
			cout << "------------------------------" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//有无账号信息的提示
			for (Student out : Vstu)
			{
				cout << "ID:" << out.Student_ID << endl;
				cout << "Username:" << out.UserName << endl;
				cout << "Password:" << out.Password << endl;
				cout << "------------------------------" << endl;
			}
			cout << "//////////////////////////////" << endl;

			cout << "以下是所有教师账号的信息：" << endl;
			cout << "------------------------------" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//有无账号信息的提示
			for (Teacher out : Vtea)
			{
				cout << "ID:" << out.Teacher_ID << endl;
				cout << "Username:" << out.UserName << endl;
				cout << "Password:" << out.Password << endl;
				cout << "------------------------------" << endl;
			}
			system("pause");
			break;
		}
		cout << "请输入正确的选项" << endl;
		system("pause");
		continue;
	}
}

//显示机房信息
void Manager::Show_ComputerRoom_info()//显示机房信息
{
	cout << "以下是所有机房的信息：" << endl;
	cout << "------------------------------" << endl;
	for (auto info : Vcom)
	{
		cout << "机房编号：" << info.ComR_ID << " 机房容量：" << info.ComR_Maxsize << endl;
		cout << "------------------------------" << endl;
	}
	system("pause");
}

//显示所有人的预约
void Manager::Show_All_Oreder()
{

}

//清空预约记录
void Manager::Clean_Order()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	if (!ofs.is_open())//检查文件是否打开
	{
		cout << "ORDER_FILE文件打开失败" << endl;
		ofs.close();
	}
	Clear_Success();
}
