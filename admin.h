#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"identify.h"
#include"allfiles.h"
#include"managesystem.h"
#include"progress.h"
#include"aqt.h"

class Admin:public Identify
{
public:

	Admin();

	Admin(string id, string password);

	//�������������˵�
	void OperMenu();

    //����˺�
	void AddPerson();

	//��ѯ����Ա��Ϣ
	void ShowAdminInfo();

	//��ѯ������Ա��Ϣ
	void ShowPersonInfo();

	//��ѯ������Ա��Ϣ
	void ShowStaffInfo();

	//չʾ��ѯ��Ϣ1�ķֽ���
	void Oper1Menu();

	//չʾɾ����Ϣ3�ķ�ҳ��
	void Oper4Menu();

	//ɾ����Ա��Ϣ
	void DeletePerson(int type);
};