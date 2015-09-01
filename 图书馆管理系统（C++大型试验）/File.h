#ifndef DBFILE_H
#define DBFILE_H
 
#include "Reader.h"
#include "Book.h"
#include "Worker.h"
#include "Manger.h"

Book* load_book();                               //读取书的数据
void save_book(Book*);                           //存储书的数据

Reader* load_reader();                           //读取读者的数据
void save_reader(Reader*);                       //存储读者的数据

Worker* load_worker();                           //读取工作人员的数据
void save_worker(Worker*);                       //存储工作人员的数据

Manger* load_manger();                           //读取管理人员的数据

void Encryption();                               //加密


#endif