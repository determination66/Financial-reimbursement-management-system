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
	//������Ա��Ϣ����
    vector<Person>vPer;

    //������Ա��Ϣ����
    vector<Staff>vSta;

    //����Ա��Ϣ����
     vector<Admin>vAdm;

     //��ʼ������
     void InitVPer();//������Ա

     void InitVSta();//������Ա

     void InitVAdm();//����Ա

     bool IsRepeat(string username, int type);//�ж��ظ����

     void SaveVPer(vector<Person>p);//�洢������Ա��Ϣ

     void SaveVSta(vector<Staff>p);//�洢������Ա��Ϣ

     void SaveVAdm(vector<Admin>p);//�洢����Ա��Ϣ

     int GetRNum();//������Ȩ��Ϣ�ǻ�ȡ���

     void Showid(int type);//չʾ���й���
};