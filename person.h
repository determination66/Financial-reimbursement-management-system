#pragma once
using namespace std;
#include<iostream>
#include<string>
#include"identify.h"
#include"progress.h"
#include"managesystem.h"
#include"aqt.h"

//报销人员的类
class Person:public Identify
{
public:
	Person();//默认构造

	Person(string num,string id, string password,string rname,string phone);//有参构造

	virtual void OperMenu();//重构函数显示菜单

	void Oper1Mune();//展示分菜单1

	void Oper3Mune();//展示分3

	void ApplyChart();//申请报表

	void ShowOwnProgress();//查询进展

	void ShowOwnInfo();//查询个人信息

	void ChangeInfo();//修改信息

	int PersonFlag();//返回信息所在Vector的下标

	bool IsProgress();//查询是否有申请的进展

	bool IsPay();

	void CancelChart();//取消报表

	void PayMoney();//最终付款

	string  m_Num;//工号

	string m_RealName;//真实姓名

	string m_PhoneNum;//电话号码
};