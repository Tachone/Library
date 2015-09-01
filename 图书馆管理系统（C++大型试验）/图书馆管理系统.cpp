#include <iostream>
#include <stdio.h>
#include "Menu.h"
#include "File.h"
using namespace std;

int main()
{   //将数据读入程序
	Book* Bhead=load_book();            
	Reader* Rhead=load_reader();
	Worker* Whead=load_worker();
	Manger* Mhead=load_manger();
	Encryption();//加密管理员
	int number=0;
	while (number!=5)
	{
		menu_system();
		cin>>number;
		switch (number)
		{
		case 1:
			{
				login_reader(Rhead,Bhead);//读者登录
				break;
			}
		case 2:
		   {
			   login_worker(Whead,Bhead,Rhead);//工作人员登录
			   break;
		   }	
		case 3:{
			   login_manger(Mhead,Bhead,Rhead,Whead);//管理人员登录
			   break;
			   }
		case 4:
			{
			  register_reader(Rhead);//注册读者
			  break;
			}
		
		}

	}
	system("cls");//清屏
	//保存数据
	save_book(Bhead);
	save_reader(Rhead);
	save_worker(Whead);

	//cout<<"信息已保存！"<<endl;
	cout<<"已退出，谢谢您的使用！"<<endl;
	system("pause");
return 0;
}