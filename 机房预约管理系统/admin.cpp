#include"admin.h"
#include"filename.h"


Admin::Admin() {

}

Admin::Admin(string name, string password) {
	this->m_Name = name;
	this->m_Password = password;

	//��ʼ���ڴ�
	InitMember();
	this->InitComputer();
}

void Admin::OperMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "  ��¼��" << endl;
	cout << "\t\t --------------------------------------- \n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            1.�� �� �� ��               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            2.�� �� �� ��               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            3.�� �� �� ��               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            4.�� �� Ԥ Լ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            0.ע �� �� ¼               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t ---------------------------------------\n";
}

void Admin::AddPerson() {//�����Ա��Ϣ�˺�����
	cout << "��ѡ������Ҫ��ӵ��˻�" << endl;
	cout << "1.ѧ���˻�" << endl;
	cout << "2.��ʦ�˻�" << endl;
	string filename;
	string tip;
	string errortip;

	int select;
	cout << "���������ѡ��";
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "������ѧ��id�ţ�";
		errortip = "��ǰѧ��id�Ѿ����ڣ��������";
	}
	else if (select == 2) {
		filename = TEACHER_FILE;
		tip = "�������ʦ��ְ���ţ�";
		errortip = "��ǰ��ʦְ������Ѿ����ڣ��������";
	}
	else {
		cout << "ѡ���������ѡ��" << endl;
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
	//	cout<<"�������û���"
	//}
	//	break;
	//case 2:
	//	break;
	//default:
	//	cout << "��������" << endl;
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
	cout << "�������û�����";
	cin >> fname;
	cout << "���������룺";
	cin >> fpassword;
	ofs << fid << " " << fname << " " << fpassword << endl;
	cout << "��ӳɹ�" << endl;
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

//��ӡѧ����Ϣ
void PrintStudent(const Student& s) {
	cout << "ѧ��ID��" << s.m_Id << "       �˻���" << s.m_Name << "       ���룺" << s.m_Password << endl;
}

//��ӡ��ʦ��Ϣ
void PrintTeacher(const Teacher& t) {

	cout << "��ʦְ����ţ�" << t.m_Empty << "       �˻���" << t.m_Name << "       ���룺" << t.m_Password << endl;
}


void Admin::ShowPerson() {//��ʾ��Ա��Ϣ
	
	cout << "1.�鿴ѧ���˻�" << endl;
	cout << "2.�鿴��ʦ�˻�" << endl;
	cout << "���������ѡ��";
	int select;
	cin >> select;
	if (select == 1) {
		for_each(VStudent.begin(), VStudent.end(), PrintStudent);
	}
	else if (select == 2) {
		for_each(VTeacher.begin(), VTeacher.end(), PrintTeacher);
	}
	else {
		cout << "ѡ�����" << endl;
	}
	system("pause");
	system("cls");
}


void Admin::ShowComputer() {//��ʾ������Ϣ
	
	for (auto& mp : mp_Computer) {
		cout << "������ţ�" << mp.first << "       ����������" << mp.second << endl;
	}
	system("pause");
	system("cls");
}

void Admin::ClearOrder() {//���ԤԼ��Ϣ
	cout << "ȷ�����ô" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();

		cout << "���ԤԼ��Ϣ��ɣ�" << endl;
	}
	else if (select == 2) {
		cout << "ȡ����գ�" << endl;
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
	//cout << "��ǰ��ʦ��" << this->VTeacher.size() << "��" << endl;
	ifs.close();
	ifs.open(STUDENT_FILE, ios::in);
	while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
		this->VStudent.push_back(Student(fid, fname, fpassword));
	}
	//cout << "��ǰѧ����" << this->VStudent.size() << "��" << endl;
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