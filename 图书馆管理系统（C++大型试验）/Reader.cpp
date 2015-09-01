#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Reader.h"
#include "Menu.h"
#include "File.h"
#include "People.h"
#include <windows.h>

using namespace std;

Reader::Reader(){}

void Reader::show_reader()//显示读者基本信息
{
	cout<<"\t\t 姓名："<<getname()<<endl;
	cout<<"\t\t 性别："<<sex<<endl;
	cout<<"\t\t 年龄："<<age<<endl;

}

void login_reader(Reader* Rhead , Book* Bhead)//读者登录
{

	int f=0;
	string name;
	string  password;
	Reader* here=Rhead;
start1:
	system("cls");
	cout<<"                 \n\n\n请输入用户名：";
	cin>>name;
	cout<<"                 \n\n\n请输入密码：";
	//cin>>password;
	char c;
	for(int i = 0; i <= 5; i++)
	{
		c = _getch();
		cout << "*";
		password += c;
	}
	while (here!=NULL)
	{
		if(name==here->getname())//如果姓名和密码符合要求
		{
		     if (here->getpassword()==password)
			 {
			       here->menu_reader_choice(Bhead);
				   return;
			 }else 
			 {
			    f=1;
				int command;
				cout<<"             \n\n\n密码错误！";
				cout<<"             \n\n\n是否重新输入\n           1：是 ；0：否"<<endl;
				cin>>command;
				if(command==1)
					goto start1;//goto语句，返回至start1处
				else return;
			 }
		}
		here=here->next;
	}   
	if (f==0)
	{
		int command=0;
		cout<<"\n\n\n\t\t\t该用户不存在!\n";
		cout<<"\t\t\t是否重新输入?(是输入1，不是输入0)\n";
		cin>>command;
		if (command==1) goto start1; 
		else return;
		return;
	}

}

void Reader::menu_reader_choice(Book* Bhead)//读者菜单选择
{
	int choice=0;
	while (choice!=5)
	{
start2:
		system("cls");
		menu_reader();
		cin>>choice;
		if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
		{
			cout<<"输入错误!\n请重新输入：\n";
			Sleep(500);
			goto start2;
		}
		if(choice==5)
			return;
		Sleep(500);
		system("cls");
		switch (choice)
		{
			case 1:                                                       //查找馆藏书目 
			{
				search_book(Bhead);
				break;
			}
			case 2:                                                       //查看个人借阅信息 
			{
				show_borrows(Bhead);
				system("pause");
				break;
			}
			case 3:                                                       //修改个人信息　
			{
				change_reader();
				break;
			}
			case 4:                                                       //查看个人信息　
			{
				show_reader();
				system("pause");
				break;
			}
			
		}
	}
}

void Reader::show_borrows(Book* Bhead)//显示读者借阅信息
{
	cout<<setw(12)<<"馆藏书号"<<setw(25)<<"书名"<<setw(9)<<"作者"<<setw(30)<<"出版社\n";
	int c;
	for (c=0;c<borrows;c++){
		cout<<(*find_book(borrow[c],Bhead));//操作符重载
	}
}

void Reader::change_reader()//修改读者信息
{
    int choice=0;
	while (choice!=5)
	{
start1:
		menu_change_reader();
		cin>>choice;
		if (choice!=1 && choice!=2 && choice!=3 && choice!=4)
		{
			cout<<"输入错误!\n请重新输入:\n";
			Sleep(500);
			goto start1;
		}
		if (choice==4) return;
		switch (choice)
		{
			case 1:
			{
				system("cls");
				cout<<"请输入年龄\n";
				cin>>age;
				break;
			}
			case 2:
			{
				system("cls");
				cout<<"请输入性别(男输入1，女输入0)\n";
				int s;
				cin>>s;
				if(s==1){
					sex="男";
				}else 
				if(s==0){ 
					sex="女"; 
				}
				else cout<<"输入错误\n";
				break;
			}
			case 3:
			{
				system("cls");
				cout<<"请输入新密码\n";
				string password;
				cin>>password;
				setpassword(password);
				break;
			}
			case 4:
			{
				break;
			}
		}
		cout<<"修改成功!\n";
		Sleep(500);
	}
}

void register_reader(Reader* Rhead)//注册读者
{
     string name;
	 system("cls");
	 int flag=0;//标识符
	 do
	 {
	    if(flag++)
			cout<<"该用户名已被注册，请重新输入！"<<endl;
		Sleep(700);
		system("cls");
		cout<<"请输入您的用户名："<<endl;
		cin>>name;
	 }while(find_reader_if(name,Rhead));//判断是否有此读者
	 Reader* here=Rhead;
	 while (here->next!=NULL)
		 here=here->next;//将链表置于最后
	 Reader* new_reader;
	 new_reader=new Reader;
	 new_reader->setname(name);
	 cout<<"请输入您的密码："<<endl;
	 string password;
	 cin>>password;
	 new_reader->setpassword(password);
	 cout<<"请输入您的年龄："<<endl;
	 cin>>new_reader->age;
	 cout<<"请输入您的性别（输入1：男，输入0：女）"<<endl;
	 int s;
	 cin>>s;
	 do
	 {
	    if (s==1)
			new_reader->sex="男";
		else if(s==0)
			new_reader->sex="女";
		else
			cout<<"输入错误，请重新输入！"<<endl;
	 }while(s==1&&s==0);
	 new_reader->borrows=0;
	 here->next=new_reader;
	 new_reader->next=NULL;
	 save_reader(Rhead);//存入数据
	 cout<<"注册成功！"<<endl;
	 system("pause");
}

bool find_reader_if(string name,Reader* Rhead)//查找是否存在名为name的读者
{
    Reader* here=Rhead;
	while(here!=NULL)
	{
		if (name==here->getname())
			return true;
		here=here->next;
	}
	return false;
}

