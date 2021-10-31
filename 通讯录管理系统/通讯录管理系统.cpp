# include <iostream>
# include <string>
# define MAX 1000
using namespace std;

struct person//人物结构体，里面是个人信息
{
    string name;
    int sex;
    string phonenumber;
    string address;
};
struct addressbook//通讯录结构体
{
    int index;//访问到的数据的下标
    struct person personarray[MAX];//一个人物数组，通讯录上限1000人

};


void showmenu(void)
{
    cout << "*******************************" << endl;
    cout << "*****1.新建联系人***************" << endl;
    cout << "*****2.显示全部联系人***********" << endl;
    cout << "*****3.删除联系人***********" << endl;
    cout << "*****4.查找联系人***************" << endl;
    cout << "*****5.修改联系人***************" << endl;
    cout << "*****0.退出系统*****************" << endl;
}

void newperson(struct addressbook* ads)
{
    cout << "请输入姓名 :" << endl;
    cin >> ads->personarray[ads->index].name;

    while (1)
    {
        cout << "请输入性别 :（1 -- 男 2 -- 女）" << endl;
        cin >> ads->personarray[ads->index].sex;
        if (ads->personarray[ads->index].sex == 1 || ads->personarray[ads->index].sex == 2)
        {
            break;
        }
        cout << "您的输入有误，请重新输入" << endl;
    }

    cout << "请输入手机号码 ：" << endl;
    cin >> ads->personarray[ads->index].phonenumber;

    cout << "请输入地址 :" << endl;
    cin >> ads->personarray[ads->index].address;

    cout << "恭喜你，添加联系人成功" << endl;
    ads->index++;
    return;
}

void showperson(struct addressbook* ads)//显示通讯录
{
    int i, j;
    cout << "姓名" << "\t" << "性别" << "\t" << "手机号码" << "\t" << "居住地址" << "\t" << endl;
    for (i = 0; i < ads->index; i++)
    {
        cout << ads->personarray[i].name << "\t";
        cout << (ads->personarray[i].sex == 1 ? "男" : "女") << "\t";
        cout << ads->personarray[i].phonenumber << "\t";
        cout << ads->personarray[i].address << "\t" << endl;

    }
    return;
}

int isexist(struct addressbook* ads, string name)
{
    int i, j;
    for (i = 0; i < ads->index; i++)
    {
        if (ads->personarray[i].name == name)
        {
            return i;
        }
    }
    return -1;
}
void deleteperson(struct addressbook * ads)
{
    cout << "请输入要删除的人的姓名：" << endl;
    string name;
    cin >> name;
    int find = isexist(ads, name);
    int i;
    for (i = find; i < ads->index; i++)
    {
        ads->personarray[i] = ads->personarray[i + 1];
    }

    ads->index--;

}
void searchperson(struct addressbook * ads)
{
    cout << "请输入要查找的人的名字：" << endl;

    string name;
    cin >> name;

    int find = isexist(ads, name);

    if (find == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        cout << "姓名：" << ads->personarray[find].name << "\t";
        cout << "性别：" << ads->personarray[find].sex << "\t";
        cout << "手机号码：" << ads->personarray[find].phonenumber << "\t";
        cout << "居住地址：" << ads->personarray[find].address << "\t";
    }
}
void changeperson(struct addressbook* ads)
{
    string name;
    cin >> name;

    int find = isexist(ads, name);

    if (find == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        cout << "请输入您要修改的信息：" << endl;
        cout << "姓名:" << endl;
        cin >> ads->personarray[find].name;
        cout << "性别:" << endl;
        cin >> ads->personarray[find].sex;
        cout << "手机号码:" << endl;
        cin >> ads->personarray[find].phonenumber;
        cout << "居住地址:" << endl;
        cin >> ads->personarray[find].address;

        cout << "修改成功" << endl;
    }

}

int main(void)
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
            newperson(&ads);
            break;
        }
        case 2://显示全部联系人
        {
            showperson(&ads);
            break;
        }
        case 3://删除联系人
        {
            deleteperson(&ads);
            break;
        }
        case 4://查找联系人
        {
            searchperson(&ads);
            break;
        }
        case 5://修改联系人
        {
            changeperson(&ads);
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

        system("pause");
        system("cls");
    }





    return 0;
}
