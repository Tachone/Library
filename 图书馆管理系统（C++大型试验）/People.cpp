#include <string>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "Menu.h"
#include "People.h"
#include "Book.h"


using namespace std;

People::People(){}

string People::getname()
{
     return name;
}

string People::getpassword()
{

	return password;
}

void People::setname(string newname)
{
	name=newname;

}

void People::setpassword(string newpassword)
{
	password=newpassword;

}

void People::search_book(Book* Bhead)//查询图书
{
	int choice=0;
	while(choice!=3)
	{
       menu_search_book();//显示查找界面函数
	   cin>>choice;
	   if(choice==4) 
		   return;
	   else if(choice==1)
		   search_book_1(Bhead);//使用图书号查询图书
	   else if(choice==2)
		   search_book_2(Bhead);//使用图书名查询图书
	   else if(choice==3)
		   print_all_book(Bhead);//查看所有图书
	   else 
		   cout<<"输入错误！\n请重新输入"<<endl;
	    system("pause");
	}
}

void People::search_book_1(Book* Bhead)//按图书号查询图书函数
{
    int number;//图书号
	int find;//标识符
	int choice=1;
	while(choice)
	{
	   Book* here=Bhead;
	   find=0;
	   system("cls");
	   cout<<"请输入您要查询的图书的书号：";
	   cin>>number;
	   while(here!=NULL)
	   {
	        if(here->book_number==number)
			{
			    here->output();//打印要查询的图书信息
				find=1;//修改标识符
				break;
			}
			here=here->next;	   
	   }
	   if(find==0)
		   cout<<"对不起，您所查询的图书不存在。\n";
		   cout<<"如继续查询请输入1，退出请输入0\n";
		   cin>>choice;
	       if (choice==0)
			   return;
	}

}

void People::search_book_2(Book* Bhead)//按图书名查询图书
{
	int find=0;//标识符
	int choice=1;
	string bookname;	
	while(choice)
	{
	Book* here=Bhead;
	system("cls");
	cout<<"请输入您要查询的图书的书名：";
	cin>>bookname;
	while(here!=NULL)
	{
		int temp = here->book_name.find(bookname);//模糊查询
		if (temp != here->book_name.npos)
		{
			here->output();
			find = 1;
		}

		/*if(here->book_name==bookname)
	        {
	            here->output();
				find=1;
				break;
	        }*/
		here=here->next;
	}
		if(find==0)
		   cout<<"对不起，您所查询的图书不存在。\n";
		   cout<<"如继续查询请输入1，退出请输入0\n";
	       cin>>choice;		
	}

}

void People::print_all_book(Book* Bhead)//打印所有图书信息
{
    system("cls");
	Book* here=Bhead;
	cout<<setw(10)<<"书号"<<setw(20)<<"书名"<<setw(15)<<"作者"<<setw(20)<<"出版社"<<"     借阅情况\n"<<endl;
	while(here!=NULL)
	{
	    cout<<(*here);//操作符重载
		here=here->next;
	
	}
	
}

Book* People::find_book(int number,Book* Bhead)     //查询图书       
{
	Book* here=Bhead;
	while (here!=NULL)
	{
		if (here->book_number==number)
			return here;
		here=here->next;
	}
	cout<<"没有该书!\n";
	return NULL;
}

