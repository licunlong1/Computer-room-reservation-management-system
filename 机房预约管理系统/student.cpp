#include"student.h"

Student::Student() {

}

Student::Student(int id, string name, string password) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = password;
}

void Student::OperMenu() {//ѧ���˵�
	cout << "��ӭѧ����" << this->m_Name << "  ��¼��" << endl;
	cout << "\t\t --------------------------------------- \n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            1.�� �� Ԥ Լ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            2.�鿴����ԤԼ              |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            3.�鿴������ԤԼ            |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            4.ȡ �� Ԥ Լ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            5.�� �� �� ��               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            0.ע �� �� ¼               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t ---------------------------------------\n";
}


void Student::ApplyOrder() {//����ԤԼ
	cout << "��ԤԼʱ���Ϊ��һ�����壬�����첻��ԤԼ����\n"
		<< "1.����һ\n" << "2.���ڶ�\n" << "3.������\n" << "4.������\n" << "5.������\n"<<"0.ȡ��ѡ��\n";
	cout << "����Ҫ�ܼ�ԤԼ�أ���ѡ��";
	int date;
	cin >> date;
	if (date > 0 && date < 6) {
		cout << "1.����\t\t2.����" << endl;
		cout << "��ҪԤԼʲôʱ���أ���ѡ��";
		int time;
		cin >> time;
		//�ѻ��������ݼ��ص��ڴ浱��
		this->InitComputer();
		for (auto& mp : mp_Computer) {
			cout << "������ţ�" << mp.first << "       ����������" << mp.second << endl;
		}
		cout << "��ҪԤԼ�Ǹ������أ���ѡ��";
		int computer;
		cin >> computer;
		cout << "ԤԼ�ɹ�����������У�" << endl;
		//��ʾ״̬���ַ���
		string status;
		
		ofstream ofs(ORDER_FILE, ios::app);
		ofs << "���� ����" << date << " " << "ʱ�� " << time << " " << "ID��ְ����� " 
			<< this->m_Id << " "<< "���� " << this->m_Name << " " << "ԤԼ���� " 
			<< computer << "�Ż���" << " " << "״̬ " << "1" << endl;
		ofs.close();
		system("pause");
		system("cls");
		return;
	}
	cout << "ȡ��ѡ��" << endl;
	system("pause");
	system("cls");
}

void Student::ShowMyOrder() {//��ʾ�Լ���ԤԼ
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
		if (this->m_Id == atoi(of.mp_Order[i]["ID��ְ�����"].c_str())) {
			cout << "���ڣ�" << of.mp_Order[i]["����"] << " ";
			cout << "ʱ�䣺" << (of.mp_Order[i]["ʱ��"] == "1" ? "����" : "����");
			cout << " ID��ְ����ţ�" << of.mp_Order[i]["ID��ְ�����"];
			cout << " ������" << of.mp_Order[i]["����"];
			cout << " ԤԼ������" << of.mp_Order[i]["ԤԼ����"];
			string status = " ���״̬��";
			//0ȡ��ԤԼ 1����� 2ԤԼ�ɹ� -1ԤԼʧ��
			if (of.mp_Order[i]["״̬"] == "1") {
				status += "�����";
			}
			else if (of.mp_Order[i]["״̬"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.mp_Order[i]["״̬"] == "-1") {
				status += "ԤԼʧ��";
			}
			else if (of.mp_Order[i]["״̬"] == "0") {
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}


void Student::ShouAllOrder() {//��ʾ�����˵�ԤԼ

	//����ֱ�Ӷ�ȡ�ļ��е����� ��Ϊ�ļ��е����ݸ��û��뿴�������ݲ�һ�� ��Ҫ��������
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
		cout << "��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.Order_Size; i++) {
		cout << i + 1 << "��";
		cout << "���ڣ�" << of.mp_Order[i]["����"] << " ";
		cout << "ʱ�䣺" << (of.mp_Order[i]["ʱ��"] == "1" ? "����" : "����");
		cout << " ID��ְ����ţ�" << of.mp_Order[i]["ID��ְ�����"];
		cout << " ������" << of.mp_Order[i]["����"];
		cout << " ԤԼ������" << of.mp_Order[i]["ԤԼ����"];
		string status = " ���״̬��";
		//0ȡ��ԤԼ 1����� 2ԤԼ�ɹ� -1ԤԼʧ��
		if (of.mp_Order[i]["״̬"] == "1") {
			status += "�����";
		}
		else if (of.mp_Order[i]["״̬"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.mp_Order[i]["״̬"] == "-1") {
			status += "ԤԼʧ��";
		}
		else if (of.mp_Order[i]["״̬"] == "0") {
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;
	}

	//�������
	//for (auto& mp : of.mp_Order) {
	//	cout << mp.first << "��" ;
	//	for (auto& mp1 : mp.second) {
	//		cout << mp1.first << " ";
	//		if (mp1.second == "1") {
	//			cout << "����";
	//		}
	//		else if (mp1.second == "2") {
	//			cout << "����";
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

void Student::CancelOrder() {//ȡ��ԤԼ
	cout << "------------ֻ������к�ԤԼ�ɹ��Ŀ���ȡ��ԤԼ(ֻ��ȡ���Լ���ԤԼ)--------------" << endl;
	OrderFile of;
	of.UpdateMemory();

	//���û���ʾ�ļ�¼ ��
	vector<int> v;
	int index = 1;
	int count = 0;

	for (int i = 0; i < of.Order_Size; i++) {
		if (this->m_Id == atoi(of.mp_Order[i]["ID��ְ�����"].c_str())) {
			if (of.mp_Order[i]["״̬"] == "1" || of.mp_Order[i]["״̬"] == "2") {
				cout << index++ << "��";
				cout << "���ڣ�" << of.mp_Order[i]["����"];
				cout << " ʱ�䣺" << of.mp_Order[i]["ʱ��"];
				cout << " ID��ְ����ţ�" << of.mp_Order[i]["ID��ְ�����"];
				cout << " ������" << of.mp_Order[i]["����"];
				cout << " ԤԼ������" << of.mp_Order[i]["ԤԼ����"];
				string status = " ״̬��";
				if (of.mp_Order[i]["״̬"] == "1") {
					status += "�����";
				}
				else if (of.mp_Order[i]["״̬"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
				v.push_back(i);
				count++;
			}
		}
	}
	if (count == 0) {
		cout << "��ǰ����Ҫȡ��ԤԼ�ļ�¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "���������ѡ��(0�˳�ԤԼ)��";
	int select;
	
	while (1) {
		cin >> select;
		if (select >= 0 && select <= (int)v.size()) {
			if (select == 0)
				break;
			else {
				of.mp_Order[v[select - 1]]["״̬"] = "0";
				of.UpdateOrderFile();
				cout << "���Ѿ�ȡ��ԤԼ��" << endl;
				v.clear();
				break;
			}
		}
		else {
			cout << "ѡ�����������ѡ��" << endl;
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
	//�������
	//for (auto& mp : this->mp_Student) {
	//	cout << "ID:" << mp.first;
	//	for (auto& mp1 : mp.second) {
	//		cout << "������" << mp1.first << " ���룺" << mp1.second << endl;
	//	}
	//}
}

void Student::ModifyPassword() {

	this->InitStudent();
	string password;
	cout << "���������ԭ���룺";
	cin >> password;
	if (password == this->mp_Student[this->m_Id][this->m_Name]) {
	again:
		cout << "��������������룺";
		string m_password;
		cin >> m_password;
		string m_password1;
		cout << "���ٴ�������������룺";
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

			cout << "�޸ĳɹ���" << endl;
		}
		else {
			cout << "�������벻һ�������������룡" << endl;
			goto again;
		}
	}
	else {
		cout << "ԭ�������" << endl;
	}
	system("pause");
	system("cls");
}

void Student::InitStudentFile() {

}