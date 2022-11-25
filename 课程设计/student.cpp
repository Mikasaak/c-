#include"student.h";
#include<iostream>
using namespace std;

//��������Ϣ����vector������//��ʼ����Ż�����Ϣ������Vcom
int Student::Creat_ComputerRoom_Vector()
{
	ifstream ifs;
	int ComRSize = 0;
	ifs.open(COMPUTER_FILE, ios::in);//�Ի�����Ϣ�ļ����ж�ȡ
	if (!ifs.is_open())//����ļ��Ƿ��
	{
		cout << "COMPUTER_FILE�ļ���ʧ��" << endl;
		ifs.close();
	}
	Vcom.clear();
	ComputerRoom C;
	while (ifs >> C.ComR_ID && ifs >> C.ComR_Maxsize)//���ļ��жԻ�����Ϣ���ж�ȡ����ΪComputerRoom����ֵ
	{
		Vcom.push_back(C);//���������������
		cout << "ID:" << C.ComR_ID << " // " << "Maxsize:" << C.ComR_Maxsize << endl;
	}
	ifs.close();
	ComRSize = Vcom.size();
	return ComRSize;
}

//student����޲ι���
Student::Student()
{
	this->Creat_ComputerRoom_Vector();
}

//student����вι���//����ʼ����Ż�����Ϣ������Vcom
Student::Student(int id, string username, string password)
{
	Student_ID = id;
	UserName = username;
	Password = password;
	this->Creat_ComputerRoom_Vector();//��ʼ����Ż�����Ϣ������Vcom
}

//��ʾѧ����ݵĲ����˵�
void Student::Menu()
{
	Student_Operat_Screen(UserName);
}

//����ԤԼ////�ɹ�����true ʧ�ܷ���false
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
	//���ԤԼ���ܵ�ʵ��
	while (true)
	{
		
		cout << "���������л�������Ϣ��" << endl;
		cout << "------------------------------" << endl;
		for (auto info : Vcom)
		{
			cout << "������ţ�" << info.ComR_ID << " ����������" << info.ComR_Maxsize << endl;
			cout << "------------------------------" << endl;
		}
		cout << "�˻���һ����������������   *  "<<endl;
		cout << "------------------------------" << endl;
		fstream fs;
		fs.open(ORDER_FILE, ios::app);
		if (!fs.is_open())//����ļ��Ƿ��
		{
			cout << "ORDER_FILE�ļ���ʧ��" << endl;
			fs.close();
		}
		//�ж�����Ļ�������Ƿ���Ч//��Ч����������ֱ��������ȷ
		while (true)
		{
			bool ID_can_break = false;
			cout << "������ʹ�û�����ţ�\n";
			cin >> ComRoomID;
			//�ж���������������* // �������˳�ѭ����������һ��
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

			cout << "��������ȷ�Ļ������" << endl;
			system("pause");
			continue;
		}

		//�ж�����������Ƿ���ϱ�׼//��Ч����������ֱ��������ȷ
		while (true)
		{
			bool Date_can_break = true;
			cout << "������ʹ�����ڣ�\n";
			
			//����ʱ������ݣ�����������string����
			cin >> s_Year;
			cin >> s_Month;
			cin >> s_Day;
			//��string���Ѹ�������stringתΪint�͵�����
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
			//�ж���������������* // �������˳�ѭ����������һ��
			if (find(s_date.begin(), s_date.end(), '*') != s_date.end())
			{
				return false;
			}
			//cout << s_date;//����
			if (Year < 2022)
			{
				cout << "��������ȷ����" << endl;
				Date_can_break = false;
			}
			if (Month <= 0 || Month > 12)
			{
				Date_can_break = false;
				cout << "��������ȷ����" << endl;
			}
			if (Day > 31)
			{
				cout << "��������ȷ����" << endl;
				Date_can_break = false;
			}
			if (Date_can_break == true)
			{
				break;
			}
			system("pause");
			continue;
		}
		
		//�ж�����ʱ����Ƿ�Ϸ�//��Ч����������ֱ��������ȷ
		while (true)
		{
			bool Time_can_break = true;
			cout << "������ʹ��ʱ��Σ�\n";
			//����ʱ������ݣ�����������string����
			cin >> s_Btime1 >> s_Btime2;
			cin >> s_Etime1 >> s_Etime2;
			//��string���Ѹ�������stringתΪint�͵�����
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
			s_time = s_Btime1 + s_Btime2 + s_Etime1 + s_Etime2;//ƴ�Ӹ���ʱ�䲿��
			//�ж���������������* // �������˳�ѭ����������һ��
			if (find(s_time.begin(), s_time.end(), '*') != s_time.end())
			{
				return false;
			}
			//cout << s_time<<endl;//����

			if (Btime1 < 8 || Etime1 < 8 || Btime1 >= 21 || Etime1 >= 21)
			{
				Time_can_break = false;
				cout << "�����ʱ�䲻�ڻ�������ʱ����" << endl;
			}

			if (Btime1 > Etime1 || (Btime1 == Etime1 && Btime2 >= Etime2))
			{
				Time_can_break = false;
				cout << "��ʼʱ�䲻�ܴ��ڵ��ڽ���ʱ��" << endl;
			}

			if (Btime2 < 0 || Btime2 > 60 || Etime2 < 0 || Etime2>60)
			{
				Time_can_break = false;
				cout << "���������ܴ���60��С��0" << endl;
			}

			if (Time_can_break == true)
			{
				break;
			}
			system("pause");
			continue;
		}

		Date date(Year, Month, Day);//����Date����
		Time time(Btime1, Btime2, Etime1, Etime2);//����Time����
		bool is_Meet = false;//�����ж��Ƿ��Ƿ�֮ǰ��ԤԼ���ͻ�ı�־����
		//��forѭ���жϴ�������ԤԼ�Ƿ�֮ǰ��ԤԼ���ͻ
		for (auto it : orderlog.V_DateAndTime)
		{
			if (get<0>(it) == ComRoomID)//�ж��Ƿ��ҵ���ͬ�������
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
		
		//����OrderLog�����ĸ���
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
		orderlog.M_AllOrder.insert(make_pair(++orderlog.Map_size, m));//����M_AllOrder
		orderlog.V_DateAndTime.push_back(make_tuple(ComRoomID, date, time));//����V_DateAndTime
		//�����������

		//���������������
		/*for (auto it : orderlog.M_AllOrder)
		{
			cout << "��" << it.first << "��:";
			for (auto it2 : it.second)
			{
				cout << it2.first << ':' << it2.second << ' ';
			}cout << endl;
		}*/
		/*for (auto it : orderlog.V_DateAndTime)
		{
			cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
		}*/
		//�������
		fs.close();
		Apply_Success_Prompt();//����ԤԼ�ɹ�����ʾ
		return true;
	}
	
}

//��ʾ�ҵ�ԤԼ
void Student::ShowMyOrder()
{
	//��ѭ��ȡ������OrderLog������Map�������û�Ϊ�Լ�������//
	for (int i = 1; i <= orderlog.Map_size; i++)
	{
		//���ж��Ƿ����Լ���ѧ��������
		if (orderlog.M_AllOrder[i]["StudentName"] == this->UserName &&
			orderlog.M_AllOrder[i]["StudentID"] == to_string(this->Student_ID))
		{
			//���ζ���map����������
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

//��ʾ�����˵�ԤԼ
void Student::ShowAllOreder()
{
	//��ѭ��ȡ������OrderLog������Map�����������//
	for (auto it : orderlog.M_AllOrder)
	{
		cout << "��" << it.first << "��:";
		for (auto it2 : it.second)
		{
			cout << it2.first << ':' << it2.second<<' ';
		}cout << endl;
	}
	
}

//ȡ���Լ���ԤԼ
void Student::CancalMyOrder()
{
	vector<int>sub;
	//��ѭ��ȡ������OrderLog������Map�������û�Ϊ�Լ�������//
	for (int i = 1; i <= orderlog.Map_size; i++)
	{
		//���ж��Ƿ����Լ���ѧ��������
		if (orderlog.M_AllOrder[i]["StudentName"] == this->UserName
			&& orderlog.M_AllOrder[i]["StudentID"] == to_string(this->Student_ID)
			&& orderlog.M_AllOrder[i]["Status"] != "Canceled")
		{
			sub.push_back(i);
			//���ζ���map����������
			cout << "��" << sub.size() << "��:";
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
		cout << "��������Ҫȡ����ԤԼ��¼�����\n";
		cout << "�����ж�ȡ�������밴   *   \n";
		string number;
		int num;
		cin >> number;
		if (find(number.begin(), number.end(), '*') != number.end())//����������*  ���ж�ȡ��ԤԼ����
		{
			return;
		}
		//��û�� * ����stringת��Ϊint ������һ���ж�
		stringstream ss;
		ss << number;
		ss >> num;
		ss.clear();
		if (num<1 || num>sub.size())
		{
			cout << "��������ȷ�ļ�¼���" << endl;
			continue;
		}
		else
		{
			//���Ը��º��V_DateAndTime
			/*for (auto it: orderlog.V_DateAndTime)
			{
				cout << "com_id:" << get<0>(it) << endl;
				cout << "Date:" << get<1>(it) << endl;
				cout << "Time:" << get<2>(it) << endl;
			}*/
			orderlog.M_AllOrder[sub[num - 1]]["Status"] = "Canceled";
			//��ȡ���ļ�¼��V_DateAndTime��ȥ��
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
			//��Date��ÿ�������������
			int D_p = s_date.find('/');//���ڴ洢��ͷ���ҳ��ĵ�һ����/�����±ꣻ
			int D_q = s_date.rfind('/');//���ڴ洢��β���ҳ��ĵ�һ����/�����±�//��Ϊ�ڶ�����/�����±�
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
			//��Time��ÿ�������������
			int T_p = s_time.find(':');//���ڴ洢��ͷ���ҳ��ĵ�һ����:�����±ꣻ
			int T_i = s_time.find("--");//���ڴ洢��ͷ���ҳ��ĵ�һ����--�����±ꣻ
			int T_q = s_time.rfind(':');//���ڴ洢��β���ҳ��ĵ�һ����:�����±ꣻ
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
			//���Ը��º��V_DateAndTime
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