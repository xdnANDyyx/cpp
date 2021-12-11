#include "manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ������
	this->initVector();
	//��ȡ�ײ���Ϣ
	ifstream ifs;

	ifs.open(FEAST_FILE, ios::in);

	Feast c;
	while (ifs >> c.m_Id && ifs >> c.type)
	{
		vCom.push_back(c);
	}
	//cout << "��ǰ�ײ�����Ϊ�� " << vCom.size() << endl;

	ifs.close();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴�ײ�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���Ԥ��            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�  
void Manager::addPerson()
{
		cout << "����������˺ŵ�����" << endl;
		cout << "1����ӹ˿�" << endl;
		cout << "2����Ӿ���" << endl;

		string fileName;
		string tip;
		ofstream ofs;
		string errorTip; //�ظ�������ʾ

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			fileName = CUSTOMER_FILE;
			tip = "�������Ա�ţ� ";
			errorTip = "��Ա����Ч������������";
		}
		else
		{
			fileName = DIRECTOR_FILE;
			tip = "������ְ����ţ�";
			errorTip = "ְ������Ч������������";
		}

		ofs.open(fileName, ios::out | ios::app);
		int id;
		string name;
		string pwd;
		cout << tip << endl;
		while (true)
		{
			cin >> id;

			bool ret = this->checkRepeat(id, select);

			if (ret) //���ظ�
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}
		}

		
		
		//cin >> id;


		cout << "������������ " << endl;
		cin >> name;

		cout << "���������룺 " << endl;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");

		ofs.close();
		//��ʼ������
		this->initVector();
	
}

void printStudent(Customer & s)
{
	cout << "��Ա�ţ� " << s.m_Id << " ������ " << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printDirector(Director & t)
{
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
		cout << "��ѡ��鿴���ݣ�" << endl;
		cout << "1���鿴���л�Ա" << endl;
		cout << "2���鿴���о���" << endl;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "���л�Ա��Ϣ���£� " << endl;
			for_each(vCus.begin(), vCus.end(), printStudent);
		}
		else
		{
			cout << "���о�����Ϣ���£� " << endl;
			for_each(vTea.begin(), vTea.end(), printDirector);
		}
		system("pause");
		system("cls");
	
}

//�鿴������Ϣ
void Manager::showFeast()
{
	
		cout << "�����ײ���Ϣ���£� " << endl;
		for (vector<Feast>::iterator it = vCom.begin(); it != vCom.end(); it++)
		{
			cout << "�ײͱ�ţ� " << it->m_Id << " �ײ���� " << it->type << endl;
		}
		system("pause");
		system("cls");
	
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();

		cout << "��ճɹ���" << endl;
		system("pause");
		system("cls");
	
}
//ȥ�ز���
void Manager::initVector()
{
	//��ȡ�˿��ļ�����Ϣ
	ifstream ifs;
	ifs.open(CUSTOMER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vCus.clear();
	vTea.clear();

	Customer s;
	while (ifs >> s.m_Id && ifs >> s.m_Name &&  ifs >> s.m_Pwd)
	{
		vCus.push_back(s);
	}
	//cout << "��ǰ�˿�����Ϊ�� " << vStu.size() << endl;
	ifs.close(); //�˿ͳ�ʼ��

	//��ȡ�����ļ���Ϣ
	ifs.open(DIRECTOR_FILE, ios::in);

	Director t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ��������Ϊ�� " << vTea.size() << endl;

	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Customer>::iterator it = vCus.begin(); it != vCus.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else 
	{
		for (vector<Director>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}