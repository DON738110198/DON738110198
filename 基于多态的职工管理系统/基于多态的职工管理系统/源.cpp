# include <iostream>
# include "WorkerManager.h"
# include "Worker.h"
# include "Employee.h"
# include "Manager.h"
# include "Boss.h"
using namespace std;
int main(void)
{
	WorkerManager wm;
	wm.ShowMenu();
	int choice = 0;

	/*Worker* worker;
	worker = new Manager(1, "����", 2);
	worker->show_information();*/

	while (1)
	{
		wm.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�
		{
			wm.ExitSystem();
			break;
		}
		case 1: //����ְ����Ϣ
		{
			wm.add_emp();
			break;
		}
		case 2: //��ʾ
		{
			wm.show_emp();
			break;
		}
		case 3://ɾ��
		{
			wm.del_emp();
			break;
		}
		case 4://�޸�
		{
			wm.change_emp();
			break;
		}
		case 5://����
		{
			wm.find_emp();
			break;
		}
		case 6://���ձ������
		{
			wm.sort_emp();
			break;
		}
		case 7://���Ա���ĵ�
		{
			wm.clean_file();
			break;
		}

		}
	 system("pause");
	 system("cls");
	}


	return 0;
}