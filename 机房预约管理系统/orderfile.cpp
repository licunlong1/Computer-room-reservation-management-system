#include"orderfile.h"

OrderFile::OrderFile() {

}

void OrderFile::UpdateOrderFile() {
	if (this->Order_Size == 0) {
		cout << "文件中没有记录呢！";
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out);
	for (int i = 0; i < this->Order_Size; i++) {
		ofs << "日期 " << this->mp_Order[i]["日期"] << " " << "时间 " << this->mp_Order[i]["时间"] << " " 
			<< "ID或职工编号 "<< this->mp_Order[i]["ID或职工编号"] << " " << "姓名 " << this->mp_Order[i]["姓名"] 
			<< " " << "预约机房 "<< this->mp_Order[i]["预约机房"] << " " << "状态 " << this->mp_Order[i]["状态"] << endl;
	}
}

void OrderFile::UpdateMemory() {
	this->mp_Order.clear();
	this->Order_Size = 0;
	//构造函数
	ifstream ifs(ORDER_FILE, ios::in);
	string first1, first2, first3, first4, first5, first6;
	string second1, second2, second3, second4, second5, second6;
	map<string, string> mp_Order1;
	int pos = 0;
		
	while (ifs >> first1 && ifs >> second1&& ifs >> first2 && ifs >> second2&& ifs >> first3 && ifs >> second3
		&&ifs >> first4 && ifs >> second4 &&ifs >> first5 && ifs >> second5 &&ifs >> first6 && ifs >> second6) {
		mp_Order1.clear();
		mp_Order1.insert(make_pair(first1, second1));
		mp_Order1.insert(make_pair(first2, second2));
		mp_Order1.insert(make_pair(first3, second3));
		mp_Order1.insert(make_pair(first4, second4));
		mp_Order1.insert(make_pair(first5, second5));
		mp_Order1.insert(make_pair(first6, second6));
		//测试输出
		//cout << first << " " << second << endl;
		mp_Order.insert(make_pair(pos, mp_Order1));
		pos++;
		this->Order_Size++;
	}
		
	//测试输出
	//for (auto& mp : mp_Order) {
	//	cout << mp.first << "   " << endl;
	//	for (auto& mp1 : mp.second) {
	//		cout << mp1.first << "  " << mp1.second << endl;
	//	}
	//}
}
