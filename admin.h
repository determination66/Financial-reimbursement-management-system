#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"identify.h"
#include"allfiles.h"
#include"managesystem.h"
#include"progress.h"
#include"aqt.h"

class Admin:public Identify
{
public:

	Admin();

	Admin(string id, string password);

	//抽象函数，操作菜单
	void OperMenu();

    //添加账号
	void AddPerson();

	//查询管理员信息
	void ShowAdminInfo();

	//查询报销人员信息
	void ShowPersonInfo();

	//查询审批人员信息
	void ShowStaffInfo();

	//展示查询信息1的分界面
	void Oper1Menu();

	//展示删除信息3的分页面
	void Oper4Menu();

	//删除人员信息
	void DeletePerson(int type);
};