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
	string getname();                      //�õ�����
	string getpassword();                  //�õ�����
	Book* find_book(int,Book*);                 //����ͼ��
	void setname(string);                       //��������
	void setpassword(string );                  //��������
	void search_book(Book*);                    //��ѯͼ����Ϣ
	void search_book_1(Book*);                 //��ѯͼ����Ϣ(���)
	void search_book_2(Book*);                //��ѯͼ����Ϣ(����)
	void print_all_book(Book*);                 //�鿴ȫ��ͼ��

};

#endif