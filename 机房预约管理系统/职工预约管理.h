
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include"identity.h"
#include"student.h"
#include"admin.h"
#include"teacher.h"
#include"filename.h"

void mainMenu() {
	cout << "======================欢迎来到学院机房预约管理系统========================" << endl;
	cout << endl << "请选择你的身份" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              1.学生代表               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              2.老    师               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              3.管 理 员               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              0.退    出               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "请输入你的选择：";
}

//管理员接口的实现
void AdminInter(Identity* &Person) {

	while (1) {
	again:
		Person->OperMenu();
		Admin* admin = (Admin*)Person;
		cout << "请输入你的选择：";
		int select;
		cin >> select;
		switch (select) {
		case 1://添加账户
			//cout << "添加账户" << endl;
			admin->AddPerson();
			break;
		case 2://查看所有账户
			admin->ShowPerson();
			break;
		case 3://查看机房
			admin->ShowComputer();
			break;
		case 4://清空机房预约
			admin->ClearOrder();
			break;
		case 0:
			cout << "注销成功！" << endl;
			system("cls");
			return;
			break;
		default:
			cout << "选择错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			goto again;
			break;
		}
	}
}

//学生接口的实现
void StudentInter(Identity* &Person) {
	while (1) {
	again:
		Person->OperMenu();
		Student* student = (Student*)Person;
		int select;
		cout << "请输入你的选择：";
		cin >> select;
		switch (select) {

		case 1://申请预约
			student->ApplyOrder();
			break;
		case 2://显示自己的预约
			student->ShowMyOrder();
			break;
		case 3://显示所有人的预约
			student->ShouAllOrder();
			break;
		case 4://取消预约
			student->CancelOrder();
			break;
		case 5://修改密码
			student->ModifyPassword();
			break;
		case 0:
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "选择错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			goto again;
			break;
		}
	}
}


//教师接口的实现
void TeacherInter(Identity* &Person) {
	while (1) {
	again:
		Person->OperMenu();

		Teacher* teacher = (Teacher*)Person;
		cout << "请输入你的选择：";
		int select;
		cin >> select;
		switch (select) {
		case 1://查看所有人的预约
			teacher->ShowAllOrder();
			break;
		case 2://审核预约
			teacher->ValidOrder();
			break;
		case 0://注销登录
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "选择错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			goto again;
			break;
		}
	}

}

void LoginCheck(string filename, int select) {

	Identity* Person = NULL;
	ifstream ifs(filename, ios::in);//打开文件
	if (!ifs.is_open()) {
		cout << "file no find" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;
	if (select == 1) {
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (select == 2) {
		cout << "请输入您的职工编号：";
		cin >> id;
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> password;

	//验证需要读取文件中的数据  用变量来接收他
	string fname;
	string fpassword;
	int fid;

	if (select == 1) {
		//验证学生登录
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//测试代码
			//cout << "学生验证" << endl;
			//cout << fid << endl;
			//cout << fname << endl;
			//cout << fpassword << endl;
			if (fid == id && fname == name && fpassword == password) {
				cout << "学生登录成功！" << endl;
				ifs.close();
				system("pause");
				system("cls");
				Person = new Student(id, name, password);
				//学生接口实现
				StudentInter(Person);
				return;
			}
		}
	}
	else if (select == 2) {
		//验证教师登录
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//测试代码
			//cout << "学生验证" << endl;
			//cout << fid << endl;
			//cout << fname << endl;
			//cout << fpassword << endl;
			if (fid == id && fname == name && fpassword == password) {
				cout << "教师登陆成功！" << endl;
				ifs.close();
				system("pause");
				system("cls");
				//教师接口实现
				Person = new Teacher(id, name, password);
				TeacherInter(Person);
				return;
			}
		}
	}
	else if (select == 3) {
		//管理员验证
		while (ifs >> fpassword && ifs >> fname) {
			//测试输出
			//cout << fname << endl;
			//cout << fpassword << endl;
			if (fname == name && password == fpassword) {
				cout << "管理员登陆成功！" << endl;
				ifs.close();
				system("pause");
				system("cls");
				//管理员接口实现
				Person = new Admin(name, password);
				AdminInter(Person);
				return;
			}
		}
	}
	cout << "验证失败，登录不成功！" << endl;
	system("pause");
	system("cls");
}

