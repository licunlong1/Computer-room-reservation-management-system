#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
#include"filename.h"
#include"orderfile.h"
class Identity {
public:
	virtual void OperMenu() = 0;

	//��ʼ��������Ϣ
	void InitComputer() {
		ifstream ifs(COMPUTER_FILE, ios::in);
		int roomid;
		int capacity;
		while (ifs >> roomid && ifs >> capacity) {
			mp_Computer.insert(make_pair(roomid, capacity));
		}
		//�����������
		//cout << mp_Computer[1] << endl;
		//cout << mp_Computer[2] << endl;
		//cout << mp_Computer[3] << endl;
		ifs.close();
	}

	string m_Name;
	string m_Password;

	//ά����������Ϣ
	map<int, int>mp_Computer;

	//�洢��ʦ�������Ϣ
	map<int, map<string, string>> mp_Teacher;
};

//void Identity::InitComputer() {
//
//	ifstream ifs(COMPUTER_FILE, ios::in);
//	int roomid;
//	int capacity;
//	while (ifs >> roomid && ifs >> capacity) {
//		mp_Computer.insert(make_pair(roomid, capacity));
//	}
//	cout << mp_Computer[1] << endl;
//	cout << mp_Computer[2] << endl;
//	cout << mp_Computer[3] << endl;
//	ifs.close();
//}