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

	//����Ա�˵�
	void OperMenu();

	//����˺�
	void AddPerson();

	//�鿴�˺�
	void ShowPerson();

	//�鿴������Ϣ
	void ShowComputer();

	//���ԤԼ��Ϣ
	void ClearOrder();

	//��ʼ������ ����ʦѧ���ļ��е����ݼ��뵽�ڴ浱��
	void InitMember();
	
	//����ظ���ѧ���ͽ�ʦid  ��һ���Ǽ���id �ڶ����ж���ѧ��������ʦ
	bool CheckReapeat(int id,int type);

	//�洢�ļ�����ʦѧ������Ϣ����
	vector<Student> VStudent;
	vector<Teacher> VTeacher;
};

