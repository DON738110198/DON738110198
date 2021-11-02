# include "Boss.h"

Boss::Boss(int id, string name, int depart_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_depart_id = depart_id;
}

//显示个人信息
void Boss::show_information()
{
	cout << "职工编号:" << this->m_id;
	cout << "\t职工姓名:" << this->m_name;
	cout << "\t职工岗位:" << this->get_depart_id();
	cout << "\t岗位职责:" << "向经理布置任务\n";
}

//显示岗位名称
string Boss::get_depart_id()
{
	return "老板";
}