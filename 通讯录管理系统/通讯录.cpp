#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define max 1000
using namespace std;
void showmenu()
{
	const string BLUE_BG = "\033[44m";       
	const string WHITE_TEXT = "\033[37m";    
	const string GREEN = "\033[32m";         
	const string BOLD = "\033[1m";           
	const string BLINK = "\033[5m";          
	const string RESET = "\033[0m";          
	cout << BLUE_BG << WHITE_TEXT << BOLD << "************************" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 1.添加联系人 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 2.显示联系人 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 3.删除联系人 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 4.查找联系人 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 5.修改联系人 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 6.清空联系人 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET<< GREEN << BOLD << BLINK << " 0.退出通讯录 " << RESET<< BLUE_BG << WHITE_TEXT << BOLD << "*****" << RESET << endl;
	cout << BLUE_BG << WHITE_TEXT << BOLD << "************************" << RESET << endl;
}
typedef struct person
{
	string name;
	string sex;
	int age;
	string phone;
	string addr;
}human;
typedef struct addressbooks
{
	human parr[max];
	int size;
}abks;
void addperson(abks* abs)
{
	if (abs->size == max)
	{
		cout << "通讯录满了！！！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->parr[abs->size].name=name;
		cout << "请输入性别:" << endl;
		cout << "1---男" << endl << "2---女" << endl;
		int ok = 0;
		while (!ok)
		{
			int temp;
			cin >> temp;
			switch (temp)
			{
			case 1:
				abs->parr[abs->size].sex = "男";
				ok = 1;
				break;
			case 2:
				abs->parr[abs->size].sex = "女";
				ok = 1;
				break;
			default:
				cout << "输入错误，请重新输入" << endl;
			}
		}
		cout << "请输入年龄:" << endl;
		while (1)
		{
			int age;
			cin >> age;
			if (age >= 0 && age <= 200)
			{
				abs->parr[abs->size].age = age;
				break;
			}
			else
				cout << "你踏马输入了个什么玩意，重新输入！" << endl;

		}
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;
		abs->parr[abs->size].phone = phone;
		cout << "请输入家庭住址:" << endl;
		string add;
		cin >> add;
		abs->parr[abs->size].addr = add;
		abs->size++;
		cout << "添加成功！！" << endl;
		system("pause");
		system("cls");
	}
}
void showperson(abks* abs)
{
	if (abs->size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名:" << abs->parr[i].name << "\t";
			cout << "性别：" << abs->parr[i].sex << "\t";
			cout << "年龄：" << abs->parr[i].age << "\t";
			cout << "电话：" << abs->parr[i].phone << "\t";
			cout << "住址：" << abs->parr[i].addr << endl;
		}
	}
}
int isexist(abks* abs,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->parr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
void deleteperson(abks* abs)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >>name;
	int ret=isexist(abs, name);
	if (ret != -1)
	{
		if (abs->size == ret+1)
		{
			abs->size--;
			cout << "删除成功！" << endl;
		}
		else
		{
			abs->parr[ret].name = abs->parr[abs->size-1].name;
			abs->parr[ret].age = abs->parr[abs->size-1].age;
			abs->parr[ret].phone = abs->parr[abs->size-1].phone;
			abs->parr[ret].addr = abs->parr[abs->size-1].addr;
			abs->parr[ret].sex = abs->parr[abs->size-1].sex;
			abs->size--;
			cout << "删除成功！" << endl;
		}
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(abks* abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret=isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << abs->parr[ret].name << "\t";
		cout << "性别：" << abs->parr[ret].sex << "\t";
		cout << "年龄：" << abs->parr[ret].age << "\t";
		cout << "电话：" << abs->parr[ret].phone << "\t";
		cout << "住址：" << abs->parr[ret].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void clsabks(abks* abs)
{
	abs->size = 0;
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
}
void modifyperson(abks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	showperson(abs);
	string name;
	cin >> name;
	int ret=isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << "\t";
		cin >> abs->parr[ret].name;
		cout << "性别：" << "\t";
		cin >> abs->parr[ret].sex;
		cout << "年龄：" << "\t";
		cin>>abs->parr[ret].age;
		cout << "电话：" << "\t";
		cin>>abs->parr[ret].phone;
		cout << "住址：" << endl;
		cin>>abs->parr[ret].addr;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	abks abs;
	abs.size = 0;
	int select = 0;
	while (true)
	{
		showmenu();
		cout << "\033[33m请输入您要进行的操作前的序号\033[0m" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
		{
			showperson(&abs);
			
			system("pause");
			system("cls");
			break;
		}
		case 3:
			deleteperson(&abs);
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			clsabks(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	
	return 0;
}