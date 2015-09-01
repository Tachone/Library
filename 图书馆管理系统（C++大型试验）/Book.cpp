#include <iostream>
#include <iomanip>
#include "Book.h"
#include <string>

using namespace std;

Book::Book(){}

void Book::output ()  //显示图书信息
{
    cout<<"              书号："<<book_number<<endl;
	cout<<"              书名："<<book_name<<endl;
	cout<<"              作者："<<book_author<<endl;
	cout<<"              出版社："<<book_press<<endl;

}

ostream& operator <<(ostream& outs,const Book& b)  //重载输出，输出藏书信息
{
	outs<<setw(10)<<b.book_number<<setw(25)<<b.book_name<<setw(11)<<b.book_author<<setw(23)<<b.book_press;
	if (b.storenum>b.borrownum)
	{
		outs<<"  可借阅\n"<<endl;
	}
	else
	{
		outs<<"  已借完\n";
	}
	return outs;
}


istream& operator >>(istream& ins,Book& b)	  //重载输入，输入单本藏书信息
{
	cout<<"输入书名";
	ins>>b.book_name;
	cout<<"输入作者";
	ins>>b.book_author;
	cout<<"输入出版社";
	ins>>b.book_press;
	cout<<"输入藏书量";
	ins>>b.storenum;
	b.borrownum=0;
	return ins;
}
