#include"Operat.h"

//mananger�����˵��Ĳ���ʵ��
void Manage_Mainmenu_Operat(Identity*& manager)//����Ա�˵��еĲ����߼�
{

	while (true)//��ѡ���˳��ò������һֱ�ڴ˲����ѡ�����
	{
		manager->Menu();//���ö�̬�ø���ָ�������ʾ�˵��ĺ���
		
		Manager* user = (Manager*)manager;//�Ѹ���ָ��ת��ΪMangerָ��

		char select;//���ڽ���ѡ��ı���
		cin >> select;//�û�����ѡ��
		cin.ignore(10000, '\n');//�������뻺����
		if (select == '1')//��������˺ŵĲ���
		{
			Operat_Lev_Showing('M',1);//��ʾ�����㣨����˺ţ�
			user->Add_Account();
		}

		if (select == '2')//���в鿴�˺ŵĲ���
		{
			Operat_Lev_Showing('M', 2);//��ʾ�����㣨�鿴�˺ţ�
			user->Show_Accouen();
		}

		if (select == '3') //���в鿴�����Ĳ���
		{
			Operat_Lev_Showing('M', 3);//��ʾ�����㣨�鿴������
			user->Show_ComputerRoom_info();

		}
		if (select == '4')//������ʾ����ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('M', 4);//��ʾ�����㣨���ԤԼ��
			user->Show_All_Oreder();
		}

		if (select == '5')//�������ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('M', 4);//��ʾ�����㣨���ԤԼ��
			user->Clean_Order();

		}

		if (select == '*')//���з���ע������һ���Ĳ���
		{
			delete manager;
			Logout_Prompt();
			system("cls");
			return;
		}

		if (select == '0')//���з���ֱ���˳�ϵͳ����
			Direct_Exit_Prompt();
	}
}

//student�����˵��Ĳ���ʵ��
void Student_Mainmenu_Operat(Identity*& student)
{
	while (true)//��ѡ���˳��ò������һֱ�ڴ˲����ѡ�����
	{
		student->Menu();//���ö�̬�ø���ָ�������ʾ�˵��ĺ���

		Student* user = (Student*)student;//�Ѹ���ָ��ת��ΪStudentָ��

		char select;//���ڽ���ѡ��ı���
		cin >> select;//�û�����ѡ��
		cin.ignore(10000, '\n');//�������뻺����

		if (select == '1')//��������ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('S',1);//��ʾ�����㣨����ԤԼ��
			user->ApplyOrder();
			//system("pause");
		}

		if (select == '2')//������ʾ�û��Լ�ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('S', 2);//��ʾ�����㣨��ʾ�ҵ�ԤԼ��
			user->ShowMyOrder(); 
			system("pause");
		}

		if (select == '3') //������ʾ�����˵�ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('S', 3);//��ʾ�����㣨��ʾ�����˵�ԤԼ��
			user->ShowAllOreder();
			system("pause");
		}

		if (select == '4')//����ȡ���Լ���ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('S', 4);//��ʾ�����㣨ȡ���Լ���ԤԼ��
			user->CancalMyOrder();
			system("pause");
		}

		if (select == '*')//���з���ע������һ���Ĳ���
		{
			delete student;
			Logout_Prompt();
			system("cls");
			return;
		}

		if (select == '0')//���з���ֱ���˳�ϵͳ����
			Direct_Exit_Prompt();
	}
}

//teacher�����˵��Ĳ���ʵ��
void Teacher_Mainmenu_Operat(Identity*& teacher)
{
	while (true)//��ѡ���˳��ò������һֱ�ڴ˲����ѡ�����
	{
		teacher->Menu();//���ö�̬�ø���ָ�������ʾ�˵��ĺ���

		Teacher* user = (Teacher*)teacher;//�Ѹ���ָ��ת��ΪMangerָ��

		char select;//���ڽ���ѡ��ı���
		cin >> select;//�û�����ѡ��
		cin.ignore(10000, '\n');//�������뻺����

		if (select == '1')//������ʾ�����˵�ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('T',1);//��ʾ�����㣨��ʾ�����˵�ԤԼ��
			user->ShowAllOreder();

		}

		if (select == '2')//������������˵�ԤԼ�Ĳ���
		{
			Operat_Lev_Showing('T', 2);//��ʾ�����㣨��������˵�ԤԼ��
			user->AuditOrder();

		}

		if (select == '*')//���з���ע������һ���Ĳ���
		{
			delete teacher;
			Logout_Prompt();
			system("cls");
			return;
		}

		if (select == '0')//���з���ֱ���˳�ϵͳ����
			Direct_Exit_Prompt();
	}
}

//���ڲ�ͬ����ݽ��е�¼��������Ӧ����//����ֵΪIdentityָ��
Identity* Login_AND_Creat(string file_name, char select)
{
	Identity* person = NULL;//����ָ������ָ���������

	ifstream read;
	read.open(file_name, ios::in);
	if (!read.is_open())
	{
		cout << "file_not_open\n";
		read.close();
		return person;
	}
	int ID = 0;
	string username;//�������������û��������Ϣ
	string password;
	if (select != '3')
	{
		cout << "����������ѧ�Ż�ְ����\nID:";
		cin >> ID;
	}
	cout << "�����������û���\nUsername:";
	cin >> username;
	cout << "��������������\nPassword:";
	cin >> password;
	if (select == '1')//��ѧ����ݵ��˽��������֤
	{
		int check_ID;//�ļ��ж�����������֤��¼��ID,username,password
		string check_username;
		string check_password;
		while (read >> check_ID && read >> check_username && read >> check_password)//���ж���
		{
			if (check_ID == ID && check_username == username && check_password == password)//���бȽ�
			{
				Login_Success_Prompt(select);//��½�ɹ�����ʾ
				person = new Student(ID, username, password);//�û���ָ�����ָ�򴴽���ѧ������
				return person;
			}

		}


	}
	else if (select == '2')//�Խ�ʦ��ݵ��˽��������֤
	{
		int check_ID;//�ļ��ж�����������֤��¼��ID,username,password
		string check_username;
		string check_password;
		while (read >> check_ID && read >> check_username && read >> check_password)//���ж���
		{
			if (check_ID == ID && check_username == username && check_password == password)//���бȽ�
			{
				Login_Success_Prompt(select);//��½�ɹ�����ʾ
				person = new Teacher(ID, username, password);//�û���ָ�����ָ�򴴽��Ľ�ʦ����
				return person;
			}
		}
	}
	else if (select == '3')//�Թ���Ա��ݵ��˽��������֤
	{
		//�ļ��ж�����������֤��¼��username,password
		string check_username;
		string check_password;
		while (read >> check_username && read >> check_password)//���ж���
		{
			if (check_username == username && check_password == password)//���бȽ�
			{
				Login_Success_Prompt(select);//��½�ɹ�����ʾ
				person = new Manager(username, password);//�û���ָ�����ָ�򴴽��Ĺ���Ա����
				return person;
			}

		}
	}


	Login_Fail_Prompt();//��¼ʧ�ܵ���ʾ
	return person;



}