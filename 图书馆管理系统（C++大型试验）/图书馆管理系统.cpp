#include <iostream>
#include <stdio.h>
#include "Menu.h"
#include "File.h"
using namespace std;

int main()
{   //�����ݶ������
	Book* Bhead=load_book();            
	Reader* Rhead=load_reader();
	Worker* Whead=load_worker();
	Manger* Mhead=load_manger();
	Encryption();//���ܹ���Ա
	int number=0;
	while (number!=5)
	{
		menu_system();
		cin>>number;
		switch (number)
		{
		case 1:
			{
				login_reader(Rhead,Bhead);//���ߵ�¼
				break;
			}
		case 2:
		   {
			   login_worker(Whead,Bhead,Rhead);//������Ա��¼
			   break;
		   }	
		case 3:{
			   login_manger(Mhead,Bhead,Rhead,Whead);//������Ա��¼
			   break;
			   }
		case 4:
			{
			  register_reader(Rhead);//ע�����
			  break;
			}
		
		}

	}
	system("cls");//����
	//��������
	save_book(Bhead);
	save_reader(Rhead);
	save_worker(Whead);

	//cout<<"��Ϣ�ѱ��棡"<<endl;
	cout<<"���˳���лл����ʹ�ã�"<<endl;
	system("pause");
return 0;
}