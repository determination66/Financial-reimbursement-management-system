#pragma once
#include<iostream>
#include"vector.hpp"
#include<string>
using namespace std;
#include<algorithm>
#include<fstream>
#include"allfiles.h"
#include"aqt.h"

class ArlTable
{
public:
	ArlTable();//构造函数

	int m_key;//编号

	string m_Role;//角色

	int m_Money;//额度

	string m_Num;//工号，用于判断是哪个审批人员

	 //审批人授权额度表
	vector<ArlTable>vAT;

	void InitVAT();//授权额度表

	void ShowInfo();//展示信息

	int GetVATSize();//获取容器的大小

	int GetVATnum();//获取创建时编号信息

	void SaveVAT(vector<ArlTable>p);//存储保存信息

	void AddVAT(string role,int money,string num);//增加授权表信息
};