#pragma once
#include<iostream>
using namespace std;
#include <string>

class Identify
{
public:
	//ÿ����ĳ������������˵�
	virtual void OperMenu() = 0;

	string m_Id;//�û���

	string m_Password;//����
};