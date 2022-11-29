#include"Order.h"
using namespace std;

//Date的有参构造
Date::Date(const int year = 0, const int month = 0, const int day = 0) :Year(year), Month(month),Day(day)
{
}
//Date的友元函数重载<<
ostream& operator << (ostream& cout, Date& D) 
{
	cout << D.Year << '/' << D.Month << '/' << D.Day ;
	return cout;
}

//Date的==重载
bool Date::operator == (Date& D)
{
	if (D.Year == this->Year && D.Month == this->Month && D.Day == this->Day)
		return true;
	else
		return false;
}

//Time的有参构造
Time::Time(const int behour = -1, const int beminute = -1, const int endhour = -1, const int endminute = -1)
	:Begin_Hour(behour),Begin_Minute(beminute),End_Hour(endhour),End_Minute(endminute)
{}

//Time的友元函数重载<<
ostream& operator<<(ostream& cout, Time& T) 
{
	cout << T.Begin_Hour << ':' << T.Begin_Minute << "--" << T.End_Hour << ':' << T.End_Minute;
	return cout;
}

//Time的==重载
bool Time::operator == (Time& T)
{
	if (this->Begin_Hour == T.Begin_Hour && this->Begin_Minute == T.Begin_Minute
		&& this->End_Hour == T.End_Hour && this->End_Minute == T.End_Minute)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//判断两个时间段是否有相交部分//是返回true 不是返回false
bool Time::Is_meet(Time& T)
{
	//如果this的结束的时间小于T的开始时间 则不重叠
	if ((this->End_Hour < T.Begin_Hour)|| ((this->End_Hour == T.Begin_Hour) && (this->End_Minute <= T.Begin_Minute)))
		return false;
	if ((this->Begin_Hour > T.End_Hour) || ((this->Begin_Hour == T.End_Hour) && (this->Begin_Minute >= T.End_Minute)))
		return false;

	return true;
}

//OrderLog无参构造函数
OrderLog::OrderLog() 
{
	//cout << "一构造" << endl;

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())//检查文件是否打开
	{
		cout << "ORDER_FILE文件打开失败" << endl;
		ifs.close();
	}
	string ComRoomID;//机房编号
	string date;//日期
	string time;//时间段
	string StuName;//学生姓名
	string StuID;//学生学号
	string status;//状态
	this->Map_size = 0;
	while (ifs >> ComRoomID && ifs >> date && ifs >> time && ifs >> StuName && ifs >> StuID && ifs >> status)
	{
		string key;
		string value;
		bool V_flag = true;//用来确定是否插入V_DateAndTime容器中//为true 的时候插入，为false的时候不插入//
		//为了让V_DateAndTime 里面存的预约记录数据都是没被取消的//防止误判时间相冲的函数出现错误
		unordered_map<string, string > m;
		string VcomputerID;// 用于存初始化Vector的string的变量//用来表示机房编号
		// 用于存初始化日期的变量
		int year=0;
		int month=0;
		int day=0;
		// 用于存初始化具体时间的变量
		int beginHour=-1;
		int beginMin=-1;
		int endHour=-1;
		int endMin=-1;
		int pos = ComRoomID.find(':');//分离ComRoomID冒号前后的部分
		if (pos != -1)
		{
			key = ComRoomID.substr(0, pos);
			value = ComRoomID.substr(pos + 1, ComRoomID.size() - pos - 1);
			VcomputerID = value;//给VcomputerID赋值；
			m.insert(make_pair(key, value));
		}

		pos = date.find(':');//分离Date冒号前后的部分
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
			//将Date的每个参数分离出来
			int p = value.find('/');//用于存储从头查找出的第一个‘/’的下标；
			int q = value.rfind('/');//用于存储从尾查找出的第一个‘/’的下标//即为第二个‘/’的下标
			stringstream ss;
			ss << value.substr(0, p);
			ss >> year;
			//cout << year << endl;
			ss.clear();
			ss << value.substr(p + 1, q - p - 1);
			ss >> month;
			//cout << month << endl;
			ss.clear();
			ss << value.substr(q + 1, value.size() - p - 1);
			ss >> day;
			ss.clear();
			//cout << day << endl;
		}

		pos = time.find(':');//分离Time冒号前后的部分
		if (pos != -1)
		{
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos - 1);
			m.insert(make_pair(key, value));
			//将Time的每个参数分离出来
			int p = value.find(':');//用于存储从头查找出的第一个‘:’的下标；
			int i = value.find("--");//用于存储从头查找出的第一个‘--’的下标；
			int q = value.rfind(':');//用于存储从尾查找出的第一个‘:’的下标；
			stringstream ss;
			ss << value.substr(0, p);
			ss >> beginHour;
			ss.clear();

			ss << value.substr(p + 1, i - p - 1);
			ss >> beginMin;
			ss.clear();

			ss << value.substr(i + 2, q - i - 2);
			ss >> endHour;
			ss.clear();

			ss << value.substr(q + 1, value.size() - q - 1);
			ss >> endMin;
			ss.clear();
		}

		pos = StuName.find(':');//分离StudentName冒号前后的部分
		if (pos != -1)
		{
			key = StuName.substr(0, pos);
			value = StuName.substr(pos + 1, StuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = StuID.find(':');//分离StudentID冒号前后的部分
		if (pos != -1)
		{
			key = StuID.substr(0, pos);
			value = StuID.substr(pos + 1, StuID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(':');//分离status冒号前后的部分
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			if (value == "Canceled"||value == "Failed")//如果该条预约记录的状态是 取消 的或是 预约失败 的
				V_flag = false;//把V_flag标志置为假//表示不加入V_DateAndTime容器之中
			m.insert(make_pair(key, value));
		}
		if(V_flag==true)
		{ 
			Date D(year, month, day);//用参数初始化Date
			Time T(beginHour, beginMin, endHour, endMin);//用参数初始化Time
			V_DateAndTime.push_back(make_tuple(VcomputerID, D, T));//将以 VcomputerID（机房编号），D（日期）
			             									      //T （时间段）组成的元组插入vector容器中
		}
		//将小的map容器的插入到大的map容器之中//用于表示所有的预约记录
		//小的map容器表示一条预约记录

		this->Map_size++;
		this->M_AllOrder.insert(make_pair(this->Map_size, m));
	}
	ifs.close();
}
//测试vector
/*for (auto it: V_DateAndTime)
{
	cout << "com_id:" << get<0>(it) << endl;
	cout << "Date:" << get<1>(it) << endl;
	cout << "Time:" << get<2>(it) << endl;
}*/

//测试map
/*for (auto it :M_AllOrder)
{
	cout << "条数为" << it.first << "value = " << endl;
	for (auto mit :it.second)
	{
		cout << mit.first << " " << mit.second << ' ';
	}
	cout << endl;
}*/

//更新预约记录//当type为1的时候是用文本来重新更新M_AllOrder和V_DateAndTime
			//当type为2的时候是用M_AllOrder来重新更新文本
void OrderLog::UpdateOrder(const char type)
{
	//当type为1的时候是用文本来重新更新M_AllOrder和V_DateAndTime
	if (type == '1')
	{
		M_AllOrder.clear();
		V_DateAndTime.clear();
		ifstream ifs;
		ifs.open(ORDER_FILE, ios::in);
		if (!ifs.is_open())//检查文件是否打开
		{
			cout << "ORDER_FILE文件打开失败" << endl;
			ifs.close();
		}
		string ComRoomID;//机房编号
		string date;//日期
		string time;//时间段
		string StuName;//学生姓名
		string StuID;//学生学号
		string status;//状态
		this->Map_size = 0;
		while (ifs >> ComRoomID && ifs >> date && ifs >> time && ifs >> StuName && ifs >> StuID && ifs >> status)
		{
			string key;
			string value;
			bool V_flag = true;//用来确定是否插入V_DateAndTime容器中//为true 的时候插入，为false的时候不插入//
			//为了让V_DateAndTime 里面存的预约记录数据都是没被取消的//防止误判时间相冲的函数出现错误
			unordered_map<string, string > m;
			string VcomputerID;// 用于存初始化Vector的string的变量//用来表示机房编号
			// 用于存初始化日期的变量
			int year = 0;
			int mouth = 0;
			int day = 0;
			// 用于存初始化具体时间的变量
			int beginHour = -1;
			int beginMin = -1;
			int endHour = -1;
			int endMin = -1;
			int pos = ComRoomID.find(':');//分离ComRoomID冒号前后的部分
			if (pos != -1)
			{
				key = ComRoomID.substr(0, pos);
				value = ComRoomID.substr(pos + 1, ComRoomID.size() - pos - 1);
				VcomputerID = value;//给VcomputerID赋值；
				m.insert(make_pair(key, value));
			}

			pos = date.find(':');//分离Date冒号前后的部分
			if (pos != -1)
			{
				key = date.substr(0, pos);
				value = date.substr(pos + 1, date.size() - pos - 1);
				m.insert(make_pair(key, value));
				//将Date的每个参数分离出来
				int p = value.find('/');//用于存储从头查找出的第一个‘/’的下标；
				int q = value.rfind('/');//用于存储从尾查找出的第一个‘/’的下标//即为第二个‘/’的下标
				stringstream ss;
				ss << value.substr(0, pos);
				ss >> year;
				//cout << year << endl;
				ss.clear();
				ss << value.substr(p + 1, q - p - 1);
				ss >> mouth;
				//cout << mouth << endl;
				ss.clear();
				ss << value.substr(q + 1, value.size() - p - 1);
				ss >> day;
				ss.clear();
				//cout << day << endl;
			}

			pos = time.find(':');//分离Time冒号前后的部分
			if (pos != -1)
			{
				key = time.substr(0, pos);
				value = time.substr(pos + 1, time.size() - pos - 1);
				m.insert(make_pair(key, value));
				//将Time的每个参数分离出来
				int p = value.find(':');//用于存储从头查找出的第一个‘:’的下标；
				int i = value.find("--");//用于存储从头查找出的第一个‘--’的下标；
				int q = value.rfind(':');//用于存储从尾查找出的第一个‘:’的下标；
				stringstream ss;
				ss << value.substr(0, p);
				ss >> beginHour;
				ss.clear();

				ss << value.substr(p + 1, i - p - 1);
				ss >> beginMin;
				ss.clear();

				ss << value.substr(i + 2, q - i - 2);
				ss >> endHour;
				ss.clear();

				ss << value.substr(q + 1, value.size() - q - 1);
				ss >> endMin;
				ss.clear();
			}

			pos = StuName.find(':');//分离StudentName冒号前后的部分
			if (pos != -1)
			{
				key = StuName.substr(0, pos);
				value = StuName.substr(pos + 1, StuName.size() - pos - 1);
				m.insert(make_pair(key, value));
			}

			pos = StuID.find(':');//分离StudentID冒号前后的部分
			if (pos != -1)
			{
				key = StuID.substr(0, pos);
				value = StuID.substr(pos + 1, StuID.size() - pos - 1);
				m.insert(make_pair(key, value));
			}

			pos = status.find(':');//分离status冒号前后的部分
			if (pos != -1)
			{
				key = status.substr(0, pos);
				value = status.substr(pos + 1, status.size() - pos - 1);
				if (value == "Canceled"||value == "Failed")//如果该条预约记录的状态是 取消 的或是 预约失败 的
					V_flag = false;//把V_flag标志置为假//表示不加入V_DateAndTime容器之中
				m.insert(make_pair(key, value));
			}
			if (V_flag == true)//
			{
				Date D(year, mouth, day);//用参数初始化Date
				Time T(beginHour, beginMin, endHour, endMin);//用参数初始化Time
				V_DateAndTime.push_back(make_tuple(VcomputerID, D, T));//将以 VcomputerID（机房编号），D（日期）
				//T （时间段）组成的元组插入vector容器中
			}
			//将小的map容器的插入到大的map容器之中//用于表示所有的预约记录
			//小的map容器表示一条预约记录

			this->Map_size++;
			this->M_AllOrder.insert(make_pair(this->Map_size, m));
		}
		ifs.close();
	}
	
	//当type为1的时候是用M_AllOrder来重新更新文本
	if (type == '2')
	{
		ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
		for (auto it : this->M_AllOrder)
		{
			for (auto it2 : it.second)
			{
				ofs << it2.first << ':' << it2.second << " ";
			}
			ofs << '\n';
		}
		ofs.close();
	}
	
}