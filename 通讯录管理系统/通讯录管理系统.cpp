# include <iostream>
# include <string>
# define MAX 1000

struct addressbook//ͨѶ¼�ṹ��
{
    int index;//���ʵ������ݵ��±�
    struct person personarray[MAX];//һ���������飬ͨѶ¼����1000��
    
};
struct person//����ṹ�壬�����Ǹ�����Ϣ
{
    string name;
    int sex;
    string phonenumber;
    string address;
};

void showmenu(void)
{
    cout << "*******************************" << endl;
    cout << "*****1.�½���ϵ��***************" << endl;
    cout << "*****2.��ʾȫ����ϵ��***********" << endl;
    cout << "*****3.ɾ��ȫ����ϵ��***********" << endl;
    cout << "*****4.������ϵ��***************" << endl;
    cout << "*****5.�޸���ϵ��***************" << endl;
    cout << "*****0.�˳�ϵͳ*****************" << endl; 
}

void newperson (struct addressbook * ads)
{
    cout << "���������� :" << endl;
    cin >> ads -> personarray[ads -> index].name;

    cout << "�������Ա� :��1 -- �� 2 -- Ů��" << endl;
    cin >> ads -> personarray[ads -> index].sex;

    cout << "�������ֻ����� ��" << endl;
    cin >> ads -> personarray[ads -> index].phonenumber;

    cout << "�������ַ :" << endl;
    cin >> ads -> personarray[ads -> index].address;

    ads -> index++;
}

void showperson (struct addressbook * ads)//��ʾͨѶ¼
{
    int i, j;
    for (i = 0; i < ads -> index; i++)
    {
        cout << ads -> personarray[ads -> index].name << "/t";
        cout << (ads -> personarray[ads -> index].sex == 1 ? "��" : "Ů") << "/t";
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

    while (1)//ϵͳӦ��һֱѭ���������ҳ��
    {
        showmenu();
        cin >> select;

        switch (select)
        {
        case 1://�½���ϵ��
        {
            newperson (&ads);
            break;
        }
        case 2://��ʾȫ����ϵ��
        {
            showperson (&ads);
            break;
        }
        case 3://ɾ��ȫ����ϵ��
        {

            break;
        }
        case 4://������ϵ��
        {

            break;
        }
        case 5://�޸���ϵ��
        {

            break;
        }
        case 0:
        {
            cout << "��ӭ���ٴ�ʹ��ͨѶ¼����ϵͳ" << endl;
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

