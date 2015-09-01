#include "Worker.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include "Menu.h"
#include "File.h"
#include <stdlib.h>


Worker::Worker(){}

void Worker::book_borrow(Reader* Rhead,Book* Bhead)//����
{
    string name;
	Reader* rhere;
	int a=0;
	while (a==0)
	{
	   system("cls");
	   cout<<"��������ߵ��û�����";
	   cin>>name;
	   rhere=find_reader(name,Rhead);
	   if(rhere==NULL)
	   {
	      cout<<"�Բ���û�и��û���"<<endl;
		  cout<<"����������"<<endl;
		  Sleep(500);//��ͣ0.5��
	   }
	   if(rhere!=NULL)
	   {
	      cout<<"�Ѳ��ҵ����û�"<<endl;
		  cout<<"���������"<<endl;
		  Sleep(700);
		  break;
	   }	
	}
	int num;
	Book* bhere;
	while(a==0)
	{     
		 system("cls");
	     cout<<"��������Ҫ���ĵ�ͼ�����ţ�";
         cin>>num;	    
	     bhere=find_book(num,Bhead);
		 if(bhere==NULL)
		 {
		     cout<<"��Ǹ��û����Ҫ���ĵ�ͼ��"<<endl;
			 cout<<"�����������룺"<<endl;
			 Sleep(700);
		 }
	     if(bhere!=NULL)
		 {
			 
			 break;	
		 }
	}
	bhere=find_book(num,Bhead);
	if (bhere->borrownum==bhere->storenum)  //�ж�ͼ���Ƿ���Խ���
	     {
			cout<<"�Բ�����Ҫ���ĵ�ͼ���ѽ���"<<endl;
	        Sleep(500);
	     }
			 else if(rhere->borrows<5)
			 {
				bhere->borrownum++;
				rhere->borrow[rhere->borrows++]=bhere->book_number;
				rhere->show_borrows(Bhead);////////�¼Ӵ���
				cout<<"����ɹ���"<<endl;
				save_book(Bhead);
				save_reader(Rhead);
				system("pause");
			 }
			else
				{
				cout<<"�ö����ѽ���ͼ��"<<endl;
				system("pause");
				}
}

Reader* find_reader(string name,Reader* Rhead)//����Ԫ������ ���Ҷ���
{
    Reader* here=Rhead;
	while (here!=NULL)
	{
		if(name==here->getname())
		   return here;
		here=here->next;	
	}
	cout<<"�Բ���û�и��û���";
	return NULL;
}

void Worker::book_return(Reader* Rhead,Book* Bhead)  //����
{
    string name;
	Reader* rhere;
start:
	int flag=0;
	do
	{
		if (flag++) cout<<"\n\n\n\t\t\tû�и��û�!\n����������\n";
		Sleep(500); 
		system("cls");
		cout<<"\n\n\n\t\t\t��������û���:";
		cin>>name;
		rhere=find_reader(name,Rhead);
	} while (rhere==NULL);	                                         //�ж��Ƿ���ڸö���
	int no;
	Book* bhere;
	flag=0;
	do
	{
		if (flag++) cout<<"\n\n\n\t\t\tû�и���!\n\t\t\t����������\n\t\t\t";
		Sleep(500);  system("cls");
		cout<<"�ö����ѽ���Ŀ:\n";
		rhere->show_borrows(Bhead);
		cout<<"\n\n����Ҫ�����:";
		cin>>no;
		bhere=find_book(no,Bhead);
	} while (bhere==NULL);	                                         //�ж��Ƿ���ڸ���	
	int c=0;
	while (rhere->borrow[c]!=bhere->book_number && c<rhere->borrows) 
		c++;
	if (c==rhere->borrows) 
	{ 
		cout<<"\n\n\n\t\t\t�ö���δ���Ȿ��\n";                   	 //δ������
		int command=0;
		cout<<"\t\t\t�Ƿ���������:(������1��������0):\n\t\t\t";
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
	cout<<"\n\n\n\t\t\t����ɹ�\n";

	bhere->borrownum--;
	save_book(Bhead);
	save_reader(Rhead);
	system("pause");
}

void login_worker(Worker* Whead,Book* Bhead,Reader* Rhead)  //������Ա��¼
{
     string name;
	 string password;
 begin2:
	 system("cls");
	 cout<<"�����������û�����";
	 cin>>name;
	 cout<<"���������룺";
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
			    cout<<"�Բ��������������"<<endl;
				cout<<"�Ƿ��������룿������1���ǣ�����0����"<<endl;
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
		 cout<<"�Բ����û��������ڣ�"<<endl;
		 cout<<"�Ƿ��������룿������1���ǣ�����0����"<<endl;
		 cin>>a;
		 if(a==1)
			 goto begin2;
		 else return;	 
	 }
}

void Worker::menu_worker_choice(Reader* Rhead,Book* Bhead)  //������Ա�˵�ѡ��
{
    int choice=0;
	while (choice!=5)
	{
start1:
		menu_worker();
		cin>>choice;
		if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
		{
		    cout<<"�Բ��������������"<<endl;
			cout<<"���������룺"<<endl;
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
			   cout<<"������Ҫ��ѯ�Ķ��ߵ��û�����"<<endl;
			   cin>>name;
			   Reader* here=find_reader(name,Rhead);
			   here->show_reader();
			   cout<<"�ö��߽�����Ϣ��"<<endl;
			   here->show_borrows(Bhead);  //��ʾ���ߵĽ�����Ϣ
			   system("pause");
			   break;
			}
		}
	}
}

istream& operator >>(istream& in,Worker& Whead)  //">>"����������
{
    string name;
	string password;
	cout<<"�������û�����"<<endl;
	in>>name;
	Whead.setname(name);
	cout<<"���������룺"<<endl;
	in>>password;
	Whead.setpassword(password);
	return in;
}