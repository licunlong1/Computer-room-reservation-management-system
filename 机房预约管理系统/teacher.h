#pragma once

#include<iostream>

using namespace std;

#include"identity.h"
#include"student.h"

class Teacher :public Identity {
public:
	Teacher();
	Teacher(int empid, string name, string password);

	//��ʦ�˵�
	void OperMenu();

	//�鿴����ԤԼ
	void ShowAllOrder();

	//���ԤԼ
	void ValidOrder();

	//��ʦְ�����
	int m_Empty = 0;
};