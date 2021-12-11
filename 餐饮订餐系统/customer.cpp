#include "customer.h"

//默认构造
Customer::Customer()
{
}

//有参构造(会员号、姓名、密码)
Customer::Customer(int id, string name, string pwd)
{
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	//获取套餐信息
	ifstream ifs;
	ifs.open(FEAST_FILE, ios::in);

	Feast c;
	while (ifs >> c.m_Id && ifs >> c.type)
	{
		vFe.push_back(c);
	}

	ifs.close();
}

//菜单界面
void Customer::operMenu()
{
	cout << "欢迎尊贵会员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.选择预订              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预订          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预订          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预订              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//申请预约
void Customer::applyOrder()
{
	cout << "餐厅开放时间为周三至周日！" << endl;
	cout << "请输入申请预订的时间：" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	cout << "6、周六" << endl;
	cout << "7、周日" << endl;
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
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;//间隔
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择套餐类别：" << endl;
	cout << "1号套餐：" << vFe[0].type << endl;
	cout << "2号套餐：" << vFe[1].type << endl;
	cout << "3号套餐：" << vFe[2].type << endl;
	cout << "4号套餐：" << vFe[3].type << endl;
	cout << "5号套餐：" << vFe[4].type << endl;
	cout << "6号套餐：" << vFe[5].type << endl;

	while (true)
	{
		cin >> feast;
		if (feast >= 1 && feast <= 6)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预订成功！提交中..." << endl;

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

//查看我的预约
void Customer::showMyOrder()
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
		if (atoi(of.m_orderData[i]["cId"].c_str()) == this->m_Id)
		{
			cout << "预订日期： 周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
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
	}

	system("pause");
	system("cls");
}

//查看所有预约
void Customer::showAllOrder()
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
			cout << " 套餐号：" << of.m_orderData[i]["fId"];
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

//取消预约
void Customer::cancelOrder()
{
	
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "无预订记录" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "审查中或预订成功的记录可以取消，请输入取消的记录" << endl;

		vector<int>v;
		int index = 1;
		for (int i = 0; i < of.m_Size; i++)
		{
			if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
			{
				if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
				{
					v.push_back(i);
					cout << index++ << "、 ";
					cout << "预约日期： 周" << of.m_orderData[i]["date"];
					cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
					cout << " 套餐号：" << of.m_orderData[i]["roomId"];
					string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
					if (of.m_orderData[i]["status"] == "1")
					{
						status += "审查中";
					}
					else if (of.m_orderData[i]["status"] == "2")
					{
						status += "预订成功";
					}
					cout << status << endl;

				}
			}
		}

		cout << "请输入取消的记录,0代表返回" << endl;
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
					//	cout << "记录所在位置： " << v[select - 1] << endl;
					of.m_orderData[v[select - 1]]["status"] = "0";
					of.updateOrder();
					cout << "已取消预订" << endl;
					break;
				}

			}
			cout << "输入有误，请重新输入" << endl;
		}

		system("pause");
		system("cls");
	

}
