#pragma once
using namespace std;
#include<iostream>
#include<string>
#include"identify.h"
#include"progress.h"
#include"managesystem.h"
#include"aqt.h"

//������Ա����
class Person:public Identify
{
public:
	Person();//Ĭ�Ϲ���

	Person(string num,string id, string password,string rname,string phone);//�вι���

	virtual void OperMenu();//�ع�������ʾ�˵�

	void Oper1Mune();//չʾ�ֲ˵�1

	void Oper3Mune();//չʾ��3

	void ApplyChart();//���뱨��

	void ShowOwnProgress();//��ѯ��չ

	void ShowOwnInfo();//��ѯ������Ϣ

	void ChangeInfo();//�޸���Ϣ

	int PersonFlag();//������Ϣ����Vector���±�

	bool IsProgress();//��ѯ�Ƿ�������Ľ�չ

	bool IsPay();

	void CancelChart();//ȡ������

	void PayMoney();//���ո���

	string  m_Num;//����

	string m_RealName;//��ʵ����

	string m_PhoneNum;//�绰����
};