#include "orderFile.h"
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //����
	string interval;  //ʱ���
	string Id;     //��Ա��
	string Name;   //��Ա����
	string fId;    //�ײͱ��
	string status;    //Ԥ��״̬


	this->m_Size = 0; //Ԥ����¼����

	while (ifs >> date && ifs >> interval && ifs >> Id && ifs >> Name && ifs >> fId && ifs >> status)
	{
		//���Դ���
		

		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);//������������0λ�ÿ�ʼ��pos��
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = Id.find(":");
		if (pos != -1)
		{
			key = Id.substr(0, pos);
			value = Id.substr(pos + 1, Id.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = Name.find(":");//find����string���õĲ��Һ��������Ҳ������� -1
		if (pos != -1)
		{
			key = Name.substr(0, pos);//string���õĽ�ȡ�ַ�����
			value = Name.substr(pos + 1, Name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = fId.find(":");
		if (pos != -1)
		{
			key = fId.substr(0, pos);
			value = fId.substr(pos + 1, fId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}


		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	
	ifs.close();
}
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "cId:" << this->m_orderData[i]["cId"] << " ";
		ofs << "cName:" << this->m_orderData[i]["cName"] << " ";
		ofs << "fId:" << this->m_orderData[i]["fId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
