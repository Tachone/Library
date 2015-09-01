#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book
{
public:
	Book();
	void output();
	friend ostream& operator <<(ostream& ou,const Book& b);                //重载输入，输入藏书信息
	friend istream& operator >>(istream& in,Book& b);                      //重载输出，输出藏书信息
	long book_number;                                                               //书号
	string book_name;	                                                       //书名
	string book_author;	                                                   //作者
	string book_press;	                                                       //出版社
	int storenum;	                                                       //馆藏书量
	int borrownum;                                                     	   //借出量
	Book* next;	                                                           //链表指针
};

#endif
 