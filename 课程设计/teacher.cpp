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

}

void Teacher::AuditOrder()//��������˵�ԤԼ
{

}