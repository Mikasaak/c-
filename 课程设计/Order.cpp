#include"Order.h"
using namespace std;

//Date���вι���
Date::Date(const int year = 0, const int month = 0, const int day = 0) :Year(year), Month(month),Day(day)
{
}
//Date����Ԫ��������<<
ostream& operator << (ostream& cout, Date& D) 
{
	cout << D.Year << '/' << D.Month << '/' << D.Day ;
	return cout;
}

//Date��==����
bool Date::operator == (Date& D)
{
	if (D.Year == this->Year && D.Month == this->Month && D.Day == this->Day)
		return true;
	else
		return false;
}

//Time���вι���
Time::Time(const int behour = -1, const int beminute = -1, const int endhour = -1, const int endminute = -1)
	:Begin_Hour(behour),Begin_Minute(beminute),End_Hour(endhour),End_Minute(endminute)
{}

//Time����Ԫ��������<<
ostream& operator<<(ostream& cout, Time& T) 
{
	cout << T.Begin_Hour << ':' << T.Begin_Minute << "--" << T.End_Hour << ':' << T.End_Minute;
	return cout;
}

//Time��==����
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
//�ж�����ʱ����Ƿ����ཻ����//�Ƿ���true ���Ƿ���false
bool Time::Is_meet(Time& T)
{
	//���this�Ľ�����ʱ��С��T�Ŀ�ʼʱ�� ���ص�
	if ((this->End_Hour < T.Begin_Hour)|| ((this->End_Hour == T.Begin_Hour) && (this->End_Minute <= T.Begin_Minute)))
		return false;
	if ((this->Begin_Hour > T.End_Hour) || ((this->Begin_Hour == T.End_Hour) && (this->Begin_Minute >= T.End_Minute)))
		return false;

	return true;
}

//OrderLog�޲ι��캯��
OrderLog::OrderLog() 
{
	//cout << "һ����" << endl;

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())//����ļ��Ƿ��
	{
		cout << "ORDER_FILE�ļ���ʧ��" << endl;
		ifs.close();
	}
	string ComRoomID;//�������
	string date;//����
	string time;//ʱ���
	string StuName;//ѧ������
	string StuID;//ѧ��ѧ��
	string status;//״̬
	this->Map_size = 0;
	while (ifs >> ComRoomID && ifs >> date && ifs >> time && ifs >> StuName && ifs >> StuID && ifs >> status)
	{
		string key;
		string value;
		bool V_flag = true;//����ȷ���Ƿ����V_DateAndTime������//Ϊtrue ��ʱ����룬Ϊfalse��ʱ�򲻲���//
		//Ϊ����V_DateAndTime ������ԤԼ��¼���ݶ���û��ȡ����//��ֹ����ʱ�����ĺ������ִ���
		unordered_map<string, string > m;
		string VcomputerID;// ���ڴ��ʼ��Vector��string�ı���//������ʾ�������
		// ���ڴ��ʼ�����ڵı���
		int year=0;
		int month=0;
		int day=0;
		// ���ڴ��ʼ������ʱ��ı���
		int beginHour=-1;
		int beginMin=-1;
		int endHour=-1;
		int endMin=-1;
		int pos = ComRoomID.find(':');//����ComRoomIDð��ǰ��Ĳ���
		if (pos != -1)
		{
			key = ComRoomID.substr(0, pos);
			value = ComRoomID.substr(pos + 1, ComRoomID.size() - pos - 1);
			VcomputerID = value;//��VcomputerID��ֵ��
			m.insert(make_pair(key, value));
		}

		pos = date.find(':');//����Dateð��ǰ��Ĳ���
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
			//��Date��ÿ�������������
			int p = value.find('/');//���ڴ洢��ͷ���ҳ��ĵ�һ����/�����±ꣻ
			int q = value.rfind('/');//���ڴ洢��β���ҳ��ĵ�һ����/�����±�//��Ϊ�ڶ�����/�����±�
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

		pos = time.find(':');//����Timeð��ǰ��Ĳ���
		if (pos != -1)
		{
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos - 1);
			m.insert(make_pair(key, value));
			//��Time��ÿ�������������
			int p = value.find(':');//���ڴ洢��ͷ���ҳ��ĵ�һ����:�����±ꣻ
			int i = value.find("--");//���ڴ洢��ͷ���ҳ��ĵ�һ����--�����±ꣻ
			int q = value.rfind(':');//���ڴ洢��β���ҳ��ĵ�һ����:�����±ꣻ
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

		pos = StuName.find(':');//����StudentNameð��ǰ��Ĳ���
		if (pos != -1)
		{
			key = StuName.substr(0, pos);
			value = StuName.substr(pos + 1, StuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = StuID.find(':');//����StudentIDð��ǰ��Ĳ���
		if (pos != -1)
		{
			key = StuID.substr(0, pos);
			value = StuID.substr(pos + 1, StuID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(':');//����statusð��ǰ��Ĳ���
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			if (value == "Canceled"||value == "Failed")//�������ԤԼ��¼��״̬�� ȡ�� �Ļ��� ԤԼʧ�� ��
				V_flag = false;//��V_flag��־��Ϊ��//��ʾ������V_DateAndTime����֮��
			m.insert(make_pair(key, value));
		}
		if(V_flag==true)
		{ 
			Date D(year, month, day);//�ò�����ʼ��Date
			Time T(beginHour, beginMin, endHour, endMin);//�ò�����ʼ��Time
			V_DateAndTime.push_back(make_tuple(VcomputerID, D, T));//���� VcomputerID��������ţ���D�����ڣ�
			             									      //T ��ʱ��Σ���ɵ�Ԫ�����vector������
		}
		//��С��map�����Ĳ��뵽���map����֮��//���ڱ�ʾ���е�ԤԼ��¼
		//С��map������ʾһ��ԤԼ��¼

		this->Map_size++;
		this->M_AllOrder.insert(make_pair(this->Map_size, m));
	}
	ifs.close();
}
//����vector
/*for (auto it: V_DateAndTime)
{
	cout << "com_id:" << get<0>(it) << endl;
	cout << "Date:" << get<1>(it) << endl;
	cout << "Time:" << get<2>(it) << endl;
}*/

//����map
/*for (auto it :M_AllOrder)
{
	cout << "����Ϊ" << it.first << "value = " << endl;
	for (auto mit :it.second)
	{
		cout << mit.first << " " << mit.second << ' ';
	}
	cout << endl;
}*/

//����ԤԼ��¼//��typeΪ1��ʱ�������ı������¸���M_AllOrder��V_DateAndTime
			//��typeΪ2��ʱ������M_AllOrder�����¸����ı�
void OrderLog::UpdateOrder(const char type)
{
	//��typeΪ1��ʱ�������ı������¸���M_AllOrder��V_DateAndTime
	if (type == '1')
	{
		M_AllOrder.clear();
		V_DateAndTime.clear();
		ifstream ifs;
		ifs.open(ORDER_FILE, ios::in);
		if (!ifs.is_open())//����ļ��Ƿ��
		{
			cout << "ORDER_FILE�ļ���ʧ��" << endl;
			ifs.close();
		}
		string ComRoomID;//�������
		string date;//����
		string time;//ʱ���
		string StuName;//ѧ������
		string StuID;//ѧ��ѧ��
		string status;//״̬
		this->Map_size = 0;
		while (ifs >> ComRoomID && ifs >> date && ifs >> time && ifs >> StuName && ifs >> StuID && ifs >> status)
		{
			string key;
			string value;
			bool V_flag = true;//����ȷ���Ƿ����V_DateAndTime������//Ϊtrue ��ʱ����룬Ϊfalse��ʱ�򲻲���//
			//Ϊ����V_DateAndTime ������ԤԼ��¼���ݶ���û��ȡ����//��ֹ����ʱ�����ĺ������ִ���
			unordered_map<string, string > m;
			string VcomputerID;// ���ڴ��ʼ��Vector��string�ı���//������ʾ�������
			// ���ڴ��ʼ�����ڵı���
			int year = 0;
			int mouth = 0;
			int day = 0;
			// ���ڴ��ʼ������ʱ��ı���
			int beginHour = -1;
			int beginMin = -1;
			int endHour = -1;
			int endMin = -1;
			int pos = ComRoomID.find(':');//����ComRoomIDð��ǰ��Ĳ���
			if (pos != -1)
			{
				key = ComRoomID.substr(0, pos);
				value = ComRoomID.substr(pos + 1, ComRoomID.size() - pos - 1);
				VcomputerID = value;//��VcomputerID��ֵ��
				m.insert(make_pair(key, value));
			}

			pos = date.find(':');//����Dateð��ǰ��Ĳ���
			if (pos != -1)
			{
				key = date.substr(0, pos);
				value = date.substr(pos + 1, date.size() - pos - 1);
				m.insert(make_pair(key, value));
				//��Date��ÿ�������������
				int p = value.find('/');//���ڴ洢��ͷ���ҳ��ĵ�һ����/�����±ꣻ
				int q = value.rfind('/');//���ڴ洢��β���ҳ��ĵ�һ����/�����±�//��Ϊ�ڶ�����/�����±�
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

			pos = time.find(':');//����Timeð��ǰ��Ĳ���
			if (pos != -1)
			{
				key = time.substr(0, pos);
				value = time.substr(pos + 1, time.size() - pos - 1);
				m.insert(make_pair(key, value));
				//��Time��ÿ�������������
				int p = value.find(':');//���ڴ洢��ͷ���ҳ��ĵ�һ����:�����±ꣻ
				int i = value.find("--");//���ڴ洢��ͷ���ҳ��ĵ�һ����--�����±ꣻ
				int q = value.rfind(':');//���ڴ洢��β���ҳ��ĵ�һ����:�����±ꣻ
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

			pos = StuName.find(':');//����StudentNameð��ǰ��Ĳ���
			if (pos != -1)
			{
				key = StuName.substr(0, pos);
				value = StuName.substr(pos + 1, StuName.size() - pos - 1);
				m.insert(make_pair(key, value));
			}

			pos = StuID.find(':');//����StudentIDð��ǰ��Ĳ���
			if (pos != -1)
			{
				key = StuID.substr(0, pos);
				value = StuID.substr(pos + 1, StuID.size() - pos - 1);
				m.insert(make_pair(key, value));
			}

			pos = status.find(':');//����statusð��ǰ��Ĳ���
			if (pos != -1)
			{
				key = status.substr(0, pos);
				value = status.substr(pos + 1, status.size() - pos - 1);
				if (value == "Canceled"||value == "Failed")//�������ԤԼ��¼��״̬�� ȡ�� �Ļ��� ԤԼʧ�� ��
					V_flag = false;//��V_flag��־��Ϊ��//��ʾ������V_DateAndTime����֮��
				m.insert(make_pair(key, value));
			}
			if (V_flag == true)//
			{
				Date D(year, mouth, day);//�ò�����ʼ��Date
				Time T(beginHour, beginMin, endHour, endMin);//�ò�����ʼ��Time
				V_DateAndTime.push_back(make_tuple(VcomputerID, D, T));//���� VcomputerID��������ţ���D�����ڣ�
				//T ��ʱ��Σ���ɵ�Ԫ�����vector������
			}
			//��С��map�����Ĳ��뵽���map����֮��//���ڱ�ʾ���е�ԤԼ��¼
			//С��map������ʾһ��ԤԼ��¼

			this->Map_size++;
			this->M_AllOrder.insert(make_pair(this->Map_size, m));
		}
		ifs.close();
	}
	
	//��typeΪ1��ʱ������M_AllOrder�����¸����ı�
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