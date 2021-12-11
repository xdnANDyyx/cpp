#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "feast.h"
#include "globalFile.h"
#include "orderFile.h"
using namespace std;
#include "Identity.h"

//学生类
class Customer :public Identity
{
public:
	//默认构造
	Customer();

	//有参构造(会员号、姓名、密码)
	Customer(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//会员号
	int m_Id;

	//套餐容器
	vector<Feast> vFe;
};
