#ifndef DBFILE_H
#define DBFILE_H
 
#include "Reader.h"
#include "Book.h"
#include "Worker.h"
#include "Manger.h"

Book* load_book();                               //��ȡ�������
void save_book(Book*);                           //�洢�������

Reader* load_reader();                           //��ȡ���ߵ�����
void save_reader(Reader*);                       //�洢���ߵ�����

Worker* load_worker();                           //��ȡ������Ա������
void save_worker(Worker*);                       //�洢������Ա������

Manger* load_manger();                           //��ȡ������Ա������

void Encryption();                               //����


#endif