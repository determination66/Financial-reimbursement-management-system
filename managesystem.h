#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"allfiles.h"//�����ļ�
#include"identify.h"//�����ͷ�ļ�
#include"person.h"//������Ա
#include"staff.h"//������Ա
#include"admin.h"//����Ա
#include<fstream>//�����ļ�



class ManageSystem
{
public:
	ManageSystem();

	//��ʾ���˵�
	void ShowMainMenu();

	//��¼����
	void Login(int type);

	//��ҳ�������û�ѡ���Ƿ����˺�
	void MSOperMenu(int num);
	
	//����һ���˺�
	void Create(int num);

};