#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "File.h"

using namespace std;

Reader* load_reader()//读取读者的数据到链表中
{

	string newname;
	string newpassword;
	fstream fin("reader.txt",ios::in);//打开文件读取
		if(!fin)
		{
		    cout<<"open error!"<<endl;
			exit(1);
		}
    Reader* Rhead;
	Reader* temp;
	temp=new Reader;
	if (fin>>newname)
	{
	     temp->setname(newname);
		 fin>>newpassword;
		 temp->setpassword(newpassword);
		 fin>>temp->sex>>temp->age>>temp->borrows;
		 for(int c=0;c<temp->borrows;c++)
			 fin>>temp->borrow[c];
		 Rhead=temp;
		 Reader* temp1;
		 temp1=new Reader;
		 while(fin>>newname>>newpassword>>temp1->sex>>temp1->age>>temp1->borrows)
		 {
		       temp1->setname(newname);
			   temp1->setpassword(newpassword);
			   int c;
			   for(c=0;c<temp1->borrows;c++)
				   fin>>temp1->borrow[c];
			   temp->next=temp1;
			   temp=temp1;
			   temp1=new Reader;
			   	 
		 }
		 delete temp1;
		 temp->next=NULL;
	}
	else
	{
		delete temp;
	    Rhead=NULL;
	}
	fin.close();
	return Rhead;//返回链表头
}

Book* load_book()	//读取链表中书的数据
{
	fstream fin("book.txt",ios::in);
	if(!fin)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	Book* Bhead;
	Book* temp;
	temp=new Book;
	if (fin>>temp->book_number>>temp->book_name>>temp->book_author>>temp->book_press>>temp->storenum>>temp->borrownum)
	{
		Bhead=temp;
		Book* temp1;
		temp1=new Book;
		while (fin>>temp1->book_number>>temp1->book_name>>temp1->book_author>>temp1->book_press>>temp1->storenum>>temp1->borrownum)
		{
			temp->next=temp1;
			temp=temp1;
			temp1=new Book;
		}
		delete temp1;
		temp->next=NULL;
	} else
	{
		delete temp;
		Bhead=NULL;
	}
	fin.close();
	return Bhead;
}

Worker* load_worker()//读取链表中工作人员的信息
{
    string newname,newpassword;
	fstream fin("worker.txt",ios::in);
	if(!fin)
	{
	   cout<<" open error!"<<endl;
	   exit(1);
	}
	Worker* Whead;
	Worker* temp;
	temp=new Worker;
	if(fin>>newname)
	{
	     temp->setname(newname);
		 fin>>newpassword;
		 temp->setpassword(newpassword);
		 Whead=temp;
		 Worker* temp1;
		 temp1=new Worker;
		 while(fin>>newname>>newpassword)
		 {
		     temp1->setname(newname);
			 temp1->setpassword(newpassword);
			 temp->next=temp1;
			 temp=temp1;
			 temp1=new Worker;
		 }
		 delete temp1;
		 temp->next=NULL;
	}
	else 
	{
	    delete temp;     
	    Whead=NULL;
	}
	fin.close();
	return Whead;
}

Manger* load_manger()//读取管理人员的信息
{
   fstream fin("Manger.txt",ios::in);
   if(!fin)
   {
      cout<<"open error!"<<endl;
	  exit(1);
   }
   Manger* Mhead;
   Manger* temp;
   temp=new Manger;
   string newname;
   string newpassword;
   if(fin>>newname)
   {
	   temp->setname(newname);
	   fin>>newpassword;
	   temp->setpassword(newpassword);
       Mhead=temp;
	   Manger* temp1;
	   temp1=new Manger;
	   while(fin>>newname>>newpassword)
	   {
		   temp1->setname(newname);
		   temp1->setpassword(newpassword);
		   temp->next=temp1;
		   temp=temp1;
		   temp1=new Manger;	   
	   }
	   delete temp1;
	   temp->next=NULL;
   }else
   {
      delete temp;
	  Mhead=NULL;
   }
   fin.close();
   return Mhead;
}


void save_reader(Reader* Rhead)//将读者信息写入文件
{
	fstream fout("reader.txt",ios::out);
	if(!fout)
	{
	     cout<<"open error!"<<endl;
	     exit(1);
	}
	Reader* here=Rhead;
	while(here!=NULL)
	{
		fout<<here->getname()<<" "<<here->getpassword()<<" "<<here->sex<<" "<<here->age<<" "<<here->borrows;
		int a;
		for(a=0;a<here->borrows;a++)
			fout<<" "<<here->borrow[a];
		fout<<endl;
		here=here->next;
	}
	fout.close();
}


void save_worker(Worker* Whead)//将工作人员信息写入文件
{
	fstream fout("worker.txt",ios::out);
	if(!fout)
	{
	    cout<<"open error!"<<endl;
		exit(1);
	}
	Worker* here=Whead;
	while(here!=NULL)
	{
		fout<<here->getname()<<" "<<here->getpassword()<<endl;
		here=here->next;	
	}
	fout.close();
}

void save_book(Book* Bhead)//将书籍信息写入文件
{
    fstream fout("book.txt",ios::out);
	if(!fout)
	{
	    cout<<"open error!"<<endl;
		exit(1);
	}
	Book* t=Bhead;
	while(t!=NULL)
	{
		fout<<t->book_number<<" "<<t->book_name<<" "<<t->book_author<<" "<<t->book_press<<" "<<t->storenum<<" "<<t->borrownum<<endl;
		t=t->next;	
	}
	fout.close();
}

void Encryption()
{
	FILE *fp1, *fp2;
	char ch;
	fp1 = fopen("manger.txt", "r");
	fp2 = fopen("jiamimanger.txt", "w");
	while(1)
	{
		ch = fgetc(fp1);
		ch = 200 - ch;
		if(!feof(fp1))
			fputc(ch, fp2);
		else
			break;
	}
	fclose(fp1);
	fclose(fp2);
}