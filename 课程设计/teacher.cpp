#include"teacher.h";

Teacher::Teacher()//无参构造
{

}

Teacher::Teacher(int empid, string username, string password)//有参构造
{
	Teacher_ID = empid;
	UserName = username;
	Password = Password;
}

void Teacher::Menu()//显示教师身份的操作菜单
{
	Teacher_Operat_Screen(UserName);
}

void Teacher::ShowAllOreder()//显示所有人的预约
{
	for (auto it : orderlog.M_AllOrder)
	{
		cout << "第" << it.first << "条:";
		for (auto it2 : it.second)
		{
			cout << it2.first << ':' << it2.second << ' ';
		}cout << endl;
	}
	cout << "*输出完成*" << endl;
	system("pause");
}

void Teacher::AuditOrder()//审核申请人的预约
{
	vector<int> sub;
	if (orderlog.M_AllOrder.size() == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;
	for (int i = 1; i <= orderlog.Map_size; ++i)
	{
		//先判断是否是自己的学号与姓名
		if (orderlog.M_AllOrder[i]["Status"] == "Applying")
		{
			sub.push_back(i);
			cout << "第" << sub.size() << "条:";
			//依次读出map容器的内容
			cout << "ComputerRoomID:" << orderlog.M_AllOrder[i]["ComputerRoomID"] << ' ';
			cout << "Date:" << orderlog.M_AllOrder[i]["Date"] << ' ';
			cout << "Time:" << orderlog.M_AllOrder[i]["Time"] << ' ';
			cout << "StudentName:" << orderlog.M_AllOrder[i]["StudentName"] << ' ';
			cout << "StudentID:" << orderlog.M_AllOrder[i]["StudentID"] << ' ';
			cout << "Status:" << orderlog.M_AllOrder[i]["Status"];
			cout << endl;
		}
	}
	
	while (true)
	{
		cout << "请输入审核的预约记录，*代表返回" << endl;
		string select; //接受用户选择的预约记录
		int sel = 0;
		cin >> select;
		if (find(select.begin(), select.end(), '*') != select.end())//若输入中有*号则退出函数
		{
			return;
		}
		stringstream ss;
		ss << select;
		ss >> sel;
		ss.clear();
		if (sel<1 || sel>sub.size())//如果输入的预约记录的序号不在规定范围内//重新输入
		{
			cout << "请输入正确的预约记录的序号" << endl;
			system("pause");
			continue;
		}
		cout << "请输入审核结果" << endl;
		cout << "1、通过" << endl;
		cout << "2、不通过" << endl;
		char ret;
		cin >> ret;
		if (ret == '1')
		{
			orderlog.M_AllOrder[sub[sel - 1]]["Status"] = "Passed";
		}
		else if (ret == '2')
		{
			orderlog.M_AllOrder[sub[sel - 1]]["Status"] = "Failed";
		}
		else 
		{
			cout << "请输入正确的选择序号" << endl;
			system("pause");
			continue;
		}
		orderlog.UpdateOrder('2'); // 用M_AllOrder更新文本文件
		cout << "审核完毕" << endl;
		system("pause");
		break;
		//因为是在教师类进行应用，不需要判断预约记录是否相冲突，所以不需要进行V_DateAndTime的更新

	}
	
}