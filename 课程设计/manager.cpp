#include"manager.h"
#include"Screen.h"
using namespace std;


//��student��teacher���˺���Ϣ����vector����������ֵΪpair��һ��Ԫ��Ϊstudent��
//�˺Ÿ������ڶ���Ԫ��Ϊteacher�˺ŵĸ���
pair<int, int> Manager::Creat_ST_Vector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);//��ѧ���˺��ļ����ж�ȡ
	if (!ifs.is_open())//����ļ��Ƿ��
	{
		cout << "STUDENT_FILE�ļ���ʧ��" << endl;
		ifs.close();
	}
	Vstu.clear();
	Vtea.clear();
	int studentSize = 0;
	int teacherSize = 0;
	Student S;
	while (ifs >> S.Student_ID && ifs >> S.UserName && ifs >> S.Password)//���ļ���
	{
		Vstu.push_back(S);
	}
	studentSize = Vstu.size();
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);//�Խ�ʦ�˺��ļ����ж�ȡ
	if (!ifs.is_open())//����ļ��Ƿ��
	{
		cout << "TEACHER_FILE�ļ���ʧ��" << endl;
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

//��������Ϣ����vector������
int Manager::Creat_ComputerRoom_Vector()
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
		//cout << "ID:" << C.ComR_ID << " // " << "Maxsize:" << C.ComR_Maxsize << endl;
	}
	ifs.close();
	ComRSize = Vcom.size();
	return ComRSize;
}

//�޲ι���
Manager::Manager()
{

}

//�вι����ʼ������Ա������������vector��������student��teacher���˺���Ϣ
Manager::Manager(string username, string password)
{
	this->UserName = username;
	this->Password = password;
	this->Creat_ST_Vector();//��ʼ�����ѧ������ʦ�˺���Ϣ������
	this->Creat_ComputerRoom_Vector();//��ʼ����Ż�����Ϣ������

}

//��ʾ����Ա��ݵĲ����˵�
void Manager::Menu()
{
	Manager_Operat_Screen(UserName);
}

//��⴫���ID�����Ƿ������е�ѧ������ʦ��ID�����ظ�������bool���ͣ�����ظ�����true�����򷵻�false��
bool Manager::Is_Repeat(const int id, const char type)
{
	if (type == '1')//���������ѧ��
	{
		for (Student tmp : Vstu)//��������Vstu����������������id�ظ���ֵ�������򷵻�true
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
			if (tmp.Teacher_ID == id)//��������Vtea����������������id�ظ���ֵ�������򷵻�true
			{
				return true;
			}
		}
	}

	return false;//���򷵻�false
}

//���ѧ�����ʦ�˺�
void Manager::Add_Account()
{
	cout << "��ѡ��Ҫ���еĲ���" << endl;
	cout << "1.���ѧ���˺�" << endl;
	cout << "2.��ӽ�ʦ�˺�" << endl;
	cout << "*.������һ��" <<   endl;
	string file_name;
	char select;
	while (true)
	{
		cin >> select;
		cin.ignore(10000, '\n');
		if (select == '1')
		{
			file_name = STUDENT_FILE;
			cout << "��������Ҫ���ѧ����ѧ�š��û��������룺\nID:";
			break;
		}
		if (select == '2')
		{
			file_name = TEACHER_FILE;
			cout << "��������Ҫ��ӽ�ʦ��ְ���š��û��������룺\nID:";
			break;
		}
		if (select == '*')
		{
			break;
		}
		cout << "��������ȷ��ѡ��" << endl;
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
		if (Is_Repeat(ID, select))//����Ƿ���֮ǰ���ظ�//����ظ���������
		{
			Is_Add_Account_Prompt(select, '2');//��ʾ����˺ŵ�״̬
			break;
		}

		add.open(file_name, ios::app);//��׷�ӵķ�ʽ���ļ�
		if (!add.is_open())//����ļ��Ƿ��
		{
			cout << "�ļ���ʧ��" << endl;
			add.close();
		}
		add << ID << ' ' << username << ' ' << password << ' ' << endl;//���ļ���д����Ϣ
		Is_Add_Account_Prompt(select, '1');//��ʾ����˺ŵ�״̬
		
		if (select == '1')//����ѧ������ʦ�˺������ڵ���Ϣ����ֹһ��������ظ��˺�
		{
			Student newstu(ID, username, password);
			Vstu.push_back(newstu);
		}
		if (select == '2')
		{
			Teacher newstu(ID, username, password);
			Vtea.push_back(newstu);
		}
		add.close();//�ر���
		break;
	}
}

//��ʾ�˺�
void Manager::Show_Accouen()
{
	cout << "������鿴�˺ŵ�����" << endl;
	cout << "1.�鿴ѧ���˺�" << endl;
	cout << "2.�鿴��ʦ�˺�" << endl;
	cout << "3.�鿴�����˺�" << endl;
	char select;
	while (true)
	{
		cin >> select;
		cin.ignore(10000, '\n');
		if (select == '1')
		{
			cout << "����������ѧ���˺ŵ���Ϣ��" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//�����˺���Ϣ����ʾ
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
			cout << "���������н�ʦ�˺ŵ���Ϣ��" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//�����˺���Ϣ����ʾ
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
			cout << "����������ѧ���˺ŵ���Ϣ��" << endl;
			cout << "------------------------------" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//�����˺���Ϣ����ʾ
			for (Student out : Vstu)
			{
				cout << "ID:" << out.Student_ID << endl;
				cout << "Username:" << out.UserName << endl;
				cout << "Password:" << out.Password << endl;
				cout << "------------------------------" << endl;
			}
			cout << "//////////////////////////////" << endl;

			cout << "���������н�ʦ�˺ŵ���Ϣ��" << endl;
			cout << "------------------------------" << endl;
			if (Vstu.size() == 0)
				Is_Have_Account_Prompt(select);//�����˺���Ϣ����ʾ
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
		cout << "��������ȷ��ѡ��" << endl;
		system("pause");
		continue;
	}
}

//��ʾ������Ϣ
void Manager::Show_ComputerRoom_info()//��ʾ������Ϣ
{
	cout << "���������л�������Ϣ��" << endl;
	cout << "------------------------------" << endl;
	for (auto info : Vcom)
	{
		cout << "������ţ�" << info.ComR_ID << " ����������" << info.ComR_Maxsize << endl;
		cout << "------------------------------" << endl;
	}
	system("pause");
}

//��ʾ�����˵�ԤԼ
void Manager::Show_All_Oreder()
{

}

//���ԤԼ��¼
void Manager::Clean_Order()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	if (!ofs.is_open())//����ļ��Ƿ��
	{
		cout << "ORDER_FILE�ļ���ʧ��" << endl;
		ofs.close();
	}
	Clear_Success();
}
