#pragma once
# include "Worker.h"
# include <iostream>
using namespace std;
class Employee : public Worker
{
public:

	Employee(int id, string name, int depart_id);
	//显示个人信息
	virtual void show_information();

	//显示岗位名称
	virtual string get_depart_id();
};