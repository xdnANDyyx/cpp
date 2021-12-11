#include "manager.h"

//默认构造
Manager::Manager()
{
}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化容器
	this->initVector();
	//获取套餐信息
	ifstream ifs;

	ifs.open(FEAST_FILE, ios::in);

	Feast c;
	while (ifs >> c.m_Id && ifs >> c.type)
	{
		vCom.push_back(c);
	}
	//cout << "当前套餐数量为： " << vCom.size() << endl;

	ifs.close();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看套餐            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预订            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号  
void Manager::addPerson()
{
		cout << "请输入添加账号的类型" << endl;
		cout << "1、添加顾客" << endl;
		cout << "2、添加经理" << endl;

		string fileName;
		string tip;
		ofstream ofs;
		string errorTip; //重复错误提示

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			fileName = CUSTOMER_FILE;
			tip = "请输入会员号： ";
			errorTip = "会员号无效，请重新输入";
		}
		else
		{
			fileName = DIRECTOR_FILE;
			tip = "请输入职工编号：";
			errorTip = "职工号无效，请重新输入";
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

			if (ret) //有重复
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}
		}

		
		
		//cin >> id;


		cout << "请输入姓名： " << endl;
		cin >> name;

		cout << "请输入密码： " << endl;
		cin >> pwd;

		ofs << id << " " << name << " " << pwd << " " << endl;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");

		ofs.close();
		//初始化容器
		this->initVector();
	
}

void printStudent(Customer & s)
{
	cout << "会员号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printDirector(Director & t)
{
	cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
		cout << "请选择查看内容：" << endl;
		cout << "1、查看所有会员" << endl;
		cout << "2、查看所有经理" << endl;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "所有会员信息如下： " << endl;
			for_each(vCus.begin(), vCus.end(), printStudent);
		}
		else
		{
			cout << "所有经理信息如下： " << endl;
			for_each(vTea.begin(), vTea.end(), printDirector);
		}
		system("pause");
		system("cls");
	
}

//查看机房信息
void Manager::showFeast()
{
	
		cout << "餐厅套餐信息如下： " << endl;
		for (vector<Feast>::iterator it = vCom.begin(); it != vCom.end(); it++)
		{
			cout << "套餐编号： " << it->m_Id << " 套餐类别： " << it->type << endl;
		}
		system("pause");
		system("cls");
	
}

//清空预约记录
void Manager::cleanFile()
{
	
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();

		cout << "清空成功！" << endl;
		system("pause");
		system("cls");
	
}
//去重操作
void Manager::initVector()
{
	//读取顾客文件中信息
	ifstream ifs;
	ifs.open(CUSTOMER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vCus.clear();
	vTea.clear();

	Customer s;
	while (ifs >> s.m_Id && ifs >> s.m_Name &&  ifs >> s.m_Pwd)
	{
		vCus.push_back(s);
	}
	//cout << "当前顾客数量为： " << vStu.size() << endl;
	ifs.close(); //顾客初始化

	//读取经理文件信息
	ifs.open(DIRECTOR_FILE, ios::in);

	Director t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name &&  ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << "当前经理数量为： " << vTea.size() << endl;

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