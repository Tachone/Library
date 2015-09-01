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

void People::search_book(Book* Bhead)//��ѯͼ��
{
	int choice=0;
	while(choice!=3)
	{
       menu_search_book();//��ʾ���ҽ��溯��
	   cin>>choice;
	   if(choice==4) 
		   return;
	   else if(choice==1)
		   search_book_1(Bhead);//ʹ��ͼ��Ų�ѯͼ��
	   else if(choice==2)
		   search_book_2(Bhead);//ʹ��ͼ������ѯͼ��
	   else if(choice==3)
		   print_all_book(Bhead);//�鿴����ͼ��
	   else 
		   cout<<"�������\n����������"<<endl;
	    system("pause");
	}
}

void People::search_book_1(Book* Bhead)//��ͼ��Ų�ѯͼ�麯��
{
    int number;//ͼ���
	int find;//��ʶ��
	int choice=1;
	while(choice)
	{
	   Book* here=Bhead;
	   find=0;
	   system("cls");
	   cout<<"��������Ҫ��ѯ��ͼ�����ţ�";
	   cin>>number;
	   while(here!=NULL)
	   {
	        if(here->book_number==number)
			{
			    here->output();//��ӡҪ��ѯ��ͼ����Ϣ
				find=1;//�޸ı�ʶ��
				break;
			}
			here=here->next;	   
	   }
	   if(find==0)
		   cout<<"�Բ���������ѯ��ͼ�鲻���ڡ�\n";
		   cout<<"�������ѯ������1���˳�������0\n";
		   cin>>choice;
	       if (choice==0)
			   return;
	}

}

void People::search_book_2(Book* Bhead)//��ͼ������ѯͼ��
{
	int find=0;//��ʶ��
	int choice=1;
	string bookname;	
	while(choice)
	{
	Book* here=Bhead;
	system("cls");
	cout<<"��������Ҫ��ѯ��ͼ���������";
	cin>>bookname;
	while(here!=NULL)
	{
		int temp = here->book_name.find(bookname);//ģ����ѯ
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
		   cout<<"�Բ���������ѯ��ͼ�鲻���ڡ�\n";
		   cout<<"�������ѯ������1���˳�������0\n";
	       cin>>choice;		
	}

}

void People::print_all_book(Book* Bhead)//��ӡ����ͼ����Ϣ
{
    system("cls");
	Book* here=Bhead;
	cout<<setw(10)<<"���"<<setw(20)<<"����"<<setw(15)<<"����"<<setw(20)<<"������"<<"     �������\n"<<endl;
	while(here!=NULL)
	{
	    cout<<(*here);//����������
		here=here->next;
	
	}
	
}

Book* People::find_book(int number,Book* Bhead)     //��ѯͼ��       
{
	Book* here=Bhead;
	while (here!=NULL)
	{
		if (here->book_number==number)
			return here;
		here=here->next;
	}
	cout<<"û�и���!\n";
	return NULL;
}

