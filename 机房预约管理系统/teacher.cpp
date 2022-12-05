#include"teacher.h"


Teacher::Teacher() {

}

Teacher::Teacher(int empid, string name, string password) {
	this->m_Empty = empid;
	this->m_Name = name;
	this->m_Password = password;
}

void Teacher::OperMenu() {//��ʦ�˵�

	cout << "��ӭ��ʦ��" << this->m_Name << "  ��¼��" << endl;
	cout << "\t\t --------------------------------------- \n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            1.�鿴������ԤԼ            |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            2.�� �� Ԥ Լ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|            0.ע �� �� ¼               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t ---------------------------------------\n";
}

void Teacher::ShowAllOrder() {//��ʦ��ʾ������ԤԼ
	//��Ϊ��ѧ���е���Ϣһ��  ֱ�ӵ���ѧ����
	Student student;
	student.ShouAllOrder();
}

void Teacher::ValidOrder() {//��ʦ���ԤԼ����
	cout << "--------------��Ҫ��˵ļ�¼����----------------" << endl;

	OrderFile of;
	of.UpdateMemory();

	vector<int> v;
	int index = 1;
	int count = 0;
	for (int i = 0; i < of.Order_Size; i++) {
		if (of.mp_Order[i]["״̬"] == "1") {
			cout << index++ << "��";
			cout << "���ڣ�" << of.mp_Order[i]["����"];
			cout << " ʱ�䣺" << of.mp_Order[i]["ʱ��"];
			cout << " ID��ְ����ţ�" << of.mp_Order[i]["ID��ְ�����"];
			cout << " ������" << of.mp_Order[i]["����"];
			cout << " ԤԼ������" << of.mp_Order[i]["ԤԼ����"];
			cout << "״̬�������" << endl;
			v.push_back(i);
			count++;
		}
	}
	if (count == 0) {
		cout << "��ǰ����˼�¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����Ҫ����Ǹ���¼��" << endl;
	cout << "��ѡ��(0�˳�)��";
	int select;
	
	while (1) {
		cin >> select;
		if (select >= 0 && select <= (int)v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "1.ͨ�����" << endl;
				cout << "2.��ͨ�����" << endl;
				int ret;
				cout << "��ѡ��";
				cin >> ret;
				if (ret == 1) {
					of.mp_Order[v[select - 1]]["״̬"] = "2";
				}
				else if (ret == 2) {
					of.mp_Order[v[select - 1]]["״̬"] = "-1";
				}
				cout << "�����ɣ�" << endl;
				of.UpdateOrderFile();
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