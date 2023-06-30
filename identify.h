#pragma once
#include<iostream>
using namespace std;
#include <string>

class Identify
{
public:
	//每个类的抽象函数，操作菜单
	virtual void OperMenu() = 0;

	string m_Id;//用户名

	string m_Password;//密码
};