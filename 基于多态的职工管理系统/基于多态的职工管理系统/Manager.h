#pragma once
# include <iostream>
# include <string>
# include "Worker.h"
using namespace std;

//职工抽象类
class Manager : public Worker
{
public:
	Manager(int id, string name, int depart_id);
	Manager();
	//显示个人信息
	virtual void show_information();

	//显示岗位名称
	virtual string get_depart_id();
	/*int m_id;
	string m_name;
	int m_depart_id;*/

};