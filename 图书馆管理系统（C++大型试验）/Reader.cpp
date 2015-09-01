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

void Reader::show_reader()//��ʾ���߻�����Ϣ
{
	cout<<"\t\t ������"<<getname()<<endl;
	cout<<"\t\t �Ա�"<<sex<<endl;
	cout<<"\t\t ���䣺"<<age<<endl;

}

void login_reader(Reader* Rhead , Book* Bhead)//���ߵ�¼
{

	int f=0;
	string name;
	string  password;
	Reader* here=Rhead;
start1:
	system("cls");
	cout<<"                 \n\n\n�������û�����";
	cin>>name;
	cout<<"                 \n\n\n���������룺";
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
		if(name==here->getname())//����������������Ҫ��
		{
		     if (here->getpassword()==password)
			 {
			       here->menu_reader_choice(Bhead);
				   return;
			 }else 
			 {
			    f=1;
				int command;
				cout<<"             \n\n\n�������";
				cout<<"             \n\n\n�Ƿ���������\n           1���� ��0����"<<endl;
				cin>>command;
				if(command==1)
					goto start1;//goto��䣬������start1��
				else return;
			 }
		}
		here=here->next;
	}   
	if (f==0)
	{
		int command=0;
		cout<<"\n\n\n\t\t\t���û�������!\n";
		cout<<"\t\t\t�Ƿ���������?(������1����������0)\n";
		cin>>command;
		if (command==1) goto start1; 
		else return;
		return;
	}

}

void Reader::menu_reader_choice(Book* Bhead)//���߲˵�ѡ��
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
			cout<<"�������!\n���������룺\n";
			Sleep(500);
			goto start2;
		}
		if(choice==5)
			return;
		Sleep(500);
		system("cls");
		switch (choice)
		{
			case 1:                                                       //���ҹݲ���Ŀ 
			{
				search_book(Bhead);
				break;
			}
			case 2:                                                       //�鿴���˽�����Ϣ 
			{
				show_borrows(Bhead);
				system("pause");
				break;
			}
			case 3:                                                       //�޸ĸ�����Ϣ��
			{
				change_reader();
				break;
			}
			case 4:                                                       //�鿴������Ϣ��
			{
				show_reader();
				system("pause");
				break;
			}
			
		}
	}
}

void Reader::show_borrows(Book* Bhead)//��ʾ���߽�����Ϣ
{
	cout<<setw(12)<<"�ݲ����"<<setw(25)<<"����"<<setw(9)<<"����"<<setw(30)<<"������\n";
	int c;
	for (c=0;c<borrows;c++){
		cout<<(*find_book(borrow[c],Bhead));//����������
	}
}

void Reader::change_reader()//�޸Ķ�����Ϣ
{
    int choice=0;
	while (choice!=5)
	{
start1:
		menu_change_reader();
		cin>>choice;
		if (choice!=1 && choice!=2 && choice!=3 && choice!=4)
		{
			cout<<"�������!\n����������:\n";
			Sleep(500);
			goto start1;
		}
		if (choice==4) return;
		switch (choice)
		{
			case 1:
			{
				system("cls");
				cout<<"����������\n";
				cin>>age;
				break;
			}
			case 2:
			{
				system("cls");
				cout<<"�������Ա�(������1��Ů����0)\n";
				int s;
				cin>>s;
				if(s==1){
					sex="��";
				}else 
				if(s==0){ 
					sex="Ů"; 
				}
				else cout<<"�������\n";
				break;
			}
			case 3:
			{
				system("cls");
				cout<<"������������\n";
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
		cout<<"�޸ĳɹ�!\n";
		Sleep(500);
	}
}

void register_reader(Reader* Rhead)//ע�����
{
     string name;
	 system("cls");
	 int flag=0;//��ʶ��
	 do
	 {
	    if(flag++)
			cout<<"���û����ѱ�ע�ᣬ���������룡"<<endl;
		Sleep(700);
		system("cls");
		cout<<"�����������û�����"<<endl;
		cin>>name;
	 }while(find_reader_if(name,Rhead));//�ж��Ƿ��д˶���
	 Reader* here=Rhead;
	 while (here->next!=NULL)
		 here=here->next;//�������������
	 Reader* new_reader;
	 new_reader=new Reader;
	 new_reader->setname(name);
	 cout<<"�������������룺"<<endl;
	 string password;
	 cin>>password;
	 new_reader->setpassword(password);
	 cout<<"�������������䣺"<<endl;
	 cin>>new_reader->age;
	 cout<<"�����������Ա�����1���У�����0��Ů��"<<endl;
	 int s;
	 cin>>s;
	 do
	 {
	    if (s==1)
			new_reader->sex="��";
		else if(s==0)
			new_reader->sex="Ů";
		else
			cout<<"����������������룡"<<endl;
	 }while(s==1&&s==0);
	 new_reader->borrows=0;
	 here->next=new_reader;
	 new_reader->next=NULL;
	 save_reader(Rhead);//��������
	 cout<<"ע��ɹ���"<<endl;
	 system("pause");
}

bool find_reader_if(string name,Reader* Rhead)//�����Ƿ������Ϊname�Ķ���
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

