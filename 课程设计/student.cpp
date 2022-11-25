#include"student.h";
#include<iostream>
using namespace std;

//将机房信息读入vector容器中//初始化存放机房信息的容器Vcom
int Student::Creat_ComputerRoom_Vector()
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
		cout << "ID:" << C.ComR_ID << " // " << "Maxsize:" << C.ComR_Maxsize << endl;
	}
	ifs.close();
	ComRSize = Vcom.size();
	return ComRSize;
}

//student类的无参构造
Student::Student()
{
	this->Creat_ComputerRoom_Vector();
}

//student类的有参构造//并初始化存放机房信息的容器Vcom
Student::Student(int id, string username, string password)
{
	Student_ID = id;
	UserName = username;
	Password = password;
	this->Creat_ComputerRoom_Vector();//初始化存放机房信息的容器Vcom
}

//显示学生身份的操作菜单
void Student::Menu()
{
	Student_Operat_Screen(UserName);
}

//申请预约////成功返回true 失败返回false
bool Student::ApplyOrder()
{
	ApplyOrder_Tips();
	string ComRoomID;
	int Year;
	int Month;
	int Day;
	string s_date;
	string  s_Year;
	string s_Month;
	string s_Day;

	string s_time;
	string s_Btime1;
	string s_Btime2;
	string s_Etime1;
	string s_Etime2;
	int Btime1;
	int Btime2;
	int Etime1;
	int Etime2;
	//添加预约功能的实现
	while (true)
	{
		
		cout << "以下是所有机房的信息：" << endl;
		cout << "------------------------------" << endl;
		for (auto info : Vcom)
		{
			cout << "机房编号：" << info.ComR_ID << " 机房容量：" << info.ComR_Maxsize << endl;
			cout << "------------------------------" << endl;
		}
		cout << "退回上一级请在数据中输入   *  "<<endl;
		cout << "------------------------------" << endl;
		fstream fs;
		fs.open(ORDER_FILE, ios::app);
		if (!fs.is_open())//检查文件是否打开
		{
			cout << "ORDER_FILE文件打开失败" << endl;
			fs.close();
		}
		//判断输入的机房编号是否有效//无效则重新输入直到输入正确
		while (true)
		{
			bool ID_can_break = false;
			cout << "请输入使用机房编号：\n";
			cin >> ComRoomID;
			//判断输入数据中有无* // 若有则退出循环，返回上一级
			if (find(ComRoomID.begin(), ComRoomID.end(), '*') != ComRoomID.end())
			{
				return false;
			}
			for (auto it : Vcom)
			{
				if (ComRoomID == it.ComR_ID)
				{
					ID_can_break = true;
					break;
				}
			}
			if (ID_can_break == true)
				break;

			cout << "请输入正确的机房编号" << endl;
			system("pause");
			continue;
		}

		//判断输入的日期是否符合标准//无效则重新输入直到输入正确
		while (true)
		{
			bool Date_can_break = true;
			cout << "请输入使用日期：\n";
			
			//输入时间段数据，各个部分用string储存
			cin >> s_Year;
			cin >> s_Month;
			cin >> s_Day;
			//用string流把各个部分string转为int型的数据
			stringstream ss;
			s_date = s_Year + s_Month + s_Day;
			ss << s_Year;
			ss >> Year;
			ss.clear();
			ss << s_Month;
			ss >> Month;
			ss.clear();
			ss << s_Day;
			ss >> Day;
			ss.clear();
			//判断输入数据中有无* // 若有则退出循环，返回上一级
			if (find(s_date.begin(), s_date.end(), '*') != s_date.end())
			{
				return false;
			}
			//cout << s_date;//测试
			if (Year < 2022)
			{
				cout << "请输入正确的年" << endl;
				Date_can_break = false;
			}
			if (Month <= 0 || Month > 12)
			{
				Date_can_break = false;
				cout << "请输入正确的月" << endl;
			}
			if (Day > 31)
			{
				cout << "请输入正确的日" << endl;
				Date_can_break = false;
			}
			if (Date_can_break == true)
			{
				break;
			}
			system("pause");
			continue;
		}
		
		//判断输入时间段是否合法//无效则重新输入直到输入正确
		while (true)
		{
			bool Time_can_break = true;
			cout << "请输入使用时间段：\n";
			//输入时间段数据，各个部分用string储存
			cin >> s_Btime1 >> s_Btime2;
			cin >> s_Etime1 >> s_Etime2;
			//用string流把各个部分string转为int型的数据
			stringstream ss;
			ss << s_Btime1;
			ss >> Btime1;
			ss.clear();
			ss << s_Btime2;
			ss >> Btime2;
			ss.clear();
			ss << s_Etime1;
			ss >> Etime1;
			ss.clear();
			ss << s_Etime2;
			ss >> Etime2;
			ss.clear();
			s_time = s_Btime1 + s_Btime2 + s_Etime1 + s_Etime2;//拼接各个时间部分
			//判断输入数据中有无* // 若有则退出循环，返回上一级
			if (find(s_time.begin(), s_time.end(), '*') != s_time.end())
			{
				return false;
			}
			//cout << s_time<<endl;//测试

			if (Btime1 < 8 || Etime1 < 8 || Btime1 >= 21 || Etime1 >= 21)
			{
				Time_can_break = false;
				cout << "输入的时间不在机房开放时间内" << endl;
			}

			if (Btime1 > Etime1 || (Btime1 == Etime1 && Btime2 >= Etime2))
			{
				Time_can_break = false;
				cout << "开始时间不能大于等于结束时间" << endl;
			}

			if (Btime2 < 0 || Btime2 > 60 || Etime2 < 0 || Etime2>60)
			{
				Time_can_break = false;
				cout << "分钟数不能大于60或小于0" << endl;
			}

			if (Time_can_break == true)
			{
				break;
			}
			system("pause");
			continue;
		}

		Date date(Year, Month, Day);//创建Date对象
		Time time(Btime1, Btime2, Etime1, Etime2);//创建Time对象
		bool is_Meet = false;//用于判断是否是否之前的预约相冲突的标志变量
		//用for循环判断创建的新预约是否之前的预约相冲突
		for (auto it : orderlog.V_DateAndTime)
		{
			if (get<0>(it) == ComRoomID)//判断是否找到相同机房编号
			{
				if (date == get<1>(it) && time.Is_meet(get<2>(it)))
				{
					is_Meet = true;
					break;
				}
			}
		}
		if (is_Meet == true)
		{

			fs.close();
			Apply_Fail_Prompt();
			return false;

		}
		//cout << date.Year << " " << date.Month << ' ' << date.Day << endl;
		//fs << "ComputerRoomID:" << ComRoomID << ' ';
		fs << "ComputerRoomID:" << ComRoomID << ' ';
		fs << "Date:" << s_Year << '/' << s_Month << '/' << s_Day << ' ';
		fs << "Time:" << s_Btime1 << ':' << s_Btime2 << "--" << s_Etime1 << ':' << s_Etime2 << ' ';
		fs << "StudentName:" << this->UserName << ' ' << "StudentID:" << this->Student_ID << ' ';
		fs << "Status:Applying " << "\n";
		
		//进行OrderLog容器的更新
		string D;
		string T;
		string Stuid = to_string(this->Student_ID);

		D = s_Year + '/' + s_Month + '/' + s_Day;
		T = s_Btime1 + ":" + s_Btime2 + "--" + s_Etime1 + ":" + s_Etime2;
		unordered_map<string, string>m;
		m.insert(make_pair("ComputerRoomID", ComRoomID));
		m.insert(make_pair("Date", D));
		m.insert(make_pair("Time", T));
		m.insert(make_pair("StudentName", this->UserName));
		m.insert(make_pair("StudentID", Stuid));
		m.insert(make_pair("Status", "Apply"));
		orderlog.M_AllOrder.insert(make_pair(++orderlog.Map_size, m));//更新M_AllOrder
		orderlog.V_DateAndTime.push_back(make_tuple(ComRoomID, date, time));//更新V_DateAndTime
		//容器更新完成

		//测试容器更新情况
		/*for (auto it : orderlog.M_AllOrder)
		{
			cout << "第" << it.first << "条:";
			for (auto it2 : it.second)
			{
				cout << it2.first << ':' << it2.second << ' ';
			}cout << endl;
		}*/
		/*for (auto it : orderlog.V_DateAndTime)
		{
			cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
		}*/
		//测试完成
		fs.close();
		Apply_Success_Prompt();//申请预约成功的提示
		return true;
	}
	
}

//显示我的预约
void Student::ShowMyOrder()
{
	//用循环取出存在OrderLog对象里Map容器里用户为自己的内容//
	for (int i = 1; i <= orderlog.Map_size; i++)
	{
		//先判断是否是自己的学号与姓名
		if (orderlog.M_AllOrder[i]["StudentName"] == this->UserName &&
			orderlog.M_AllOrder[i]["StudentID"] == to_string(this->Student_ID))
		{
			//依次读出map容器的内容
			cout << "ComputerRoomID:" << orderlog.M_AllOrder[i]["ComputerRoomID"]<<' ';
			cout << "Date:" << orderlog.M_AllOrder[i]["Date"] << ' ';
			cout << "Time:" << orderlog.M_AllOrder[i]["Time"] << ' ';
			cout << "StudentName:" << orderlog.M_AllOrder[i]["StudentName"] << ' ';
			cout << "StudentID:" << orderlog.M_AllOrder[i]["StudentID"] << ' ';
			cout << "Status:" << orderlog.M_AllOrder[i]["Status"];
			cout << endl;
		}
	}
}

//显示所有人的预约
void Student::ShowAllOreder()
{
	//用循环取出存在OrderLog对象里Map容器里的内容//
	for (auto it : orderlog.M_AllOrder)
	{
		cout << "第" << it.first << "条:";
		for (auto it2 : it.second)
		{
			cout << it2.first << ':' << it2.second<<' ';
		}cout << endl;
	}
	
}

//取消自己的预约
void Student::CancalMyOrder()
{
	vector<int>sub;
	//用循环取出存在OrderLog对象里Map容器里用户为自己的内容//
	for (int i = 1; i <= orderlog.Map_size; i++)
	{
		//先判断是否是自己的学号与姓名
		if (orderlog.M_AllOrder[i]["StudentName"] == this->UserName
			&& orderlog.M_AllOrder[i]["StudentID"] == to_string(this->Student_ID)
			&& orderlog.M_AllOrder[i]["Status"] != "Canceled")
		{
			sub.push_back(i);
			//依次读出map容器的内容
			cout << "第" << sub.size() << "条:";
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
		cout << "请输入您要取消的预约记录的序号\n";
		cout << "若想中断取消操作请按   *   \n";
		string number;
		int num;
		cin >> number;
		if (find(number.begin(), number.end(), '*') != number.end())//若输入中有*  则中断取消预约操作
		{
			return;
		}
		//若没有 * 则用string转换为int 进行下一步判断
		stringstream ss;
		ss << number;
		ss >> num;
		ss.clear();
		if (num<1 || num>sub.size())
		{
			cout << "请输入正确的记录序号" << endl;
			continue;
		}
		else
		{
			//测试更新后的V_DateAndTime
			/*for (auto it: orderlog.V_DateAndTime)
			{
				cout << "com_id:" << get<0>(it) << endl;
				cout << "Date:" << get<1>(it) << endl;
				cout << "Time:" << get<2>(it) << endl;
			}*/
			orderlog.M_AllOrder[sub[num - 1]]["Status"] = "Canceled";
			//将取消的记录从V_DateAndTime中去掉
			string Com_id;
			string s_date;
			string s_time;
			int year;
			int month;
			int day;
			int B_hour;
			int B_min;
			int E_hour;
			int E_min;
			Com_id = orderlog.M_AllOrder[sub[num - 1]]["ComputerRoomID"];
			s_date = orderlog.M_AllOrder[sub[num - 1]]["Date"];
			s_time = orderlog.M_AllOrder[sub[num - 1]]["Time"];
			/*cout << Com_id << endl;
			cout << s_date << endl;
			cout << s_time << endl;*/
			//将Date的每个参数分离出来
			int D_p = s_date.find('/');//用于存储从头查找出的第一个‘/’的下标；
			int D_q = s_date.rfind('/');//用于存储从尾查找出的第一个‘/’的下标//即为第二个‘/’的下标
			stringstream ss;
			ss << s_date.substr(0, D_p);
			ss >> year;
			//cout << year << endl;
			ss.clear();
			ss << s_date.substr(D_p + 1, D_q - D_p - 1);
			ss >> month;
			//cout << month << endl;
			ss.clear();
			ss << s_date.substr(D_q + 1, s_date.size() - D_p - 1);
			ss >> day;
			//cout << day << endl;
			ss.clear();
			//将Time的每个参数分离出来
			int T_p = s_time.find(':');//用于存储从头查找出的第一个‘:’的下标；
			int T_i = s_time.find("--");//用于存储从头查找出的第一个‘--’的下标；
			int T_q = s_time.rfind(':');//用于存储从尾查找出的第一个‘:’的下标；
			ss << s_time.substr(0, T_p);
			ss >> B_hour;
			//cout << B_hour<<endl;
			ss.clear();

			ss << s_time.substr(T_p + 1, T_i - T_p - 1);
			ss >> B_min;
			//cout << B_min<<endl;
			ss.clear();

			ss << s_time.substr(T_i + 2, T_q - T_i - 2);
			ss >> E_hour;
			//cout << E_hour << endl;
			ss.clear();

			ss << s_time.substr(T_q + 1, s_time.size() - T_q - 1);
			ss >> E_min;
			//cout << E_min << endl;
			ss.clear();

			Date D(year, month, day);
			Time T(B_hour, B_min, E_hour, E_min);
			for (auto it = orderlog.V_DateAndTime.begin(); it != orderlog.V_DateAndTime.end();)
			{
				if (get<0>(*it) == Com_id && get<1>(*it) == D && get<2>(*it) == T)
				{
					it = orderlog.V_DateAndTime.erase(it);
				}
				else
				{
					++it;
				}
			}
			//测试更新后的V_DateAndTime
			/*for (auto it : orderlog.V_DateAndTime)
			{
				cout << "com_id:" << get<0>(it) << endl;
				cout << "Date:" << get<1>(it) << endl;
				cout << "Time:" << get<2>(it) << endl;
			}*/
			orderlog.UpdateOrder('2');
			Cancel_Success_Prompt();
			return;
		}

	}
	
	
}