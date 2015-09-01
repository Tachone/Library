#include "Manger.h"
#include "Book.h"
#include "Menu.h"
#include "File.h"
#include "Worker.h"
#include <windows.h>
#include <conio.h>

Manger::Manger(){}

Worker* Manger::find_worker(string name,Worker* Whead)  //查找工作人员 
{
     Worker* here=Whead;
	 while(here!=NULL)
	 {
		 if(name==here->getname())
		     return here;
		 here=here->next;
	 }
	 cout<<"对不起，没有该用户！";
	 return NULL;
}

void Manger::menu_manger_choice(Worker* Whead,Book* Bhead,Reader* Rhead)  //管理人员菜单选择
{
     int choice=0;
	 while (choice!=5)
	 {
begin:
		 system("cls");
		 menu_manger();
		 cin>>choice;
		 if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
		 {
		    cout<<"对不起，您的输入错误！"<<endl;
			cout<<"请重新输入："<<endl;
			Sleep(500);
			goto begin;
		 }
		 Sleep(500);
		 system("cls");
		 if(choice==5)
			 return;
		 switch(choice)
		 {
		 case 1:
		     {
			     search_book(Bhead);  //查询图书
				 break;
			 }
		 case 2:
			 {
			     update_book(Bhead);  //更新图书
			     break;
			 }
		 case 3:
			 {
			     update_reader(Rhead);  //更新读者
				 break;
			 }
		 case 4:
			 {
			     update_worker(Whead);  //更新工作人员
				 break;
			 }
		 }
	 }
}

void Manger::update_book(Book* Bhead)  //更新图书
{
  int choice=0;
  while (choice!=4)
  {
begin:
	  menu_update_book();
	  cin>>choice;
	  if(choice!=1&&choice!=2&&choice!=3)
	  {
	      cout<<"对不起，输入错误"<<endl;
		  cout<<"请重新输入"<<endl;
		  Sleep(700);
		  goto begin;
	  }
	  system("cls");
	  if(choice==3)
		  return;
	  switch(choice)
	  {
	  case 1:
		  {
		     update_add_book(Bhead);  //增加图书
			 break;		  
		  }
	  case 2:
		  {
		     update_change_book(Bhead);  //修改图书信息
			 break;
		  }
	  }
  }
}

void Manger::update_add_book(Book* Bhead)  //增加图书
{
    Book* here=Bhead;
	while(here->next!=NULL) //将链表置于最后
		here=here->next;
	Book* temp;
	int number=here->book_number+1;  
	int command=1;
	while(command==1)
	{
	    temp=new Book;
		cin>>(*temp);
		temp->book_number=number++;
		here->next=temp;
		here=temp;
		cout<<"添加成功！"<<endl;
		Sleep(500);
		cin>>command;
	}
	temp->next=NULL;
	save_book(Bhead);
}

void Manger::update_change_book(Book* Bhead)  //修改书本信息
{
	int choice=0;
	while (choice!=5)
	{
begin:
		menu_change_book();
		cin>>choice;
		if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
		{
			cout<<"输入错误!\n请重新输入：\n";
			Sleep(500);
			goto begin;
		}
		if (choice==5) return;
start:
		system("cls");
		int number;
		cout<<"输入书号:\n";
		cin>>number;
		Book* here=find_book(number,Bhead);
		if (here==NULL) goto start;

		switch (choice)
		{
		case 1:
			{
				system("cls");
				cout<<"原书名 "<<here->book_name<<endl;
				cout<<"输入新书名\n";
				cin>>here->book_name;
				break;
			}
		case 2:
			{
				system("cls");
				cout<<"原作者 "<<here->book_author<<endl;
				cout<<"输入新作者\n";
				cin>>here->book_author;
				break;
			}
		case 3:
			{
				system("cls");
				cout<<"原馆藏数量 "<<here->storenum<<endl;
				cout<<"输入新的馆藏数量\n";
			    
					cin>>here->storenum;
				break;
			}
		case 4:
			{
				system("cls");
				cout<<"原出版社 "<<here->book_press<<endl;
				cout<<"输入新出版社\n";
				cin>>here->book_press;
				break;
			}
		}
		cout<<"修改成功!\n";
		Sleep(500);
		save_book(Bhead);
	}
}

void login_manger(Manger* Mhead,Book* Bhead,Reader* Rhead,Worker* Whead)     //管理人员登录
{
    string name;
	string password;
begin:
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
	Manger* here=Mhead;
	while(here!=NULL)
	{
		if(name==here->getname())
		{
			if(password==here->getpassword())
			{
			    Sleep(500);
				here->menu_manger_choice(Whead, Bhead, Rhead);
				return;
			}
			else
			{
			    int command=0;
				cout<<"对不起，您的密码错误！"<<endl;
				cout<<"是否重新输入？（输入1：是，输入0：否）"<<endl;
				cin>>command;
				if(command==1)
					goto begin;
				else return;
			}
		
		}
		here=here->next;
	}
	if(here==NULL)
	{
	   int command=0;
	   cout<<"对不起，该用户不存在！"<<endl;
	   cout<<"\t\t\t是否重新输入?(是输入1，不是输入0)\n";
	   cin>>command;
	   if (command==1) 
		   goto begin; 
	   else 
		   return;
	}
}

void Manger::update_delete_reader(string name,Reader* Rhead)  //删除读者
{
   Reader* here=Rhead;
   if(here->getname()==name)
   {
	   here->next=here->next->next;
	   return;
   }
   while(here->next->getname()!=name&&here->next->next!=NULL)
	   here=here->next;
   if(here->next->next!=NULL)
	   here->next=here->next->next;
   else
	   here->next=NULL;
}

void Manger::update_reader(Reader* Rhead)  //更新读者
{
    string name;
	int choice=0;
	while(choice!=5)
	{
begin2:
		menu_change_reader_1();
		cin>>choice;
		if(choice!=1&&choice!=2 && choice!=3 && choice!=4 && choice!=5)
		{
		    cout<<"对不起，输入错误！"<<endl;
			cout<<"请重新输入："<<endl;
		    Sleep(700);
			goto begin2;
		}
	    if(choice==5)
			return;
		
start2:		
		system("cls");
		cout<<"请输入读者的用户名"<<endl;
		cin>>name;
		Reader* rhere=find_reader(name,Rhead);
	    if(rhere==NULL)
		goto start2;
		
        switch(choice)
		{
		case 1:
		    {
		       system("cls");
			   cout<<"输入新年龄："<<endl;
			   cin>>rhere->age;			  
			   break;
		    }
		case 2:
			{
			   system("cls");
			   cout<<"输入性别（输入1：男，输入0：女）"<<endl;
			   int s;
			   cin>>s;
			   if(s==1)
				   rhere->sex="男";
			   else if(s==0)
				   rhere->sex="女";
			   else 
				   cout<<"输入错误！"<<endl;
			   
			   break;
			}
		case 3:
			{
			    system("cls");
				cout<<"输入新密码："<<endl;
				string password;
				cin>>password;
				rhere->setpassword(password);
				
				break;
			}
		case 4:
			{
               system("cls");
			   update_delete_reader(name,Rhead);
			   cout<<"删除成功！"<<endl;
			   Sleep(600);
			   save_reader(Rhead);
			   return;
			   break;

			}
		}
		cout<<"修改成功！"<<endl;
		Sleep(500);
		save_reader(Rhead);
		}
	}

void Manger::update_worker(Worker* Whead)  //更新工作人员
{
	int choice;
start3:
	menu_change_worker();
	cin>>choice;
	if(choice!=1 && choice!=2 && choice!=3)
	{
	    cout<<"对不起，您的输入错误";
		Sleep(700);
	    goto start3;	
	}
	if(choice==3)
		return;
	switch(choice)
	{
	case 1:
		{
           update_add_worker(Whead); //添加工作人员
		   save_worker(Whead);
		   break;
		}
	case 2:
		{
		   update_delete_worker(Whead);  //删除工作人员
		   save_worker(Whead);
		   break;
		}
	}
	cout<<"修改成功！"<<endl;
	Sleep(700);
}

void Manger::update_add_worker(Worker* Whead)  //增加工作人员
{
   Worker* here=Whead;
   while(here->next!=NULL)
	   here=here->next;
   Worker* temp;
   int command=1;
   while(command==1)
   {
       temp=new Worker;
	   system("cls");
	   cin>>(*temp);
	   here->next=temp;
	   here=temp;
	   cout<<"是否继续添加？（输入1：是，输入2：否）"<<endl;
	   cin>>command;
	   Sleep(500);
       system("cls");
   }
   temp->next=NULL;
}

void Manger::update_delete_worker(Worker* Whead)   //撤销工作人员
{
	string  name;
start2:
	system("cls");
	cout<<"请输入工作人员的用户名\n";
	cin>>name;
	if (find_worker(name,Whead)==NULL) goto start2;

	Worker* here=Whead;
	if (here->getname()==name)
	{
		here->next=here->next->next;
		return;
	}
	while (here->next->getname()!=name && here->next->next!=NULL) here=here->next;
	if (here->next->next!=NULL)
		here->next=here->next->next;
	else
		here->next=NULL;
	
	
}

