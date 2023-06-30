#pragma once
#include<iostream>
#include<string>
using namespace std;
#include<string>
#include"identify.h"
#include"vector.hpp"
#include"managesystem.h"
#include"progress.h"
#include"admin.h"


class Staff :public Identify
{
public:
	Staff();

	Staff(string num,string id,string password,string rname,string phonenum,int role);

	//抽象函数，操作菜单
	virtual void OperMenu();

	void Oper1Menu();	//展示分菜单1的信息

	string  m_Num;//工号

	string m_RealName;//真实姓名

	string m_PhoneNum;//电话号码

	int  m_role;//职责

	string GetRole();//返回职责

	int GetCheckMoney();//返回最大额度授权

	void ShowAdminInfo();//查询管理员信息

	void ShowPersonInfo();//查询报销人员信息

	void ShowStaffInfo();//查询审批人员信息

	void ShowApproval();//展示待审批人员的信息,只展示额度范围内的所有信息

	void AprovePerson();//审批

	bool IsExistAprove();//判断是否存在审批信息

	void ChangeInfo();//修改个人信息

	void ShowOwnInfo();//查询个人信息
};