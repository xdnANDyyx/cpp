#include "customer.h"

//Ĭ�Ϲ���
Customer::Customer()
{
}

//�вι���(��Ա�š�����������)
Customer::Customer(int id, string name, string pwd)
{
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ȡ�ײ���Ϣ
	ifstream ifs;
	ifs.open(FEAST_FILE, ios::in);

	Feast c;
	while (ifs >> c.m_Id && ifs >> c.type)
	{
		vFe.push_back(c);
	}

	ifs.close();
}

//�˵�����
void Customer::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.ѡ��Ԥ��              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�Ԥ��          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����Ԥ��          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��Ԥ��              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void Customer::applyOrder()
{
	cout << "��������ʱ��Ϊ���������գ�" << endl;
	cout << "����������Ԥ����ʱ�䣺" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	cout << "6������" << endl;
	cout << "7������" << endl;
	int date = 0;
	int interval = 0;
	int feast = 0;

	while (true)
	{
		cin >> date;
		if (date >= 3 && date <= 7)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;//���
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ���ײ����" << endl;
	cout << "1���ײͣ�" << vFe[0].type << endl;
	cout << "2���ײͣ�" << vFe[1].type << endl;
	cout << "3���ײͣ�" << vFe[2].type << endl;
	cout << "4���ײͣ�" << vFe[3].type << endl;
	cout << "5���ײͣ�" << vFe[4].type << endl;
	cout << "6���ײͣ�" << vFe[5].type << endl;

	while (true)
	{
		cin >> feast;
		if (feast >= 1 && feast <= 6)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "Ԥ���ɹ����ύ��..." << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "cId:" << this->m_Id << " ";
	ofs << "cName:" << this->m_Name << " ";
	ofs << "fId:" << feast << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Customer::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��Ԥ����¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["cId"].c_str()) == this->m_Id)
		{
			cout << "Ԥ�����ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " �ײͣ�" << of.m_orderData[i]["fId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "Ԥ���ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ʱ��γ�ͻ����������Ԥ��";
			}
			else
			{
				status += "Ԥ����ȡ��";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Customer::showAllOrder()
{
	
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "��Ԥ����¼" << endl;
			system("pause");
			system("cls");
			return;
		}

		for (int i = 0; i < of.m_Size; i++)
		{
			cout << i + 1 << "�� ";

			cout << "Ԥ�����ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ��Ա�ţ�" << of.m_orderData[i]["cId"];
			cout << " ������" << of.m_orderData[i]["cName"];
			cout << " �ײͺţ�" << of.m_orderData[i]["fId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "Ԥ���ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ʱ��γ�ͻ����������Ԥ��";
			}
			else
			{
				status += "Ԥ����ȡ��";
			}
			cout << status << endl;
		}

		system("pause");
		system("cls");
	
}

//ȡ��ԤԼ
void Customer::cancelOrder()
{
	
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "��Ԥ����¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "����л�Ԥ���ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

		vector<int>v;
		int index = 1;
		for (int i = 0; i < of.m_Size; i++)
		{
			if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
			{
				if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
				{
					v.push_back(i);
					cout << index++ << "�� ";
					cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
					cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
					cout << " �ײͺţ�" << of.m_orderData[i]["roomId"];
					string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
					if (of.m_orderData[i]["status"] == "1")
					{
						status += "�����";
					}
					else if (of.m_orderData[i]["status"] == "2")
					{
						status += "Ԥ���ɹ�";
					}
					cout << status << endl;

				}
			}
		}

		cout << "������ȡ���ļ�¼,0������" << endl;
		int select = 0;
		while (true)
		{
			cin >> select;
			if (select >= 0 && select <= v.size())
			{
				if (select == 0)
				{
					break;
				}
				else
				{
					//	cout << "��¼����λ�ã� " << v[select - 1] << endl;
					of.m_orderData[v[select - 1]]["status"] = "0";
					of.updateOrder();
					cout << "��ȡ��Ԥ��" << endl;
					break;
				}

			}
			cout << "������������������" << endl;
		}

		system("pause");
		system("cls");
	

}
