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

	//�������������˵�
	virtual void OperMenu();

	void Oper1Menu();	//չʾ�ֲ˵�1����Ϣ

	string  m_Num;//����

	string m_RealName;//��ʵ����

	string m_PhoneNum;//�绰����

	int  m_role;//ְ��

	string GetRole();//����ְ��

	int GetCheckMoney();//�����������Ȩ

	void ShowAdminInfo();//��ѯ����Ա��Ϣ

	void ShowPersonInfo();//��ѯ������Ա��Ϣ

	void ShowStaffInfo();//��ѯ������Ա��Ϣ

	void ShowApproval();//չʾ��������Ա����Ϣ,ֻչʾ��ȷ�Χ�ڵ�������Ϣ

	void AprovePerson();//����

	bool IsExistAprove();//�ж��Ƿ����������Ϣ

	void ChangeInfo();//�޸ĸ�����Ϣ

	void ShowOwnInfo();//��ѯ������Ϣ
};