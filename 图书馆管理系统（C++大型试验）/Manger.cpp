#include "Manger.h"
#include "Book.h"
#include "Menu.h"
#include "File.h"
#include "Worker.h"
#include <windows.h>
#include <conio.h>

Manger::Manger(){}

Worker* Manger::find_worker(string name,Worker* Whead)  //���ҹ�����Ա 
{
     Worker* here=Whead;
	 while(here!=NULL)
	 {
		 if(name==here->getname())
		     return here;
		 here=here->next;
	 }
	 cout<<"�Բ���û�и��û���";
	 return NULL;
}

void Manger::menu_manger_choice(Worker* Whead,Book* Bhead,Reader* Rhead)  //������Ա�˵�ѡ��
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
		    cout<<"�Բ��������������"<<endl;
			cout<<"���������룺"<<endl;
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
			     search_book(Bhead);  //��ѯͼ��
				 break;
			 }
		 case 2:
			 {
			     update_book(Bhead);  //����ͼ��
			     break;
			 }
		 case 3:
			 {
			     update_reader(Rhead);  //���¶���
				 break;
			 }
		 case 4:
			 {
			     update_worker(Whead);  //���¹�����Ա
				 break;
			 }
		 }
	 }
}

void Manger::update_book(Book* Bhead)  //����ͼ��
{
  int choice=0;
  while (choice!=4)
  {
begin:
	  menu_update_book();
	  cin>>choice;
	  if(choice!=1&&choice!=2&&choice!=3)
	  {
	      cout<<"�Բ����������"<<endl;
		  cout<<"����������"<<endl;
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
		     update_add_book(Bhead);  //����ͼ��
			 break;		  
		  }
	  case 2:
		  {
		     update_change_book(Bhead);  //�޸�ͼ����Ϣ
			 break;
		  }
	  }
  }
}

void Manger::update_add_book(Book* Bhead)  //����ͼ��
{
    Book* here=Bhead;
	while(here->next!=NULL) //�������������
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
		cout<<"��ӳɹ���"<<endl;
		Sleep(500);
		cin>>command;
	}
	temp->next=NULL;
	save_book(Bhead);
}

void Manger::update_change_book(Book* Bhead)  //�޸��鱾��Ϣ
{
	int choice=0;
	while (choice!=5)
	{
begin:
		menu_change_book();
		cin>>choice;
		if (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
		{
			cout<<"�������!\n���������룺\n";
			Sleep(500);
			goto begin;
		}
		if (choice==5) return;
start:
		system("cls");
		int number;
		cout<<"�������:\n";
		cin>>number;
		Book* here=find_book(number,Bhead);
		if (here==NULL) goto start;

		switch (choice)
		{
		case 1:
			{
				system("cls");
				cout<<"ԭ���� "<<here->book_name<<endl;
				cout<<"����������\n";
				cin>>here->book_name;
				break;
			}
		case 2:
			{
				system("cls");
				cout<<"ԭ���� "<<here->book_author<<endl;
				cout<<"����������\n";
				cin>>here->book_author;
				break;
			}
		case 3:
			{
				system("cls");
				cout<<"ԭ�ݲ����� "<<here->storenum<<endl;
				cout<<"�����µĹݲ�����\n";
			    
					cin>>here->storenum;
				break;
			}
		case 4:
			{
				system("cls");
				cout<<"ԭ������ "<<here->book_press<<endl;
				cout<<"�����³�����\n";
				cin>>here->book_press;
				break;
			}
		}
		cout<<"�޸ĳɹ�!\n";
		Sleep(500);
		save_book(Bhead);
	}
}

void login_manger(Manger* Mhead,Book* Bhead,Reader* Rhead,Worker* Whead)     //������Ա��¼
{
    string name;
	string password;
begin:
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
				cout<<"�Բ��������������"<<endl;
				cout<<"�Ƿ��������룿������1���ǣ�����0����"<<endl;
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
	   cout<<"�Բ��𣬸��û������ڣ�"<<endl;
	   cout<<"\t\t\t�Ƿ���������?(������1����������0)\n";
	   cin>>command;
	   if (command==1) 
		   goto begin; 
	   else 
		   return;
	}
}

void Manger::update_delete_reader(string name,Reader* Rhead)  //ɾ������
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

void Manger::update_reader(Reader* Rhead)  //���¶���
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
		    cout<<"�Բ����������"<<endl;
			cout<<"���������룺"<<endl;
		    Sleep(700);
			goto begin2;
		}
	    if(choice==5)
			return;
		
start2:		
		system("cls");
		cout<<"��������ߵ��û���"<<endl;
		cin>>name;
		Reader* rhere=find_reader(name,Rhead);
	    if(rhere==NULL)
		goto start2;
		
        switch(choice)
		{
		case 1:
		    {
		       system("cls");
			   cout<<"���������䣺"<<endl;
			   cin>>rhere->age;			  
			   break;
		    }
		case 2:
			{
			   system("cls");
			   cout<<"�����Ա�����1���У�����0��Ů��"<<endl;
			   int s;
			   cin>>s;
			   if(s==1)
				   rhere->sex="��";
			   else if(s==0)
				   rhere->sex="Ů";
			   else 
				   cout<<"�������"<<endl;
			   
			   break;
			}
		case 3:
			{
			    system("cls");
				cout<<"���������룺"<<endl;
				string password;
				cin>>password;
				rhere->setpassword(password);
				
				break;
			}
		case 4:
			{
               system("cls");
			   update_delete_reader(name,Rhead);
			   cout<<"ɾ���ɹ���"<<endl;
			   Sleep(600);
			   save_reader(Rhead);
			   return;
			   break;

			}
		}
		cout<<"�޸ĳɹ���"<<endl;
		Sleep(500);
		save_reader(Rhead);
		}
	}

void Manger::update_worker(Worker* Whead)  //���¹�����Ա
{
	int choice;
start3:
	menu_change_worker();
	cin>>choice;
	if(choice!=1 && choice!=2 && choice!=3)
	{
	    cout<<"�Բ��������������";
		Sleep(700);
	    goto start3;	
	}
	if(choice==3)
		return;
	switch(choice)
	{
	case 1:
		{
           update_add_worker(Whead); //��ӹ�����Ա
		   save_worker(Whead);
		   break;
		}
	case 2:
		{
		   update_delete_worker(Whead);  //ɾ��������Ա
		   save_worker(Whead);
		   break;
		}
	}
	cout<<"�޸ĳɹ���"<<endl;
	Sleep(700);
}

void Manger::update_add_worker(Worker* Whead)  //���ӹ�����Ա
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
	   cout<<"�Ƿ������ӣ�������1���ǣ�����2����"<<endl;
	   cin>>command;
	   Sleep(500);
       system("cls");
   }
   temp->next=NULL;
}

void Manger::update_delete_worker(Worker* Whead)   //����������Ա
{
	string  name;
start2:
	system("cls");
	cout<<"�����빤����Ա���û���\n";
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

