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

//ѧ����
class Customer :public Identity
{
public:
	//Ĭ�Ϲ���
	Customer();

	//�вι���(��Ա�š�����������)
	Customer(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��Ա��
	int m_Id;

	//�ײ�����
	vector<Feast> vFe;
};
