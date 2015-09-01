#include "Worker.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
#include "File.h"
#include <stdlib.h>


Worker::Worker(){}

void Worker::book_borrow(Reader* Rhead,Book* Bhead)//借书
{
    string name;
	Reader* rhere;
	int a=0;
	while (a==0)
	{
	   system("cls");
	   cout<<"请输入读者的用户名：";
	   cin>>name;
	   rhere=find_reader(name,Rhead);
	   if(rhere==NULL)
	   {
	      cout<<"对不起，没有该用户！"<<endl;
		  cout<<"请重新输入"<<endl;
		  Sleep(500);//暂停0.5秒
	   }
	   if(rhere!=NULL)
	   {
	      cout<<"已查找到该用户"<<endl;
		  cout<<"请继续操作"<<endl;
		  Sleep(700);
		  break;
	   }	
	}
	int num;
	Book* bhere;
	while(a==0)
	{     
		 system("cls");
	     cout<<"请输入您要借阅的图书的书号：";
         cin>>num;	    
	     bhere=find_book(num,Bhead);
		 if(bhere==NULL)
		 {
		     cout<<"抱歉，没有您要借阅的图书"<<endl;
			 cout<<"请您重新输入："<<endl;
			 Sleep(700);
		 }
	     if(bhere!=NULL)
		 {
			 
			 break;	
		 }
	}
	bhere=find_book(num,Bhead);
	if (bhere->borrownum==bhere->storenum)  //判断图书是否可以借阅
	     {
			cout<<"对不起，您要借阅的图书已借完"<<endl;
	        Sleep(500);
	     }
			 else if(rhere->borrows<5)
			 {
				bhere->borrownum++;
				rhere->borrow[rhere->borrows++]=bhere->book_number;
				rhere->show_borrows(Bhead);////////新加代码
				cout<<"借书成功！"<<endl;
				save_book(Bhead);
				save_reader(Rhead);
				system("pause");
			 }
			else
				{
				cout<<"该读者已借满图书"<<endl;
				system("pause");
				}
}

Reader* find_reader(string name,Reader* Rhead)//（友元函数） 查找读者
{
    Reader* here=Rhead;
	while (here!=NULL)
	{
		if(name==here->getname())
		   return here;
		here=here->next;	
	}
	cout<<"对不起，没有该用户！";
	return NULL;
}

void Worker::book_return(Reader* Rhead,Book* Bhead)  //还书
{
    string name;
	Reader* rhere;
start:
	int flag=0;
	do
	{
		if (flag++) cout<<"\n\n\n\t\t\t没有该用户!\n请重新输入\n";
		Sleep(500); 
		system("cls");
		cout<<"\n\n\n\t\t\t输入读者用户名:";
		cin>>name;
		rhere=find_reader(name,Rhead);
	} while (rhere==NULL);	                                         //判断是否存在该读者
	int no;
	Book* bhere;
	flag=0;
	do
	{
		if (flag++) cout<<"\n\n\n\t\t\t没有该书!\n\t\t\t请重新输入\n\t\t\t";
		Sleep(500);  system("cls");
		cout<<"该读者已借书目:\n";
		rhere->show_borrows(Bhead);
		cout<<"\n\n输入要还书号:";
		cin>>no;
		bhere=find_book(no,Bhead);
	} while (bhere==NULL);	                                         //判断是否存在该书	
	int c=0;
	while (rhere->borrow[c]!=bhere->book_number && c<rhere->borrows) 
		c++;
	if (c==rhere->borrows) 
	{ 
		cout<<"\n\n\n\t\t\t该读者未借这本书\n";                   	 //未借跳出
		int command=0;
		cout<<"\t\t\t是否重新输入:(是输入1，否输入0):\n\t\t\t";
		cin>>command;
		if (command) 
			goto start; 
		else return;
	}
	int i;
	for (i=c+1;i<rhere->borrows;i++) 
		rhere->borrow[i-1]=rhere->borrow[i];
	rhere->borrows--;
	rhere->show_borrows(Bhead);
	//rhere->show_borrows(bhere);
	cout<<"\n\n\n\t\t\t还书成功\n";

	bhere->borrownum--;
	save_book(Bhead);
	save_reader(Rhead);
	system("pause");
}

void login_worker(Worker* Whead,Book* Bhead,Reader* Rhead)  //工作人员登录
{
     string name;
	 string password;
 begin2:
	 system("cls");
	 cout<<"请输入您的用户名：";
	 cin>>name;
	 cout<<"请输入密码：";
	 //cin>>password;
	 char c;
	 for(int i = 0; i <= 5; i++)
	 {
		 c = _getch();
		 cout << "*";
		 password += c;
	 }
	 Worker* here=Whead;
	 while (here!=NULL)
	 {
		 if(here->getname()==name)
		 {
			 if(here->getpassword()==password)
			 {
			    Sleep(500);
				here->menu_worker_choice(Rhead,Bhead);
				return;
			 }
			 else
			 {
			    cout<<"对不起，您的密码错误！"<<endl;
				cout<<"是否重新输入？（输入1：是，输入0：否）"<<endl;
				int a=0;
				cin>>a;
				if(a==1)
					goto begin2;
				else return;
			 
			 }
		 }
	     here=here->next;
	 }
	 if(here==NULL)
	 {
	     int a=0;
		 cout<<"对不起，用户名不存在！"<<endl;
		 cout<<"是否重新输入？（输入1：是，输入0：否）"<<endl;
		 cin>>a;
		 if(a==1)
			 goto begin2;
		 else return;	 
	 }
}

void Worker::menu_worker_choice(Reader* Rhead,Book* Bhead)  //工作人员菜单选择
{
    int choice=0;
	while (choice!=5)
	{
start1:
		menu_worker();
		cin>>choice;
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
		{
		    cout<<"对不起，您的输入错误！"<<endl;
			cout<<"请重新输入："<<endl;
			Sleep(500);
			goto start1;
		}
		Sleep(500);
		system("cls");
		if(choice==5)
			return;
		switch (choice)
		{
		case 1:
			{
				book_borrow(Rhead,Bhead);
				break;
			}
		case 2:
			{
			    book_return(Rhead,Bhead);
				break;
			}
		case 3:
			{
			    search_book(Bhead);
				break;
			}
		case 4:
			{
			   string name;
			   system("cls");
			   cout<<"请输入要查询的读者的用户名："<<endl;
			   cin>>name;
			   Reader* here=find_reader(name,Rhead);
			   here->show_reader();
			   cout<<"该读者借阅信息："<<endl;
			   here->show_borrows(Bhead);  //显示读者的借阅信息
			   system("pause");
			   break;
			}
		}
	}
}

istream& operator >>(istream& in,Worker& Whead)  //">>"操作符重载
{
    string name;
	string password;
	cout<<"请输入用户名："<<endl;
	in>>name;
	Whead.setname(name);
	cout<<"请输入密码："<<endl;
	in>>password;
	Whead.setpassword(password);
	return in;
}