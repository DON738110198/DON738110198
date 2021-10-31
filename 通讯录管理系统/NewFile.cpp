# include <iostream>
# include <string>
# define MAX 1000

struct addressbook//通讯录结构体
{
    int index;//访问到的数据的下标
    struct person personarray[MAX];//一个人物数组，通讯录上限1000人
    
};
struct person//人物结构体，里面是个人信息
{
    string name;
    int sex;
    string phonenumber;
    string address;
};

void showmenu(void)
{
    cout << "*******************************" << endl;
    cout << "*****1.新建联系人***************" << endl;
    cout << "*****2.显示全部联系人***********" << endl;
    cout << "*****3.删除全部联系人***********" << endl;
    cout << "*****4.查找联系人***************" << endl;
    cout << "*****5.修改联系人***************" << endl;
    cout << "*****0.退出系统*****************" << endl; 
}

void newperson (struct addressbook * ads)
{
    cout << "请输入姓名 :" << endl;
    cin >> ads -> personarray[ads -> index].name;

    cout << "请输入性别 :（1 -- 男 2 -- 女）" << endl;
    cin >> ads -> personarray[ads -> index].sex;

    cout << "请输入手机号码 ：" << endl;
    cin >> ads -> personarray[ads -> index].phonenumber;

    cout << "请输入地址 :" << endl;
    cin >> ads -> personarray[ads -> index].address;

    ads -> index++;
}

void showperson (struct addressbook * ads)//显示通讯录
{
    int i, j;
    for (i = 0; i < ads -> index; i++)
    {
        cout << ads -> personarray[ads -> index].name << "/t";
        cout << (ads -> personarray[ads -> index].sex == 1 ? "男" : "女") << "/t";
        cout << ads -> personarray[ads -> index].phonenumber << "/t";
        cout << ads -> personarray[ads -> index].address << "/t" << endl; 

    }

}
using namespace std;    
    
int main (void)
{
    int select;

    struct addressbook ads;
    ads.index = 0;

    while (1)//系统应当一直循环出现这个页面
    {
        showmenu();
        cin >> select;

        switch (select)
        {
        case 1://新建联系人
        {
            newperson (&ads);
            break;
        }
        case 2://显示全部联系人
        {
            showperson (&ads);
            break;
        }
        case 3://删除全部联系人
        {

            break;
        }
        case 4://查找联系人
        {

            break;
        }
        case 5://修改联系人
        {

            break;
        }
        case 0:
        {
            cout << "欢迎您再次使用通讯录管理系统" << endl;
            return 0;
        }
        
        default:
            break;
        }

        system ("pause");
        system ("cls");
    }





    return 0;
}

