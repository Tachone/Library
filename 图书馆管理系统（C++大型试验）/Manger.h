#ifndef MANGER_H
#define MANGER_H

#include "Worker.h"
#include "People.h"
class Manger : public People
{
public:
	Manger();
	Worker* find_worker(string ,Worker*);
	void menu_manger_choice(Worker*,Book*,Reader*);    //管理人员菜单选择
	void update_book(Book*);    //更新图书
    void update_add_book(Book*);     //添加图书
	void update_change_book(Book*);    //更改图书信息
	void update_delete_reader(string,Reader*);      //删除读者
	void update_reader(Reader*);    //更新读者
	void update_worker(Worker*);    //更新工作人员
	void update_add_worker(Worker*);      //添加工作人员
	void update_delete_worker(Worker*);     //删除工作人员
	friend void login_manger(Manger*,Book*,Reader*,Worker*);       //管理人员登录
	Manger* next;
};

#endif