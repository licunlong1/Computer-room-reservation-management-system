#pragma once

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

#include"identity.h"
#include"teacher.h"
#include"student.h"


class Admin :public Identity {

public:
	Admin();
	Admin(string name, string password);

	//管理员菜单
	void OperMenu();

	//添加账号
	void AddPerson();

	//查看账号
	void ShowPerson();

	//查看机房信息
	void ShowComputer();

	//清空预约信息
	void ClearOrder();

	//初始化容器 把老师学生文件中的内容加入到内存当中
	void InitMember();
	
	//检查重复的学生和教师id  第一个是检查的id 第二个判断是学生还是老师
	bool CheckReapeat(int id,int type);

	//存储文件中老师学生的信息容器
	vector<Student> VStudent;
	vector<Teacher> VTeacher;
};

