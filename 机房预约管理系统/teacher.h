#pragma once

#include<iostream>

using namespace std;

#include"identity.h"
#include"student.h"

class Teacher :public Identity {
public:
	Teacher();
	Teacher(int empid, string name, string password);

	//教师菜单
	void OperMenu();

	//查看所有预约
	void ShowAllOrder();

	//审核预约
	void ValidOrder();

	//教师职工编号
	int m_Empty = 0;
};