# include <iostream>
# include <string>
# include "Manager.h"
using namespace std;

//ְ��������

	Manager::Manager(int id, string name, int depart_id)
	{
		this->m_id = id;
		this->m_name = name;
		this->m_depart_id = depart_id;
	}
	//��ʾ������Ϣ
	void Manager::show_information()
	{
		cout << "ְ�����:" << this->m_id;
		cout << "\tְ������:" << this->m_name;
		cout << "\tְ����λ:" << this->get_depart_id();
		cout << "\t��λְ��:" << "����ϰ岼�õ�����, �����·������Ա��\n" << endl;
	}
	//��ʾ��λ����
	string Manager::get_depart_id()
	{
		return "����";
	}

