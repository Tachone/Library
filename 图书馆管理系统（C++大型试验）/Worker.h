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
	void book_borrow(Reader*,Book*);             //借书
	void book_return(Reader*,Book*);			 //还书
	friend Reader* find_reader(string,Reader*);			//查找读者
	void menu_worker_choice(Reader*,Book*);            //工作人员菜单选择
	friend istream& operator >>(istream& ,Worker& ); 
	friend void login_worker(Worker*,Book*,Reader*);//工作人员登陆
	Worker* next;
};

#endif