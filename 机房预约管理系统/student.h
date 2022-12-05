#pragma once
#include<iostream>
#include<string>

using namespace std;


#include"identity.h"

class Student :public Identity{
public:
	//���캯��
	Student();

	//�вι��캯��
	Student(int id, string name, string password);
	
	//��ʾѧ���˵�
	void OperMenu();

	//����ԤԼ
	void ApplyOrder();

	//�鿴�ҵ�ԤԼ
	void ShowMyOrder();

	//�鿴����ԤԼ
	void ShouAllOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	//��ʼ��ѧ����Ϣ
	void InitStudent();

	//���ڴ���Ϣ���ص��ļ���
	void InitStudentFile();

	//�޸�����
	void ModifyPassword();

	//ѧ��ѧ��
	int m_Id = 0;

	//�洢ѧ���������Ϣ
	map<int, map<string, string>> mp_Student;

	//��¼ѧ������
	int StudentNum = 0;
};