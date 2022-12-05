#include"admin.h"
#include"filename.h"


Admin::Admin() {

}

Admin::Admin(string name, string password) {
	this->m_Name = name;
	this->m_Password = password;

	//初始化内存
	InitMember();
	this->InitComputer();
}

void Admin::OperMenu() {
	cout << "欢迎管理员：" << this->m_Name << "  登录！" << endl;
	cout << "\t\t --------------------------------------- \n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            1.添 加 账 户               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            2.查 看 账 户               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            3.查 看 机 房               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            4.清 空 预 约               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            0.注 销 登 录               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t ---------------------------------------\n";
}

void Admin::AddPerson() {//添加人员信息账号密码
	cout << "请选择你想要添加的账户" << endl;
	cout << "1.学生账户" << endl;
	cout << "2.教师账户" << endl;
	string filename;
	string tip;
	string errortip;

	int select;
	cout << "请输入你的选择：";
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "请输入学生id号：";
		errortip = "当前学生id已经存在，输入错误！";
	}
	else if (select == 2) {
		filename = TEACHER_FILE;
		tip = "请输入教师的职工号：";
		errortip = "当前教师职工编号已经存在，输入错误！";
	}
	else {
		cout << "选择错误，重新选择！" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofstream ofs(filename, ios::out | ios::app);
	int fid;
	string fname, fpassword;
	//switch (select) {
	//case 1:
	//{
	//	cout << tip << endl;
	//	cin >> fid;
	//	cout<<"请输入用户名"
	//}
	//	break;
	//case 2:
	//	break;
	//default:
	//	cout << "输入有误！" << endl;
	//	system("pause");
	//	system("cls");
	//	break;
	//}
	cout << tip;
	cin >> fid;
	if (!this->CheckReapeat(fid, select)) {
		cout << errortip << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入用户名：";
	cin >> fname;
	cout << "请输入密码：";
	cin >> fpassword;
	ofs << fid << " " << fname << " " << fpassword << endl;
	cout << "添加成功" << endl;
	ofs.close();
	if (select == 1) {
		VStudent.push_back(Student(fid, fname, fpassword));
	}
	else if (select == 2) {
		VTeacher.push_back(Teacher(fid, fname, fpassword));
	}
	system("pause");
	system("cls");
}

//打印学生信息
void PrintStudent(const Student& s) {
	cout << "学生ID：" << s.m_Id << "       账户：" << s.m_Name << "       密码：" << s.m_Password << endl;
}

//打印教师信息
void PrintTeacher(const Teacher& t) {

	cout << "教师职工编号：" << t.m_Empty << "       账户：" << t.m_Name << "       密码：" << t.m_Password << endl;
}


void Admin::ShowPerson() {//显示人员信息
	
	cout << "1.查看学生账户" << endl;
	cout << "2.查看教师账户" << endl;
	cout << "请输入你的选择：";
	int select;
	cin >> select;
	if (select == 1) {
		for_each(VStudent.begin(), VStudent.end(), PrintStudent);
	}
	else if (select == 2) {
		for_each(VTeacher.begin(), VTeacher.end(), PrintTeacher);
	}
	else {
		cout << "选择错误！" << endl;
	}
	system("pause");
	system("cls");
}


void Admin::ShowComputer() {//显示机房信息
	
	for (auto& mp : mp_Computer) {
		cout << "机房编号：" << mp.first << "       机房容量：" << mp.second << endl;
	}
	system("pause");
	system("cls");
}

void Admin::ClearOrder() {//清空预约信息
	cout << "确定清空么" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();

		cout << "清空预约信息完成！" << endl;
	}
	else if (select == 2) {
		cout << "取消清空！" << endl;
	}

	system("pause");
	system("cls");
}

void Admin::InitMember() {
	this->VTeacher.clear();
	this->VStudent.clear();
	this->mp_Computer.clear();
	int fid;
	string fname, fpassword;
	ifstream ifs(TEACHER_FILE, ios::in);
	while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
		this->VTeacher.push_back(Teacher(fid, fname, fpassword));
	}
	//cout << "当前教师有" << this->VTeacher.size() << "人" << endl;
	ifs.close();
	ifs.open(STUDENT_FILE, ios::in);
	while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
		this->VStudent.push_back(Student(fid, fname, fpassword));
	}
	//cout << "当前学生有" << this->VStudent.size() << "人" << endl;
	ifs.close();
}

bool Admin::CheckReapeat(int id,int type) {
	if (type == 1) {
		//vector<Student>::iterator it = find(VStudent.begin(), VStudent.end(), id);
		for(auto &it:VStudent)
			if (it.m_Id == id) {
				return false;
			}
	}
	else {
		//vector<Teacher>::iterator it = find(VTeacher.begin(), VTeacher.end(), id);
		for(auto &it:VTeacher)
			if (it.m_Empty != id) {
				return false;
			}
	}

	return true;
}