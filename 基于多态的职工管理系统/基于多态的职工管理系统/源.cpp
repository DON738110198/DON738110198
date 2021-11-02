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
	worker = new Manager(1, "李四", 2);
	worker->show_information();*/

	while (1)
	{
		wm.ShowMenu();
		cin >> choice;
		switch (choice)
		{
		case 0://退出
		{
			wm.ExitSystem();
			break;
		}
		case 1: //增加职工信息
		{
			wm.add_emp();
			break;
		}
		case 2: //显示
		{
			wm.show_emp();
			break;
		}
		case 3://删除
		{
			wm.del_emp();
			break;
		}
		case 4://修改
		{
			wm.change_emp();
			break;
		}
		case 5://查找
		{
			wm.find_emp();
			break;
		}
		case 6://按照编号排序
		{
			wm.sort_emp();
			break;
		}
		case 7://清空员工文档
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