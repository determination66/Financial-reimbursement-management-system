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
	ArlTable();//���캯��

	int m_key;//���

	string m_Role;//��ɫ

	int m_Money;//���

	string m_Num;//���ţ������ж����ĸ�������Ա

	 //��������Ȩ��ȱ�
	vector<ArlTable>vAT;

	void InitVAT();//��Ȩ��ȱ�

	void ShowInfo();//չʾ��Ϣ

	int GetVATSize();//��ȡ�����Ĵ�С

	int GetVATnum();//��ȡ����ʱ�����Ϣ

	void SaveVAT(vector<ArlTable>p);//�洢������Ϣ

	void AddVAT(string role,int money,string num);//������Ȩ����Ϣ
};