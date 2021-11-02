# include <iostream>
# include <string>
# include "Manager.h"
using namespace std;

//职工抽象类

	Manager::Manager(int id, string name, int depart_id)
	{
		this->m_id = id;
		this->m_name = name;
		this->m_depart_id = depart_id;
	}
	//显示个人信息
	void Manager::show_information()
	{
		cout << "职工编号:" << this->m_id;
		cout << "\t职工姓名:" << this->m_name;
		cout << "\t职工岗位:" << this->get_depart_id();
		cout << "\t岗位职责:" << "完成老板布置的任务, 并且下发任务给员工\n" << endl;
	}
	//显示岗位名称
	string Manager::get_depart_id()
	{
		return "经理";
	}

