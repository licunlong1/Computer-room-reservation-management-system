#include<iostream>

#include<string>
#include<map>
#include<fstream>
using namespace std;

#include"filename.h"

class OrderFile {
public:

	OrderFile();

	//�����ļ�������
	void UpdateOrderFile();

	//�����ļ��е����ݵ��ڴ�
	void UpdateMemory();

	map<int, map<string, string>> mp_Order;

	//��¼order�Ĵ�С
	int Order_Size = 0;
};