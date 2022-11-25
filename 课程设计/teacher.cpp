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

}

void Teacher::AuditOrder()//审核申请人的预约
{

}