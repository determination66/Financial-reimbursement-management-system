#pragma once
#include"person.h"
#include"vector.hpp"
#include<string>
using namespace std;
#include<algorithm>
#include<fstream>
#include"allfiles.h"
#include<ctime>

class Progress
{
public:
	
	Progress();

	Progress(int pnum, string num, int money, string date, string state, string dealer);//有参构造

	int m_Pnum;//提单编号

	string m_Num;//工号

	int m_Pmoney;//提单金额

	string m_Date;//提单日期

	string m_State;//状态

	string m_Dealer;//处理人

	vector<Progress>vPro;//信息容器

	void InitVector();//初始化信息

	void ShowPro();//展示所有的报销进度

	string GetDate();//获取当前的日期,自己构造

	int GetVproSize();//获取容器的大小

	int GetVpronum();//获取编号信息

	void SaveVProgress(vector<Progress>p);//存储保存信息

	void ShowConInfo();//根据条件查询报表

	//因为单号只有1个或者0个，所以不需要判断
	//bool IsExist(int Pnum );//根据单号是否存在

	bool IsExist(string num);//根据工号判断存在就true
};