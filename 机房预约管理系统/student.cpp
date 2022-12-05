#include"student.h"

Student::Student() {

}

Student::Student(int id, string name, string password) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = password;
}

void Student::OperMenu() {//学生菜单
	cout << "欢迎学生：" << this->m_Name << "  登录！" << endl;
	cout << "\t\t --------------------------------------- \n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            1.申 请 预 约               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            2.查看个人预约              |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            3.查看所有人预约            |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            4.取 消 预 约               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            5.修 改 密 码               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            0.注 销 登 录               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t ---------------------------------------\n";
}


void Student::ApplyOrder() {//申请预约
	cout << "（预约时间段为周一到周五，星期天不可预约！）\n"
		<< "1.星期一\n" << "2.星期二\n" << "3.星期三\n" << "4.星期四\n" << "5.星期五\n"<<"0.取消选择\n";
	cout << "你想要周几预约呢，请选择：";
	int date;
	cin >> date;
	if (date > 0 && date < 6) {
		cout << "1.上午\t\t2.下午" << endl;
		cout << "你要预约什么时间呢，请选择：";
		int time;
		cin >> time;
		//把机房的内容加载到内存当中
		this->InitComputer();
		for (auto& mp : mp_Computer) {
			cout << "机房编号：" << mp.first << "       机房容量：" << mp.second << endl;
		}
		cout << "你要预约那个机房呢，请选择：";
		int computer;
		cin >> computer;
		cout << "预约成功！正在审核中！" << endl;
		//显示状态的字符串
		string status;
		
		ofstream ofs(ORDER_FILE, ios::app);
		ofs << "日期 星期" << date << " " << "时间 " << time << " " << "ID或职工编号 " 
			<< this->m_Id << " "<< "姓名 " << this->m_Name << " " << "预约机房 " 
			<< computer << "号机房" << " " << "状态 " << "1" << endl;
		ofs.close();
		system("pause");
		system("cls");
		return;
	}
	cout << "取消选择！" << endl;
	system("pause");
	system("cls");
}

void Student::ShowMyOrder() {//显示自己的预约
	//ifstream ifs(ORDER_FILE, ios::in);
	//if (!ifs.is_open()) {
	//	cout << "file no find!" << endl;
	//	
	//	ifs.close();
	//	return;
	//}
	//std::string id = std::to_string(this->m_Id);
	OrderFile of;
	of.UpdateMemory();
	for (int i = 0; i < of.Order_Size; i++) {
		if (this->m_Id == atoi(of.mp_Order[i]["ID或职工编号"].c_str())) {
			cout << "日期：" << of.mp_Order[i]["日期"] << " ";
			cout << "时间：" << (of.mp_Order[i]["时间"] == "1" ? "上午" : "下午");
			cout << " ID或职工编号：" << of.mp_Order[i]["ID或职工编号"];
			cout << " 姓名：" << of.mp_Order[i]["姓名"];
			cout << " 预约机房：" << of.mp_Order[i]["预约机房"];
			string status = " 审核状态：";
			//0取消预约 1审核中 2预约成功 -1预约失败
			if (of.mp_Order[i]["状态"] == "1") {
				status += "审核中";
			}
			else if (of.mp_Order[i]["状态"] == "2") {
				status += "预约成功";
			}
			else if (of.mp_Order[i]["状态"] == "-1") {
				status += "预约失败";
			}
			else if (of.mp_Order[i]["状态"] == "0") {
				status += "取消预约";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}


void Student::ShouAllOrder() {//显示所有人的预约

	//不能直接读取文件中的内容 因为文件中的内容跟用户想看到的内容不一样 需要保存起来
	//ifstream ifs(ORDER_FILE, ios::in);
	//if (!ifs.is_open()) {
	//	cout << "file no find!" << endl;

	//	ifs.close();
	//	return;
	//}
	//string date;
	//while (getline(ifs, date)) {
	//	cout << date << endl;
	//}
	//ifs.close();
	//system("pause");
	//system("cls");

	OrderFile of;
	of.UpdateMemory();
	if (of.Order_Size == 0) {
		cout << "记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.Order_Size; i++) {
		cout << i + 1 << "、";
		cout << "日期：" << of.mp_Order[i]["日期"] << " ";
		cout << "时间：" << (of.mp_Order[i]["时间"] == "1" ? "上午" : "下午");
		cout << " ID或职工编号：" << of.mp_Order[i]["ID或职工编号"];
		cout << " 姓名：" << of.mp_Order[i]["姓名"];
		cout << " 预约机房：" << of.mp_Order[i]["预约机房"];
		string status = " 审核状态：";
		//0取消预约 1审核中 2预约成功 -1预约失败
		if (of.mp_Order[i]["状态"] == "1") {
			status += "审核中";
		}
		else if (of.mp_Order[i]["状态"] == "2") {
			status += "预约成功";
		}
		else if (of.mp_Order[i]["状态"] == "-1") {
			status += "预约失败";
		}
		else if (of.mp_Order[i]["状态"] == "0") {
			status += "预约已经取消";
		}
		cout << status << endl;
	}

	//测试输出
	//for (auto& mp : of.mp_Order) {
	//	cout << mp.first << "、" ;
	//	for (auto& mp1 : mp.second) {
	//		cout << mp1.first << " ";
	//		if (mp1.second == "1") {
	//			cout << "上午";
	//		}
	//		else if (mp1.second == "2") {
	//			cout << "下午";
	//		}
	//		else {
	//			cout << mp1.second;
	//		}
	//	}
	//	cout << endl;
	//}
	system("pause");
	system("cls");
}

void Student::CancelOrder() {//取消预约
	cout << "------------只有审核中和预约成功的可以取消预约(只能取消自己的预约)--------------" << endl;
	OrderFile of;
	of.UpdateMemory();

	//对用户显示的记录 条
	vector<int> v;
	int index = 1;
	int count = 0;

	for (int i = 0; i < of.Order_Size; i++) {
		if (this->m_Id == atoi(of.mp_Order[i]["ID或职工编号"].c_str())) {
			if (of.mp_Order[i]["状态"] == "1" || of.mp_Order[i]["状态"] == "2") {
				cout << index++ << "、";
				cout << "日期：" << of.mp_Order[i]["日期"];
				cout << " 时间：" << of.mp_Order[i]["时间"];
				cout << " ID或职工编号：" << of.mp_Order[i]["ID或职工编号"];
				cout << " 姓名：" << of.mp_Order[i]["姓名"];
				cout << " 预约机房：" << of.mp_Order[i]["预约机房"];
				string status = " 状态：";
				if (of.mp_Order[i]["状态"] == "1") {
					status += "审核中";
				}
				else if (of.mp_Order[i]["状态"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
				v.push_back(i);
				count++;
			}
		}
	}
	if (count == 0) {
		cout << "当前无需要取消预约的记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "请输入你的选择(0退出预约)：";
	int select;
	
	while (1) {
		cin >> select;
		if (select >= 0 && select <= (int)v.size()) {
			if (select == 0)
				break;
			else {
				of.mp_Order[v[select - 1]]["状态"] = "0";
				of.UpdateOrderFile();
				cout << "你已经取消预约！" << endl;
				v.clear();
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

void Student::InitStudent() {
	this->mp_Student.clear();
	ifstream ifs(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "file no finde!" << endl;

		ifs.close();
		return;
	}
	int fid;
	string fname, fpassword;
	while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
		map<string, string> mps;
		mps.insert(make_pair(fname, fpassword));
		mp_Student.insert(make_pair(fid, mps));
		this->StudentNum++;
	}
	//测试输出
	//for (auto& mp : this->mp_Student) {
	//	cout << "ID:" << mp.first;
	//	for (auto& mp1 : mp.second) {
	//		cout << "姓名：" << mp1.first << " 密码：" << mp1.second << endl;
	//	}
	//}
}

void Student::ModifyPassword() {

	this->InitStudent();
	string password;
	cout << "请输入你的原密码：";
	cin >> password;
	if (password == this->mp_Student[this->m_Id][this->m_Name]) {
	again:
		cout << "请输入你的新密码：";
		string m_password;
		cin >> m_password;
		string m_password1;
		cout << "请再次输入你的新密码：";
		cin >> m_password1;
		if (m_password == m_password1) {
			this->mp_Student[this->m_Id][this->m_Name] = m_password;

			ofstream ofs(STUDENT_FILE, ios::out);
			//ofs << this->m_Id << " " << this->m_Name << " " << this->mp_Student[this->m_Id][this->m_Name];
			for (auto & password:mp_Student ) {
				ofs << password.first << " ";
				int i = 1;
				for (auto& password1 : password.second) {
					ofs << password1.first << " " << password1.second << endl;
					i++;
					if (i != 1)
						break;
				}
			}
			ofs.close();

			cout << "修改成功！" << endl;
		}
		else {
			cout << "两次密码不一样，请重新输入！" << endl;
			goto again;
		}
	}
	else {
		cout << "原密码错误！" << endl;
	}
	system("pause");
	system("cls");
}

void Student::InitStudentFile() {

}