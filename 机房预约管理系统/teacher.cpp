#include"teacher.h"


Teacher::Teacher() {

}

Teacher::Teacher(int empid, string name, string password) {
	this->m_Empty = empid;
	this->m_Name = name;
	this->m_Password = password;
}

void Teacher::OperMenu() {//教师菜单

	cout << "欢迎教师：" << this->m_Name << "  登录！" << endl;
	cout << "\t\t --------------------------------------- \n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            1.查看所有人预约            |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            2.审 批 预 约               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            0.注 销 登 录               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t ---------------------------------------\n";
}

void Teacher::ShowAllOrder() {//教师显示所有人预约
	//因为和学生中的信息一样  直接调用学生的
	Student student;
	student.ShouAllOrder();
}

void Teacher::ValidOrder() {//教师审核预约管理
	cout << "--------------需要审核的记录如下----------------" << endl;

	OrderFile of;
	of.UpdateMemory();

	vector<int> v;
	int index = 1;
	int count = 0;
	for (int i = 0; i < of.Order_Size; i++) {
		if (of.mp_Order[i]["状态"] == "1") {
			cout << index++ << "、";
			cout << "日期：" << of.mp_Order[i]["日期"];
			cout << " 时间：" << of.mp_Order[i]["时间"];
			cout << " ID或职工编号：" << of.mp_Order[i]["ID或职工编号"];
			cout << " 姓名：" << of.mp_Order[i]["姓名"];
			cout << " 预约机房：" << of.mp_Order[i]["预约机房"];
			cout << "状态：审核中" << endl;
			v.push_back(i);
			count++;
		}
	}
	if (count == 0) {
		cout << "当前无审核记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "你需要审核那个记录呢" << endl;
	cout << "请选择(0退出)：";
	int select;
	
	while (1) {
		cin >> select;
		if (select >= 0 && select <= (int)v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "1.通过审核" << endl;
				cout << "2.不通过审核" << endl;
				int ret;
				cout << "请选择：";
				cin >> ret;
				if (ret == 1) {
					of.mp_Order[v[select - 1]]["状态"] = "2";
				}
				else if (ret == 2) {
					of.mp_Order[v[select - 1]]["状态"] = "-1";
				}
				cout << "审核完成！" << endl;
				of.UpdateOrderFile();
				break;
			}
		}
		else {
			cout << "选择错误，请重新选择！" << endl;
		}
	}
	system("pause");
	system("cls");
}