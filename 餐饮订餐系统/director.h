#pragma once
#define _CRT_SECURE_NO_WARNINGS//���ڸ߰汾��visual studioĬ�ϲ���ʹ��scanf�Ⱥ�������Ϊ��Щ����������ȫ���������Ӧ�Ĵ��溯��Ϊscanf_s�ȡ������visual studio��ʹ��scanf����Щvisual studio��Ϊ����ȫ�ĺ������ͻᱨ��
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Identity.h"
#include "orderFile.h"

class Director :public Identity
{
public:

	//Ĭ�Ϲ���
	Director();

	//�вι��� (ְ����ţ�����������)
	Director(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();
	

	int m_EmpId; //������

}; 
