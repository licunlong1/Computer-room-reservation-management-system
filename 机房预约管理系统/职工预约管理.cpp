#include"ְ��ԤԼ����.h"

int main() {

	int select;
	while (1) {
		mainMenu();
		cin >> select;
		switch (select) {
		case 1://ѧ�����
			LoginCheck(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginCheck(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginCheck(ADMIN_FILE, 3);
			break;
		case 0://�˳�����
			cout << "��ӭ�´�ʹ�ã�лл��" << endl;
			exit(1);
			break;
		default:
			cout << "����ѡ������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}