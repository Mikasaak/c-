#pragma once
#include<string>
using namespace std;

void Main_Operat_Screen();//��ѡ���������

void Manager_Operat_Screen(const string username);//����Աѡ���������

void Student_Operat_Screen(const string username);//ѧ��ѡ���������

void Teacher_Operat_Screen(const string username);//��ʦѡ���������

void Student_Login_Screen();//ѧ����¼����

void Teacher_Login_Screen();//��ʦ��¼����

void Manager_Login_Screen();//����Ա��¼����

void Login_Success_Prompt(const char type);//��¼�ɹ��ķ�����ʾ

void Login_Fail_Prompt();//��¼ʧ�ܵķ�����ʾ

void Logout_Prompt();//ע���ɹ��ķ�����ʾ

void Clear_Success();////ԤԼ��ճɹ��ķ�����ʾ

void Direct_Exit_Prompt();//ֱ���˳�ϵͳ����ʾ

void Is_Add_Account_Prompt(const char fir,const char sec);//��ʾ�˺����״̬����ʾ

void Is_Have_Account_Prompt(const char type);//��ʾ�Ƿ����˺���Ϣ����ʾ

void Operat_Lev_Showing(const char usertype, const int type);//��ʾ���ڲ�����userType��ʾ�û����� operatType��ʾָ�����

void ApplyOrder_Tips();//��������ԤԼ�Ĳ�����ʾ�ͻ������˵������

void Apply_Success_Prompt();//����ԤԼ�ɹ�����ʾ

void Apply_Fail_Prompt();//����ԤԼʧ�ܵ���ʾ

void Cancel_Success_Prompt();//ȡ��ԤԼ�ɹ�����ʾ