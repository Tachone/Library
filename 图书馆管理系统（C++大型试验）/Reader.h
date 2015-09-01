#ifndef READER_H
#define READER_H

#include "People.h"

class Reader  :public People   
{
public:
	Reader();
	void show_reader();            //显示读者信息
	void change_reader();               //更改读者信息
	void menu_reader_choice(Book*);          //读者选择菜单
	void show_borrows(Book*);             //显示个人借阅信息
	friend void register_reader(Reader*);               //读者注册
	friend void login_reader(Reader*,Book*);           //读者登录
	friend bool find_reader_if(string,Reader*);                        //查找是否存在名为name的读者
	Reader* next;                 //链表指针
	int age;                     //读者年龄
	int borrow[8];				 //读者借阅书的书号
	int borrows;				 //读者借阅的数目
	string sex;					 //读者性别
	
};

#endif