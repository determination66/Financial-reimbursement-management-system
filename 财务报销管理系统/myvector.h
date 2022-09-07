#pragma once
#include<iostream>
using namespace std;
#include"vector.hpp"
#include"allfiles.h"
#include<fstream>
#include"identify.h"
#include"admin.h"
#include"person.h"
#include"staff.h"

class MyVector
{
public:
	//报销人员信息容器
    vector<Person>vPer;

    //工作人员信息容器
    vector<Staff>vSta;

    //管理员信息容器
     vector<Admin>vAdm;

     //初始化容器
     void InitVPer();//报销人员

     void InitVSta();//审批人员

     void InitVAdm();//管理员

     bool IsRepeat(string username, int type);//判断重复与否

     void SaveVPer(vector<Person>p);//存储报销人员信息

     void SaveVSta(vector<Staff>p);//存储审批人员信息

     void SaveVAdm(vector<Admin>p);//存储管理员信息

     int GetRNum();//创建授权信息是获取编号

     void Showid(int type);//展示已有工号
};