#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"allfiles.h"//交互文件
#include"identify.h"//身份类头文件
#include"person.h"//报销人员
#include"staff.h"//工作人员
#include"admin.h"//管理员
#include<fstream>//交互文件



class ManageSystem
{
public:
	ManageSystem();

	//显示主菜单
	void ShowMainMenu();

	//登录界面
	void Login(int type);

	//分页面用于用户选择是否有账号
	void MSOperMenu(int num);
	
	//创建一个账号
	void Create(int num);

};