#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_Size;
};