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

	Progress(int pnum, string num, int money, string date, string state, string dealer);//�вι���

	int m_Pnum;//�ᵥ���

	string m_Num;//����

	int m_Pmoney;//�ᵥ���

	string m_Date;//�ᵥ����

	string m_State;//״̬

	string m_Dealer;//������

	vector<Progress>vPro;//��Ϣ����

	void InitVector();//��ʼ����Ϣ

	void ShowPro();//չʾ���еı�������

	string GetDate();//��ȡ��ǰ������,�Լ�����

	int GetVproSize();//��ȡ�����Ĵ�С

	int GetVpronum();//��ȡ�����Ϣ

	void SaveVProgress(vector<Progress>p);//�洢������Ϣ

	void ShowConInfo();//����������ѯ����

	//��Ϊ����ֻ��1������0�������Բ���Ҫ�ж�
	//bool IsExist(int Pnum );//���ݵ����Ƿ����

	bool IsExist(string num);//���ݹ����жϴ��ھ�true
};