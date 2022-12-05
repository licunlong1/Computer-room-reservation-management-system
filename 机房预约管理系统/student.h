#pragma once
#include<iostream>
#include<string>

using namespace std;


#include"identity.h"

class Student :public Identity{
public:
	//构造函数
	Student();

	//有参构造函数
	Student(int id, string name, string password);
	
	//显示学生菜单
	void OperMenu();

	//申请预约
	void ApplyOrder();

	//查看我的预约
	void ShowMyOrder();

	//查看所有预约
	void ShouAllOrder();

	//取消预约
	void CancelOrder();

	//初始化学生信息
	void InitStudent();

	//把内存信息加载到文件中
	void InitStudentFile();

	//修改密码
	void ModifyPassword();

	//学生学号
	int m_Id = 0;

	//存储学生密码的信息
	map<int, map<string, string>> mp_Student;

	//记录学生个数
	int StudentNum = 0;
};