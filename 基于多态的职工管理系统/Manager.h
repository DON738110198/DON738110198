#pragma once
# include <iostream>
# include <string>
# include "Worker.h"
using namespace std;

//ְ��������
class Manager : public Worker
{
public:
	Manager(int id, string name, int depart_id);
	Manager();
	//��ʾ������Ϣ
	virtual void show_information();

	//��ʾ��λ����
	virtual string get_depart_id();
	/*int m_id;
	string m_name;
	int m_depart_id;*/

};