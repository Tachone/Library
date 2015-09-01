#ifndef MANGER_H
#define MANGER_H

#include "Worker.h"
#include "People.h"
class Manger : public People
{
public:
	Manger();
	Worker* find_worker(string ,Worker*);
	void menu_manger_choice(Worker*,Book*,Reader*);    //������Ա�˵�ѡ��
	void update_book(Book*);    //����ͼ��
    void update_add_book(Book*);     //���ͼ��
	void update_change_book(Book*);    //����ͼ����Ϣ
	void update_delete_reader(string,Reader*);      //ɾ������
	void update_reader(Reader*);    //���¶���
	void update_worker(Worker*);    //���¹�����Ա
	void update_add_worker(Worker*);      //��ӹ�����Ա
	void update_delete_worker(Worker*);     //ɾ��������Ա
	friend void login_manger(Manger*,Book*,Reader*,Worker*);       //������Ա��¼
	Manger* next;
};

#endif