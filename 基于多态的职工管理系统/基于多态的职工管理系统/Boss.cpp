# include "Boss.h"

Boss::Boss(int id, string name, int depart_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_depart_id = depart_id;
}

//��ʾ������Ϣ
void Boss::show_information()
{
	cout << "ְ�����:" << this->m_id;
	cout << "\tְ������:" << this->m_name;
	cout << "\tְ����λ:" << this->get_depart_id();
	cout << "\t��λְ��:" << "����������\n";
}

//��ʾ��λ����
string Boss::get_depart_id()
{
	return "�ϰ�";
}