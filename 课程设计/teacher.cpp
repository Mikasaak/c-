#include"teacher.h";

Teacher::Teacher()//�޲ι���
{

}

Teacher::Teacher(int empid, string username, string password)//�вι���
{
	Teacher_ID = empid;
	UserName = username;
	Password = Password;
}

void Teacher::Menu()//��ʾ��ʦ��ݵĲ����˵�
{
	Teacher_Operat_Screen(UserName);
}

void Teacher::ShowAllOreder()//��ʾ�����˵�ԤԼ
{
	for (auto it : orderlog.M_AllOrder)
	{
		cout << "��" << it.first << "��:";
		for (auto it2 : it.second)
		{
			cout << it2.first << ':' << it2.second << ' ';
		}cout << endl;
	}
	cout << "*������*" << endl;
	system("pause");
}

void Teacher::AuditOrder()//��������˵�ԤԼ
{
	vector<int> sub;
	if (orderlog.M_AllOrder.size() == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	for (int i = 1; i <= orderlog.Map_size; ++i)
	{
		//���ж��Ƿ����Լ���ѧ��������
		if (orderlog.M_AllOrder[i]["Status"] == "Applying")
		{
			sub.push_back(i);
			cout << "��" << sub.size() << "��:";
			//���ζ���map����������
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
		cout << "��������˵�ԤԼ��¼��*������" << endl;
		string select; //�����û�ѡ���ԤԼ��¼
		int sel = 0;
		cin >> select;
		if (find(select.begin(), select.end(), '*') != select.end())//����������*�����˳�����
		{
			return;
		}
		stringstream ss;
		ss << select;
		ss >> sel;
		ss.clear();
		if (sel<1 || sel>sub.size())//��������ԤԼ��¼����Ų��ڹ涨��Χ��//��������
		{
			cout << "��������ȷ��ԤԼ��¼�����" << endl;
			system("pause");
			continue;
		}
		cout << "��������˽��" << endl;
		cout << "1��ͨ��" << endl;
		cout << "2����ͨ��" << endl;
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
			cout << "��������ȷ��ѡ�����" << endl;
			system("pause");
			continue;
		}
		orderlog.UpdateOrder('2'); // ��M_AllOrder�����ı��ļ�
		cout << "������" << endl;
		system("pause");
		break;
		//��Ϊ���ڽ�ʦ�����Ӧ�ã�����Ҫ�ж�ԤԼ��¼�Ƿ����ͻ�����Բ���Ҫ����V_DateAndTime�ĸ���

	}
	
}