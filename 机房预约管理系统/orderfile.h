#include<iostream>

#include<string>
#include<map>
#include<fstream>
using namespace std;

#include"filename.h"

class OrderFile {
public:

	OrderFile();

	//更新文件的内容
	void UpdateOrderFile();

	//更新文件中的内容到内存
	void UpdateMemory();

	map<int, map<string, string>> mp_Order;

	//记录order的大小
	int Order_Size = 0;
};