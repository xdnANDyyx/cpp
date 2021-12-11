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

	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);
	//�ײ�����
	vector<Feast> vCom;

	//ѡ��˵�
	virtual void operMenu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴�ײ���Ϣ
	void showFeast();

	//���Ԥ����¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//�˿�����
	vector<Customer> vCus;

	//��������
	vector<Director> vTea;

	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);
};
