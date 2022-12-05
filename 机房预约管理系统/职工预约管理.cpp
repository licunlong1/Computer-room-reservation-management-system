#include"职工预约管理.h"

int main() {

	int select;
	while (1) {
		mainMenu();
		cin >> select;
		switch (select) {
		case 1://学生身份
			LoginCheck(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginCheck(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginCheck(ADMIN_FILE, 3);
			break;
		case 0://退出功能
			cout << "欢迎下次使用，谢谢！" << endl;
			exit(1);
			break;
		default:
			cout << "您的选择有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}