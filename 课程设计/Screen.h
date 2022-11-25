#pragma once
#include<string>
using namespace std;

void Main_Operat_Screen();//主选择操作界面

void Manager_Operat_Screen(const string username);//管理员选择操作界面

void Student_Operat_Screen(const string username);//学生选择操作界面

void Teacher_Operat_Screen(const string username);//教师选择操作界面

void Student_Login_Screen();//学生登录界面

void Teacher_Login_Screen();//教师登录界面

void Manager_Login_Screen();//管理员登录界面

void Login_Success_Prompt(const char type);//登录成功的反馈提示

void Login_Fail_Prompt();//登录失败的反馈提示

void Logout_Prompt();//注销成功的反馈提示

void Clear_Success();////预约清空成功的反馈提示

void Direct_Exit_Prompt();//直接退出系统的提示

void Is_Add_Account_Prompt(const char fir,const char sec);//显示账号添加状态的提示

void Is_Have_Account_Prompt(const char type);//显示是否有账号信息的提示

void Operat_Lev_Showing(const char usertype, const int type);//显示所在操作层userType表示用户类型 operatType表示指令序号

void ApplyOrder_Tips();//进行申请预约的操作提示和机房情况说明界面

void Apply_Success_Prompt();//申请预约成功的提示

void Apply_Fail_Prompt();//申请预约失败的提示

void Cancel_Success_Prompt();//取消预约成功的提示