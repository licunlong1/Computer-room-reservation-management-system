
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
	cout << "======================��ӭ����ѧԺ����ԤԼ����ϵͳ========================" << endl;
	cout << endl << "��ѡ��������" << endl;
	cout << "\t\t ---------------------------------------\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              1.ѧ������               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              2.��    ʦ               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              3.�� �� Ա               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t|              0.��    ��               |\n";
	cout << "\t\t|                                       |\n";
	cout << "\t\t ---------------------------------------\n";
	cout << "���������ѡ��";
}

//����Ա�ӿڵ�ʵ��
void AdminInter(Identity* &Person) {

	while (1) {
	again:
		Person->OperMenu();
		Admin* admin = (Admin*)Person;
		cout << "���������ѡ��";
		int select;
		cin >> select;
		switch (select) {
		case 1://����˻�
			//cout << "����˻�" << endl;
			admin->AddPerson();
			break;
		case 2://�鿴�����˻�
			admin->ShowPerson();
			break;
		case 3://�鿴����
			admin->ShowComputer();
			break;
		case 4://��ջ���ԤԼ
			admin->ClearOrder();
			break;
		case 0:
			cout << "ע���ɹ���" << endl;
			system("cls");
			return;
			break;
		default:
			cout << "ѡ�����������ѡ��" << endl;
			system("pause");
			system("cls");
			goto again;
			break;
		}
	}
}

//ѧ���ӿڵ�ʵ��
void StudentInter(Identity* &Person) {
	while (1) {
	again:
		Person->OperMenu();
		Student* student = (Student*)Person;
		int select;
		cout << "���������ѡ��";
		cin >> select;
		switch (select) {

		case 1://����ԤԼ
			student->ApplyOrder();
			break;
		case 2://��ʾ�Լ���ԤԼ
			student->ShowMyOrder();
			break;
		case 3://��ʾ�����˵�ԤԼ
			student->ShouAllOrder();
			break;
		case 4://ȡ��ԤԼ
			student->CancelOrder();
			break;
		case 5://�޸�����
			student->ModifyPassword();
			break;
		case 0:
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "ѡ�����������ѡ��" << endl;
			system("pause");
			system("cls");
			goto again;
			break;
		}
	}
}


//��ʦ�ӿڵ�ʵ��
void TeacherInter(Identity* &Person) {
	while (1) {
	again:
		Person->OperMenu();

		Teacher* teacher = (Teacher*)Person;
		cout << "���������ѡ��";
		int select;
		cin >> select;
		switch (select) {
		case 1://�鿴�����˵�ԤԼ
			teacher->ShowAllOrder();
			break;
		case 2://���ԤԼ
			teacher->ValidOrder();
			break;
		case 0://ע����¼
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "ѡ�����������ѡ��" << endl;
			system("pause");
			system("cls");
			goto again;
			break;
		}
	}

}

void LoginCheck(string filename, int select) {

	Identity* Person = NULL;
	ifstream ifs(filename, ios::in);//���ļ�
	if (!ifs.is_open()) {
		cout << "file no find" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string password;
	if (select == 1) {
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (select == 2) {
		cout << "����������ְ����ţ�";
		cin >> id;
	}
	cout << "�������û�����";
	cin >> name;
	cout << "���������룺";
	cin >> password;

	//��֤��Ҫ��ȡ�ļ��е�����  �ñ�����������
	string fname;
	string fpassword;
	int fid;

	if (select == 1) {
		//��֤ѧ����¼
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//���Դ���
			//cout << "ѧ����֤" << endl;
			//cout << fid << endl;
			//cout << fname << endl;
			//cout << fpassword << endl;
			if (fid == id && fname == name && fpassword == password) {
				cout << "ѧ����¼�ɹ���" << endl;
				ifs.close();
				system("pause");
				system("cls");
				Person = new Student(id, name, password);
				//ѧ���ӿ�ʵ��
				StudentInter(Person);
				return;
			}
		}
	}
	else if (select == 2) {
		//��֤��ʦ��¼
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//���Դ���
			//cout << "ѧ����֤" << endl;
			//cout << fid << endl;
			//cout << fname << endl;
			//cout << fpassword << endl;
			if (fid == id && fname == name && fpassword == password) {
				cout << "��ʦ��½�ɹ���" << endl;
				ifs.close();
				system("pause");
				system("cls");
				//��ʦ�ӿ�ʵ��
				Person = new Teacher(id, name, password);
				TeacherInter(Person);
				return;
			}
		}
	}
	else if (select == 3) {
		//����Ա��֤
		while (ifs >> fpassword && ifs >> fname) {
			//�������
			//cout << fname << endl;
			//cout << fpassword << endl;
			if (fname == name && password == fpassword) {
				cout << "����Ա��½�ɹ���" << endl;
				ifs.close();
				system("pause");
				system("cls");
				//����Ա�ӿ�ʵ��
				Person = new Admin(name, password);
				AdminInter(Person);
				return;
			}
		}
	}
	cout << "��֤ʧ�ܣ���¼���ɹ���" << endl;
	system("pause");
	system("cls");
}

