#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "Book.h"

class People
{
private:
	string name;
	string  password;
public:
	People();
	string getname();                      //得到名字
	string getpassword();                  //得到密码
	Book* find_book(int,Book*);                 //查找图书
	void setname(string);                       //设置名字
	void setpassword(string );                  //设置密码
	void search_book(Book*);                    //查询图书信息
	void search_book_1(Book*);                 //查询图书信息(书号)
	void search_book_2(Book*);                //查询图书信息(书名)
	void print_all_book(Book*);                 //查看全部图书

};

#endif