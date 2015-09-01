#ifndef READER_H
#define READER_H

#include "People.h"

class Reader  :public People   
{
public:
	Reader();
	void show_reader();            //��ʾ������Ϣ
	void change_reader();               //���Ķ�����Ϣ
	void menu_reader_choice(Book*);          //����ѡ��˵�
	void show_borrows(Book*);             //��ʾ���˽�����Ϣ
	friend void register_reader(Reader*);               //����ע��
	friend void login_reader(Reader*,Book*);           //���ߵ�¼
	friend bool find_reader_if(string,Reader*);                        //�����Ƿ������Ϊname�Ķ���
	Reader* next;                 //����ָ��
	int age;                     //��������
	int borrow[8];				 //���߽���������
	int borrows;				 //���߽��ĵ���Ŀ
	string sex;					 //�����Ա�
	
};

#endif