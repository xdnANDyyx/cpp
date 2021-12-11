#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "globalFile.h"
#include "director.h"
#include "customer.h"
#include "feast.h"
using namespace std;
#include "Identity.h"

class Manager :public Identity
{
public:

	//默认构造
	Manager();

	//有参构造  管理员姓名，密码
	Manager(string name, string pwd);
	//套餐容器
	vector<Feast> vCom;

	//选择菜单
	virtual void operMenu();

	//添加账号  
	void addPerson();

	//查看账号
	void showPerson();

	//查看套餐信息
	void showFeast();

	//清空预订记录
	void cleanFile();

	//初始化容器
	void initVector();

	//顾客容器
	vector<Customer> vCus;

	//经理容器
	vector<Director> vTea;

	//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int id, int type);
};
