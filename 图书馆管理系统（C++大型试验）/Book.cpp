#include <iostream>
#include <iomanip>
#include "Book.h"
#include <string>

using namespace std;

Book::Book(){}

void Book::output ()  //��ʾͼ����Ϣ
{
    cout<<"              ��ţ�"<<book_number<<endl;
	cout<<"              ������"<<book_name<<endl;
	cout<<"              ���ߣ�"<<book_author<<endl;
	cout<<"              �����磺"<<book_press<<endl;

}

ostream& operator <<(ostream& outs,const Book& b)  //������������������Ϣ
{
	outs<<setw(10)<<b.book_number<<setw(25)<<b.book_name<<setw(11)<<b.book_author<<setw(23)<<b.book_press;
	if (b.storenum>b.borrownum)
	{
		outs<<"  �ɽ���\n"<<endl;
	}
	else
	{
		outs<<"  �ѽ���\n";
	}
	return outs;
}


istream& operator >>(istream& ins,Book& b)	  //�������룬���뵥��������Ϣ
{
	cout<<"��������";
	ins>>b.book_name;
	cout<<"��������";
	ins>>b.book_author;
	cout<<"���������";
	ins>>b.book_press;
	cout<<"���������";
	ins>>b.storenum;
	b.borrownum=0;
	return ins;
}
