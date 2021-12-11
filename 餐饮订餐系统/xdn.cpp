#include <iostream>
#include <string.h>
#include "globalFile.h"
#include "identity.h"
#include "customer.h"
#include "director.h"
#include "manager.h"
#include <fstream>
#include <string>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
//����˵�
void DirectorMenu(Identity * &director)
{
	while (true)
	{
		//����˵�
		director->operMenu();

		Director* tea = (Director*)director;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		
		else
		{
			delete director;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//�˿Ͳ˵�
void studentMenu(Identity * &customer)
{
	while (true)
	{
		//�˿Ͳ˵�
		customer->operMenu();

		Customer* stu = (Customer*)customer;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete customer;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//����Ա�˵�
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴�ײ�" << endl;
			man->showFeast();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼����
void LoginIn(string fileName, int type)
{

	Identity * person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//�˿͵�¼
	{
		cout << "��������Ļ�Ա��" << endl;
		cin >> id;
	}
	else if (type == 2) //�����¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;


	if (type == 1)
	{
		
		//��Ա��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Customer(id, name, pwd);
				//�����Ա�Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		
		//�����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "������֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Director(id, name, pwd);
				//���뾭���Ӳ˵�
				DirectorMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}
void inFo(){
	mciSendString(TEXT("open ./welcome.mp3 alias A"), 0, 0, 0);
	mciSendString(L"play A", 0, 0, 0);
	initgraph(1000, 600, 1);
	cleardevice();
	settextcolor(RED);
	settextstyle(30, 0, L"����");
	outtextxy(300, 100, L"ʹ �� ˵ ��");
	outtextxy(300, 150, L"����ԱĬ���˻���admin 123");
	outtextxy(300, 200, L"������Ҫ��ʼ���˿���Ϣ");
	outtextxy(300, 250, L"�����ɶ���");
	outtextxy(300, 300, L"������Ԥ��");
	outtextxy(300, 350, L"Ԥ����ɡ�");


}
int main() {
	
	
	inFo();
	int choice = 0;
	while (true) 
	{
		cout << "======================  ��ӭʹ�ò������͹���ϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.��̨����           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> choice;
		switch (choice) {
		 case 1://�˿�
			 LoginIn(CUSTOMER_FILE ,1);
			break;
		 case 2://����
			 LoginIn(DIRECTOR_FILE, 2);
			break;
		 case 3://����
			 LoginIn(ADMIN_FILE, 3);
			break;
		 case 4://�˳�
			 cout << "��ӭ�´�ʹ��" << endl;
			 mciSendString(TEXT("open ./bye.mp3 alias B"), 0, 0, 0);
			 mciSendString(L"play B", 0, 0, 0);
			 system("pause");
			 return 0;
			break;
		 default:
			cout << "�����������������롣" << endl;
			system("pause");
			system("cls");
			break;

		}
	}

	
	system("pause");
	return 0;
}
