#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book
{
public:
	Book();
	void output();
	friend ostream& operator <<(ostream& ou,const Book& b);                //�������룬���������Ϣ
	friend istream& operator >>(istream& in,Book& b);                      //������������������Ϣ
	long book_number;                                                               //���
	string book_name;	                                                       //����
	string book_author;	                                                   //����
	string book_press;	                                                       //������
	int storenum;	                                                       //�ݲ�����
	int borrownum;                                                     	   //�����
	Book* next;	                                                           //����ָ��
};

#endif
 