#pragma once
#define _CRT_SECURE_NO_WARNINGS//由于高版本的visual studio默认不让使用scanf等函数，认为这些函数不够安全，而其相对应的代替函数为scanf_s等。如果在visual studio中使用scanf等那些visual studio认为不安全的函数，就会报错。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Identity.h"
#include "orderFile.h"

class Director :public Identity
{
public:

	//默认构造
	Director();

	//有参构造 (职工编号，姓名，密码)
	Director(int empId, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();
	

	int m_EmpId; //经理编号

}; 
