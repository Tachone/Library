#ifndef WORKER_H
#define WORKER_H

#include "Reader.h"
#include "People.h"
#include <iostream>

using namespace std;

class Worker :public People
{
public:
	Worker();
	void book_borrow(Reader*,Book*);             //����
	void book_return(Reader*,Book*);			 //����
	friend Reader* find_reader(string,Reader*);			//���Ҷ���
	void menu_worker_choice(Reader*,Book*);            //������Ա�˵�ѡ��
	friend istream& operator >>(istream& ,Worker& ); 
	friend void login_worker(Worker*,Book*,Reader*);//������Ա��½
	Worker* next;
};

#endif