#pragma once
# include "Worker.h"
# include <iostream>
using namespace std;

class Boss :public Worker
{
public:

	Boss(int id, string name, int depart_id);

	//��ʾ������Ϣ
	virtual void show_information();

	//��ʾ��λ����
	virtual string get_depart_id();

};