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
//经理菜单
void DirectorMenu(Identity * &director)
{
	while (true)
	{
		//经理菜单
		director->operMenu();

		Director* tea = (Director*)director;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		
		else
		{
			delete director;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//顾客菜单
void studentMenu(Identity * &customer)
{
	while (true)
	{
		//顾客菜单
		customer->operMenu();

		Customer* stu = (Customer*)customer;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete customer;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//管理员菜单
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看套餐" << endl;
			man->showFeast();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能
void LoginIn(string fileName, int type)
{

	Identity * person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//顾客登录
	{
		cout << "请输入你的会员号" << endl;
		cin >> id;
	}
	else if (type == 2) //经理登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;


	if (type == 1)
	{
		
		//会员登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "会员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Customer(id, name, pwd);
				//进入会员子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		
		//经理登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "经理验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Director(id, name, pwd);
				//进入经理子菜单
				DirectorMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

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
	settextstyle(30, 0, L"楷体");
	outtextxy(300, 100, L"使 用 说 明");
	outtextxy(300, 150, L"管理员默认账户：admin 123");
	outtextxy(300, 200, L"首先需要初始化顾客信息");
	outtextxy(300, 250, L"其次完成订单");
	outtextxy(300, 300, L"经理处理预订");
	outtextxy(300, 350, L"预订完成。");


}
int main() {
	
	
	inFo();
	int choice = 0;
	while (true) 
	{
		cout << "======================  欢迎使用餐饮订餐管理系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.顾    客           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.经    理           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.后台管理           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> choice;
		switch (choice) {
		 case 1://顾客
			 LoginIn(CUSTOMER_FILE ,1);
			break;
		 case 2://经理
			 LoginIn(DIRECTOR_FILE, 2);
			break;
		 case 3://管理
			 LoginIn(ADMIN_FILE, 3);
			break;
		 case 4://退出
			 cout << "欢迎下次使用" << endl;
			 mciSendString(TEXT("open ./bye.mp3 alias B"), 0, 0, 0);
			 mciSendString(L"play B", 0, 0, 0);
			 system("pause");
			 return 0;
			break;
		 default:
			cout << "输入有误，请重新输入。" << endl;
			system("pause");
			system("cls");
			break;

		}
	}

	
	system("pause");
	return 0;
}
