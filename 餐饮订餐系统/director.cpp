#include"director.h"
#include<stdio.h>
#include<string.h>

//默认构造
Director::Director()
{
}

//有参构造 (职工编号，姓名，密码)
Director::Director(int empId, string name, string pwd)
{
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Director::operMenu()
{
	cout << "欢迎经理：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预订          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审查预订              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Director::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预订记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、 ";

		cout << "预订日期： 周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 会员号：" << of.m_orderData[i]["cId"];
		cout << " 姓名：" << of.m_orderData[i]["cName"];
		cout << " 套餐：" << of.m_orderData[i]["fId"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审查中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预订成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "时间段冲突，您可重新预订";
		}
		else
		{
			status += "预订已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//审核预约
void Director::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预订记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审查的预订记录如下：" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、 ";
			cout << "预订日期： 周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 套餐：" << of.m_orderData[i]["roomId"];
			string status = " 状态： ";  // 0取消的预约   1 审核中   2 已预约  -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审查中";
			}
			cout << status << endl;
		}
	}
	cout << "请输入查询的预订记录,0代表返回" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "请输入审查结果" << endl;
				cout << "1、通知后厨安排" << endl;
				cout << "2、时间段冲突" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "审查完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}


	system("pause");
	system("cls");
}
